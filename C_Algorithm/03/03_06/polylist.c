#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "polylist.h"

int addPolyNodeLast(LinkedList* pList, float coef, int degree)
{
	int ret = FALSE, i = 0;
	
	ListNode node = {0,};
	node.coef = coef;
	node.degree = degree;

	if (pList != NULL) {
		int length = getLinkedListLength(pList);
		ret = addLLElement(pList, length, node);		
	}

	return ret;
}

LinkedList* polyAdd(LinkedList* pListA, LinkedList* pListB)
{
	LinkedList* pReturn = NULL;
	ListNode *pNodeA = NULL, *pNodeB = NULL;
	float coefSum = 0;

	if (pListA != NULL && pListB != NULL) {
		pReturn = createLinkedList();
		if (pReturn == NULL) {
			printf("메모리 할당 오류, polyAdd()\n");
			return NULL;
		}

		pNodeA = pListA->headerNode.pLink;
		pNodeB = pListB->headerNode.pLink;
		while(pNodeA != NULL && pNodeB != NULL)
		{
			int degreeA = pNodeA->degree;
			int degreeB = pNodeB->degree;
			if (degreeA > degreeB) {		// (1) A의 차수 > B의 차수
				coefSum = pNodeA->coef;
				addPolyNodeLast(pReturn, coefSum, degreeA);
				pNodeA = pNodeA->pLink;
			}								
			else if (degreeA == degreeB) {	// (2) A의 차수(degree) == B의 차수
													
				coefSum = pNodeA->coef + pNodeB->coef;
				addPolyNodeLast(pReturn, coefSum, degreeA);
				pNodeA = pNodeA->pLink;
				pNodeB = pNodeB->pLink;
			}
			else {							// (3) A의 차수 < B의 차수
				coefSum = pNodeB->coef;
				addPolyNodeLast(pReturn, coefSum, degreeB);
				pNodeB = pNodeB->pLink;
			}
		}

		while(pNodeA != NULL) {
			coefSum = pNodeA->coef;
			addPolyNodeLast(pReturn, coefSum, pNodeA->degree);
			pNodeA = pNodeA->pLink;
		}

		while(pNodeB != NULL) {
			coefSum = pNodeB->coef;
			addPolyNodeLast(pReturn, coefSum, pNodeB->degree);
			pNodeB = pNodeB->pLink;
		}
	}
	else
	{
		printf("오류, NULL 다항식이 전달되었습니다, polyAdd()\n");
	}

	return pReturn;
}

void displayPolyList(LinkedList* pList)
{
	int i = 0;
	if (pList != NULL) 	{
		for(i = 0; i < pList->currentElementCount; i++) {
			ListNode *pNode = getLLElement(pList, i);
			if (pNode != NULL) {
				printf("%4.1fx^%d", pNode->coef, pNode->degree);

				if (i == pList->currentElementCount - 1) {
					printf("\n");
				}
				else {
					printf(" + ");
				}
			}
		}
	}
	else
	{
		printf("빈 다항식 입니다\n");
	}
}
