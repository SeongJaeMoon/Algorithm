#ifndef _EXPR_DEF_
#define _EXPR_DEF_

typedef enum PrecedenceType { lparen, rparen, times, divide, plus, minus, 
								 operand } Precedence;

typedef struct ExprTokenType {
	float value;
	Precedence type;
} ExprToken;

#endif
