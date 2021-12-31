#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"exprdef.h"
#include"exprlinkedstack.h"
#include"stackcalc.h"

int main(int argc, char* argv[]) {
	int i = 0;
	ExprToken* pExprTokens = (ExprToken*)malloc(sizeof(ExprToken) * 7);
	pExprTokens[0].type = operand;
	pExprTokens[0].value = 2;
	pExprTokens[1].type = operand;
	pExprTokens[1].value = 3;
	pExprTokens[2].type = operand;
	pExprTokens[2].value = 4;
	pExprTokens[3].type = plus;
	pExprTokens[3].value = 0;
	pExprTokens[4].type = operand;
	pExprTokens[4].value = 5;
	pExprTokens[5].type = times;
	pExprTokens[5].value = 0;
	pExprTokens[6].type = minus;
	pExprTokens[6].value = 0;

	printf("Expression : 2 3 4 + 5 * - \n");
	calcExpr(pExprTokens, 7);
	free(pExprTokens);


	ExprToken* pExprTokens2 = NULL;
	ExprToken* pTokenResult = NULL;
	int RetTokenCount = 0;
	char* str = "(1+22) * 3 + (1+4)";//--> 1 22 + 3 * 1 4 + +
	pExprTokens2 = convertExpr(str);
	for (int i = 0; i<strlen(str); i++) {
		printToken(pExprTokens2[i]);
	}
	pTokenResult = convertInfixToPostfix2(pExprTokens2, strlen(str), &RetTokenCount);
	for (int i = 0; i < RetTokenCount; i++) {
		printToken(pTokenResult[i]);
	}
	printf("%d", RetTokenCount);
	
}