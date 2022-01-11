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
			printf("수식 계산 결과 [%f]\n", pNode1->data.value);
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
//------------ 기존 후위표기 구현

ExprToken* convertExpr(char* str) {
	int size = strlen(str);
	int stackSize = 0;
	Stack* pStack = createLNKStack();
	ExprToken token = { 0, };
	int numcnt = 0;
	if (str != NULL) {
		for (int i = 0; i < size; i++) {
			switch (str[i]) {
			case '(':
			case '{':
			case '[':
				token.value = 0;
				token.type = lparen;
				break;
			case ')':
			case '}':
			case ']':
				token.value = 0;
				token.type = rparen;
				break;
			case '+':
				token.value = 0;
				token.type = plus;
				break;
			case '-':
				token.value = 0;
				token.type = minus;
				break;
			case '*':
				token.value = 0;
				token.type = times;
				break;
			case '/':
				token.value = 0;
				token.type = divide;
				break;
			case '\t':
			case ' ':
				token.value = 0;
				token.type = -1;
				break;
			default :
				numcnt = 0;
				while (str[i + numcnt] == '0' 
					|| str[i + numcnt] == '1' 
					|| str[i + numcnt] == '2'
					|| str[i + numcnt] == '3'
					|| str[i + numcnt] == '4'
					|| str[i + numcnt] == '5'
					|| str[i + numcnt] == '6'
					|| str[i + numcnt] == '7'
					|| str[i + numcnt] == '8'
					|| str[i + numcnt] == '9'
					) {
					numcnt++;
				}
				char* numstr = (char*)malloc(sizeof(char) * (numcnt+1));
				if (numstr != NULL) {
					for (int j = 0; j < numcnt; j++) {
						numstr[j] = str[i + j];
					}
					numstr[numcnt] = '\0';
					token.value = atoi(numstr);
					token.type = operand;
					
				}
				i += numcnt-1;
				break;
			}
			if (token.type != -1) {
				pushLSExprToken(pStack, token);
				stackSize++;
			}
		}
	}
	ExprToken* pTokens = (ExprToken*)malloc(sizeof(ExprToken)* stackSize);
	for(int i = 0; i < stackSize; i++) {
		*(pTokens + i) = Pop(pStack)->data;
	}
	return pTokens;
}
ExprToken* convertInfixToPostfix2(ExprToken* pExprToken, int tokenCount, int* pRetTokenCount) {
	Stack* pStack = NULL;
	Stack* pReverseExpr = NULL;
	StackNode* pNode = NULL;
	Precedence tokentype;
	Precedence inStackTokenType;
	int i = 0;

	if (pExprToken == NULL) {
		return;
	}
	pStack = createLNKStack();
	pReverseExpr = createLNKStack();
	if (pStack != NULL) {
		for (int i = 0; i < tokenCount; i++) {
			tokentype = pExprToken[i].type;
			switch (tokentype) {
			case operand:
				printf("%f\n", pExprToken[i].value);
				pushLSExprToken(pReverseExpr, pExprToken[i]);
				*(pRetTokenCount) += 1;
				printf("pReturns Top : %f\n", Peek(pReverseExpr).data.value);
				break;
			case rparen:
				pNode = Pop(pStack);
				while (pNode != NULL && pNode->data.type != lparen) {
					pushLSExprToken(pReverseExpr, pNode->data);
					*(pRetTokenCount) += 1;

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
							pushLSExprToken(pReverseExpr, pNode->data);
							*(pRetTokenCount) += 1;
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
				pushLSExprToken(pReverseExpr, pNode->data);
				*(pRetTokenCount) += 1;
				printToken(pNode->data);
				free(pNode);
			}
		}
		deleteLNKStack(pStack);
		ExprToken* pReturn = (ExprToken*)malloc(sizeof(ExprToken) * (*pRetTokenCount));
		printf("-----------------------------------\n");
		for (int i = *(pRetTokenCount) - 1; i >= 0; i--) {
			printToken(Peek(pReverseExpr).data);
			*(pReturn + i) = Pop(pReverseExpr)->data;

		}
		printf("-----------------------------------\n");
		return pReturn;
	}

}
//------------ 예제 구현