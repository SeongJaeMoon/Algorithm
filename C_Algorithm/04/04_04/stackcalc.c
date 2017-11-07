#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprdef.h"
#include "exprlinkedstack.h"
#include "stackcalc.h"

int pushLSExprToken(LinkedStack* pStack, ExprToken data)
{
	StackNode node = {0,};
	node.data = data;
	return pushLS(pStack, node);
}

void calcExpr(ExprToken *pExprTokens, int tokenCount)
{
	LinkedStack *pStack = NULL;
	StackNode *pNode1 = NULL, *pNode2 = NULL;
	Precedence tokenType;
	int i = 0;
	if (pExprTokens == NULL) {
		return;
	}

	pStack = createLinkedStack();
	if (pStack != NULL) {
		for(i = 0; i < tokenCount; i++) {
			tokenType = pExprTokens[i].type;

			if (tokenType == operand) {
				pushLSExprToken(pStack, pExprTokens[i]);
			}
			else {
				pNode2 = popLS(pStack);
				if (pNode2 != NULL) {
					pNode1 = popLS(pStack);
					if (pNode1 != NULL) {
						float op1 = pNode1->data.value;
						float op2 = pNode2->data.value;

						ExprToken newToken;
						newToken.type = operand;
						switch(tokenType) {
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
			} //end-of-else
		}

		pNode1 = popLS(pStack);
		if (pNode1 != NULL) {
			printf("수식 계산 결과[%f]\n", 
					pNode1->data.value);
			free(pNode1);
		}
		else {
			printf("오류, 수식에 오류가 있습니다\n");
		}
		deleteLinkedStack(pStack);
	}
}

void convertInfixToPostfix(ExprToken *pExprTokens, int tokenCount)
{
	LinkedStack *pStack = NULL;
	StackNode *pNode = NULL;
	Precedence tokenType;
	Precedence inStackTokenType;
	int i = 0;

	if (pExprTokens == NULL) return;

	pStack = createLinkedStack();
	if (pStack != NULL) {
		for(i = 0; i < tokenCount; i++) {
			tokenType = pExprTokens[i].type;
			switch(tokenType) {
				case operand:
					printf("%f\n", pExprTokens[i].value);
					break;
				case rparen:
					pNode = popLS(pStack);
					while(pNode != NULL && pNode->data.type != lparen) {
						printToken(pNode->data);
						free(pNode);

						pNode = popLS(pStack);
					}
					if (pNode != NULL) free(pNode);
					break;
				default:
					while(isLinkedStackEmpty(pStack) == FALSE ) {
						inStackTokenType = peekLS(pStack)->data.type;
						if (outStackPrecedence(tokenType) 
								<= inStackPrecedence(inStackTokenType)) {
							pNode = popLS(pStack);
							if (pNode != NULL) {
								printToken(pNode->data);
								free(pNode);
							}
						}
						else {
							break;
						}
					}
					pushLSExprToken(pStack, pExprTokens[i]);
					break;
			}//end-of-switch
		}//end-of-for

		while(isLinkedStackEmpty(pStack) == FALSE) {
			pNode = popLS(pStack);
			if (pNode != NULL) {
				printToken(pNode->data);
				free(pNode);
			}
		}
		deleteLinkedStack(pStack);
	}
}

int inStackPrecedence(Precedence oper)
{
	switch(oper) {
		case lparen:
			return 0;
		case rparen:
			return 4;
		case times:
		case divide: 
			return 2;
		case plus:
		case minus:
			return 1;
	}
	return -1;
}

int outStackPrecedence(Precedence oper)
{
	switch(oper) {
		case lparen:
			return 5;
		case rparen:
			return 4;
		case times:
		case divide: 
			return 2;
		case plus:
		case minus:
			return 1;
	}
	return -1;
}

void printToken(ExprToken element)
{
	switch(element.type) {
		case lparen:
			printf("(\n");
			break;
		case rparen:
			printf(")\n");
			break;
		case plus:
			printf("+\n");
			break;
		case minus:
			printf("-\n");
			break;
		case times:
			printf("*\n");
			break;
		case divide:
			printf("/\n");
			break;
		case operand:
			printf("%f\n", element.value);
			break;
	}
}
