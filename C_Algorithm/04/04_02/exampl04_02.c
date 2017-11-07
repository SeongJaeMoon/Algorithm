#include <stdio.h>
#include <stdlib.h>
#include "linkedstack.h"

void displayLinkedStack(LinkedStack *pStack)
{
	StackNode *pNode = NULL;
	int i = 1;
	if (pStack != NULL) {
		printf("현재 노드 개수: %d\n",
				pStack->currentElementCount);
		pNode = pStack->pTopElement;
		while(pNode != NULL) {
			printf("[%d]-[%c]\n", 
				pStack->currentElementCount - i,
				pNode->data);
			i++;
			pNode = pNode->pLink;
		}
	}
}

int main(int argc, char *argv[])
{
	LinkedStack *pStack = NULL;
	StackNode *pNode = NULL;

	pStack = createLinkedStack();
	if (pStack != NULL) {
		StackNode node1 = {'A'};
		StackNode node2 = {'B'};
		StackNode node3 = {'C'};
		StackNode node4 = {'D'};

		pushLS(pStack, node1);
		pushLS(pStack, node2);
		pushLS(pStack, node3);
		pushLS(pStack, node4);
		displayLinkedStack(pStack);

		pNode = popLS(pStack);
		if (pNode != NULL)
		{
			printf("Pop-[%c]\n", pNode->data);
			free(pNode);
		}
		else {
			printf("Pop-NULL\n");
		}
		displayLinkedStack(pStack);

		pNode = peekLS(pStack);
		if (pNode != NULL) {
			printf("Peek-[%c]\n", pNode->data);
		}
		else {
			printf("Peek-NULL\n");
		}
		displayLinkedStack(pStack);

		deleteLinkedStack(pStack);
	}
	return 0;
}
