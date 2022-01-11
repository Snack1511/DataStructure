#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"exprdef.h"
#include"exprlinkedstack.h"
#include"stackcalc.h"

int pushLSExprToken(Stack* pStack, ExprToken data) {
	StackNode node = { 0, };
	node.data = data;
	return Push(pStack, node);

}
void calcExpr(ExprToken* pExprTokens, int tokenCount) {
	Stack* pStack = NULL;
	StackNode* pNode1 = NULL, * pNode2 = NULL;
	Precedence tokenType;
	int i = 0;
	if (pExprTokens == NULL) {
		return;
	}

	pStack = createLNKStack();
	if (pStack != NULL) {
		for (i = 0; i < tokenCount; i++) {
			tokenType = pExprTokens[i].type;
			if (tokenType == operand) {
				pushLSExprToken(pStack, pExprTokens[i]);
			}
			else {
				pNode2 = Pop(pStack);
				if (pNode2 != NULL) {
					pNode1 = Pop(pStack);
					if (pNode1 != NULL) {
						float op1 = pNode1->data.value;
						float op2 = pNode2->data.value;

						ExprToken newToken;
						newToken.type = operand;

						switch (tokenType) {
						case plus:
							newToken.value = op1 + op2;
							break;
						case minus:
							newToken.value = op1 - op2;
							break;
						case times:
							newToken.value = op1 * op2;
							break;
						case divide:
							newToken.value = op1 / op2;
							break;

						}
						pushLSExprToken(pStack, newToken);


						free(pNode1);
					}
					free(pNode2);
				}

			}
		}

		pNode1 = Pop(pStack);
		if (pNode1 != NULL) {
			printf("���� ��� ��� [%f]\n", pNode1->data.value);
			free(pNode1);
		}

		deleteLNKStack(pStack);
	}
}
void convertInfixToPostfix(ExprToken* pExprToken, int tokenCount) {
	Stack* pStack = NULL;
	StackNode *pNode = NULL;
	Precedence tokentype;
	Precedence inStackTokenType;
	int i = 0;

	if (pExprToken == NULL) {
		return;
	}
	pStack =createLNKStack();
	if (pStack != NULL) {
		for (int i = 0; i < tokenCount; i++) {
			tokentype = pExprToken[i].type;
			switch (tokentype) {
			case operand:
				printf("%f\n", pExprToken[i].value);
				break;
			case rparen:
				pNode = Pop(pStack);
				while (pNode != NULL && pNode->data.type != lparen) {
					printToken(pNode->data);
					free(pNode);
					pNode = Pop(pStack);
				}
				if (pNode != NULL) free(pNode);
				break;

			default:
				while (IsStackEmpty(pStack) == FALSE) {
					inStackTokenType = Peek(pStack).data.type;
					if (outStackPrecedence(tokentype) <= inStackPrecedence(inStackTokenType)) {
						pNode = Pop(pStack);
						if (pNode != NULL) {
							printToken(pNode->data);
							free(pNode);
						}
					}
					else {
						break;
					}
				}
				pushLSExprToken(pStack, pExprToken[i]);
				break;
			}

		}
		while (IsStackEmpty(pStack) == FALSE) {
			pNode = Pop(pStack);
			if (pNode != NULL) {
				printToken(pNode->data);
				free(pNode);
			}
		}
		deleteLNKStack(pStack);
	}

}
int inStackPrecedence(Precedence oper) {
	switch (oper) {
	case lparen:
		return 0;
		break;
	case rparen:
		return 4;
		break;
	case times:
	case divide:
		return 2;
		break;
	case plus:
	case minus:
		return 1;
		break;

	}
	return -1;
}
int outStackPrecedence(Precedence oper) {
	switch (oper) {
	case lparen:
		return 5;
		break;
	case rparen:
		return 4;
		break;
	case times:
	case divide:
		return 2;
		break;
	case plus:
	case minus:
		return 1;
		break;

	}
	return -1;
}
void printToken(ExprToken element) {
	switch (element.type) {
	case lparen:
		printf("(\n");
		break;
	case rparen:
		printf(")\n");
		break;
	case times:
		printf("*\n");
		break;
	case divide:
		printf("/\n");
		break;
	case plus:
		printf("+\n");
		break;
	case minus:
		printf("-\n");
		break;
	case operand:
		printf("%f\n", element.value);
		break;

	}
	return -1;
}