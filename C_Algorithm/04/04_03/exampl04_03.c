#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"
#include "stackutil.h"

int main(int argc, char *argv[])
{
	char sourceStr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char successExprStr[] = "((A * B) / C) - {(D + E) && (F - G)}";
	char failExprStr[] = "((A * B) / C - {(D + E) && (F - G))}";
	int checkResult = 0;	
	
	char *pReverseStr = reverseString(sourceStr);
	if (pReverseStr != NULL) {
		printf("[%s] => [%s]\n", sourceStr, pReverseStr);
		free(pReverseStr);
	}

	checkResult = checkBracketMatching(successExprStr);
	if (checkResult == TRUE) 	{
		printf("SUCCESS, %s\n", successExprStr);
	}
	else 	{
		printf("FAIL, %s\n", successExprStr);
	}

	checkResult = checkBracketMatching(failExprStr);
	if (checkResult == TRUE) 	{
		printf("SUCCESS, %s\n", failExprStr);
	}
	else 	{
		printf("FAIL, %s\n", failExprStr);
	}

	return 0;
}
