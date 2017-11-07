#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublylist.h"
DoublyList* createDoublyList()
{
	DoublyList *pReturn = NULL;
	int i = 0;

	pReturn = (DoublyList *)malloc(sizeof(DoublyList));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(DoublyList));

		pReturn->headerNode.pLLink = &(pReturn->headerNode);
		pReturn->headerNode.pRLink = &(pReturn->headerNode);
	}
	else {
		printf("오류, 메모리할당 createDoublyList()\n");
		return NULL;
	}

	return pReturn;
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	int ret = FALSE, i = 0;
	DoublyListNode *pPreNode = NULL, *pNewNode = NULL, *pTempNode = NULL;
	if (pList != NULL) 	{
		if (position >= 0 && position <= pList->currentElementCount) {
			pNewNode = (DoublyListNode*)malloc(sizeof(DoublyListNode));
			if (pNewNode == NULL) {
				printf("오류, 메모리할당 addCLElement()\n");
				return ret;
			}
			*pNewNode = element;
			pNewNode->pLLink = NULL;
			pNewNode->pRLink = NULL;

			pPreNode = &(pList->headerNode);
			for(i = 0; i < position; i++) {
				pPreNode = pPreNode->pRLink;
			}

			pNewNode->pLLink = pPreNode;
			pNewNode->pRLink = pPreNode->pRLink;
			pPreNode->pRLink = pNewNode;
			pNewNode->pRLink->pLLink = pNewNode;

			pList->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("오류, 위치 인덱스-[%d] addDLElement()\n", position);
		}
	}

	return ret;
}

int removeDLElement(DoublyList* pList, int position)
{
	int ret = FALSE;
	int i = 0, arrayCount = 0;
	DoublyListNode *pPreNode = NULL, *pDelNode = NULL, *pTempNode = NULL;
	
	if (pList != NULL) 	{
		arrayCount = getDoublyListLength(pList);
		if (position >=0 && position < arrayCount) 	{
			pPreNode = &(pList->headerNode);
			for(i = 0; i < position; i++) {
				pPreNode = pPreNode->pRLink;
			}
			pDelNode = pPreNode->pRLink;

			pPreNode->pRLink = pDelNode->pRLink;
			pDelNode->pRLink->pLLink = pPreNode;
			free(pDelNode);

			pList->currentElementCount--;
			ret = TRUE;
		}
		else
		{
			printf("오류, 위치 인덱스-[%d] removeDLElement()\n", position);
		}
	}

	return ret;
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode* pReturn = NULL;
	int i = 0;
	DoublyListNode* pNode = NULL;
	if (pList != NULL) {
		if (position >=0 && position < pList->currentElementCount) 	{
			pNode = pList->headerNode.pRLink;
			for(i = 0; i < position; i++) {
				pNode = pNode->pRLink;
			}
			pReturn = pNode;
		}
		else {
			printf("오류, 위치 인덱스-[%d] getDLElement()\n", position);
		}
	}

	return pReturn;
}

void displayDoublyList(DoublyList* pList)
{
	int i = 0;
	if (pList != NULL) {
		printf("현재 노드 개수: %d\n", pList->currentElementCount);

		for(i = 0; i < pList->currentElementCount; i++) {
			printf("[%d],%d\n", i, getDLElement(pList, i)->data);
		}
	}
	else {
		printf("원소가 없습니다.\n");
	}
}

void deleteDoublyList(DoublyList* pList)
{
	if (pList != NULL) {
		clearDoublyList(pList);
		free(pList);
	}
}

void clearDoublyList(DoublyList* pList)
{
	if (pList != NULL) {
		while (pList->currentElementCount > 0) {
			removeDLElement(pList, 0);
		}
	}
}

int getDoublyListLength(DoublyList* pList)
{
	int ret = 0;
	if (pList != NULL) {
		ret = pList->currentElementCount;
	}
	return ret;
}
