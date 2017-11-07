#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

LinkedList* createLinkedList()
{
	LinkedList *pReturn = NULL;
	int i = 0;

	pReturn = (LinkedList *)malloc(sizeof(LinkedList));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedList));
	}
	else {
		printf("오류, 메모리할당 createLinkedList()\n");
		return NULL;
	}

	return pReturn;
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	int ret = FALSE;
	int i = 0;
	ListNode* pPreNode = NULL;
	ListNode* pNewNode = NULL;
	if (pList != NULL) {
		if (position >= 0
				&& position <= pList->currentElementCount) {
			pNewNode = (ListNode*)malloc(sizeof(ListNode));
			if (pNewNode != NULL) {
				*pNewNode = element;
				pNewNode->pLink = NULL;

				pPreNode = &(pList->headerNode);
				for(i = 0; i < position; i++) {
					pPreNode = pPreNode->pLink;
				}

				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode;

				pList->currentElementCount++;
				ret = TRUE;
			}
			else {
				printf("오류, 메모리할당 addLLElement()\n");
				return ret;
			}
		}
		else {
			printf("오류, 위치 인덱스-[%d], addLLElement()\n",
					position);
		}
	}

	return ret;
}

int removeLLElement(LinkedList* pList, int position)
{
	int ret = FALSE;
	int i = 0;
	int arrayCount = 0;
	ListNode* pNode = NULL;
	ListNode* pDelNode = NULL;
	if (pList != NULL) {
		arrayCount = getLinkedListLength(pList);
		if (position >=0 && position < arrayCount)
		{
			pNode = &(pList->headerNode);
			for(i = 0; i < position; i++) {
				pNode = pNode->pLink;
			}

			pDelNode = pNode->pLink;
			pNode->pLink = pDelNode->pLink;
			free(pDelNode);

			pList->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("오류, 위치 인덱스-[%d] removeLLElement()\n", position);
		}
	}

	return ret;
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode* pReturn = NULL;
	int i = 0;
	ListNode* pNode = NULL;
	if (pList != NULL) 	{
		if (position >=0 && position < pList->currentElementCount) {
			pNode = &(pList->headerNode);
			for(i = 0; i <= position; i++) {
				pNode = pNode->pLink;
			}
			pReturn = pNode;
		}
	}

	return pReturn;
}

void deleteLinkedList(LinkedList* pList)
{
	int i = 0;
	if (pList != NULL) {
		clearLinkedList(pList);
		free(pList);
	}
}

void clearLinkedList(LinkedList* pList)
{
	if (pList != NULL) {
		if (pList->currentElementCount > 0) {
			removeLLElement(pList, 0);
		}
	}
}

int getLinkedListLength(LinkedList* pList)
{
	int ret = 0;

	if (pList != NULL) {
		ret = pList->currentElementCount;
	}

	return ret;
}

int isEmpty(LinkedList* pList)
{
	int ret = FALSE;

	if (pList != NULL) {
		if (pList->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}
