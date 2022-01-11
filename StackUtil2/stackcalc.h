#ifndef _STACK_CALC_
#define _STACK_CALC_
void calcExpr(ExprToken* pExprTokens, int tokenCount);
int pushLSExprToken(Stack* pStack, ExprToken data);
void convertInfixToPostfix(ExprToken* pExprToken, int tokenCount);
int inStackPrecedence(Precedence oper);
int outStackPrecedence(Precedence oper);
void printToken(ExprToken element);
#endif