#include <stdio.h>
#include <stdlib.h>
#include "linkeddeque.h"

int insertFrontLDChar(LinkedDeque* pDeque, char data)
{
	DequeNode node = {0,};
	node.data = data;
	return insertFrontLD(pDeque, node);
}

int insertRearLDChar(LinkedDeque* pDeque, char data)
{
	DequeNode node = {0,};
	node.data = data;
	return insertRearLD(pDeque, node);
}

void displayLinkedDeque(LinkedDeque *pDeque)
{
	DequeNode *pNode = NULL;
	int i = 0;

	if (pDeque != NULL) {
		printf("현재 노드 개수: %d\n",
				pDeque->currentElementCount);
		pNode = pDeque->pFrontNode;
		while(pNode != NULL) {
			printf("[%d]-[%c]\n", i, pNode->data);
			i++;
			pNode = pNode->pRLink;
		}
	}
}

int main(int argc, char *argv[])
{
	LinkedDeque *pDeque = NULL;
	DequeNode *pNode = NULL;

	pDeque = createLinkedDeque();
	if (pDeque != NULL) {
		insertFrontLDChar(pDeque, 'A');
		insertFrontLDChar(pDeque, 'B');
		insertRearLDChar(pDeque, 'C');
		insertRearLDChar(pDeque, 'D');
		displayLinkedDeque(pDeque);

		pNode = deleteRearLD(pDeque);
		if (pNode != NULL) {
			printf("deleteRearLD Value-[%c]\n", pNode->data);
			free( pNode );
		}
		displayLinkedDeque(pDeque);

		pNode = deleteFrontLD(pDeque);
		if (pNode != NULL) {
			printf("deleteFrontLD Value-[%c]\n", pNode->data);
			free( pNode );
		}
		displayLinkedDeque(pDeque);

		deleteLinkedDeque(pDeque);
	}
	return 0;
}
