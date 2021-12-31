#ifndef _EXPR_DEF_
#define _EXPR_DEF_
typedef enum precedenceType Precedence;
typedef struct ExprTokenType ExprToken;
enum precedenceType {
	lparen, rparen, times, divide, plus, minus, operand
};

struct ExprTokenType {
	float value;
	Precedence type;
};
#endif
//문자열을 후위 표기 수식으로 만드는 함수