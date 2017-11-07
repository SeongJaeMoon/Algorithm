#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

ArrayList* createArrayList(int maxElementCount) {
	ArrayList *pReturn = NULL;
	int i = 0;

	if (maxElementCount > 0) {
		pReturn = (ArrayList *)malloc(sizeof(ArrayList));

		if (pReturn != NULL) {
			pReturn->maxElementCount = maxElementCount;
			pReturn->currentElementCount = 0;
			pReturn->pElement = NULL;
		}
		else {
			printf("오류, 메모리할당 createArrayList()\n");
			return NULL;
		}
	}
	else {
		printf("오류, 최대 원소 개수는 0이상이어야 합니다\n");
		return NULL;
	}

	pReturn->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
	if (pReturn->pElement == NULL) {
		printf("오류, 2번째 메모리할당 createArrayList()\n");
		free(pReturn); return NULL;
	}
	memset(pReturn->pElement, 0, sizeof(ArrayListNode) * maxElementCount);

	return pReturn;
}

int addALElement(ArrayList* pList, int position, ArrayListNode element) {
	int ret = FALSE;
	int i=0;

	if (pList != NULL) {
		if (isArrayListFull(pList) != TRUE) {
			if (position >= 0
				&& position <= pList->currentElementCount)
			{
				for(i = pList->currentElementCount-1; i >= position; i--) {
					pList->pElement[i+1] = pList->pElement[i];
				}
				pList->pElement[position] = element;
				pList->currentElementCount++;
				
				ret = TRUE;
			}
			else {
				printf("오류, 위치 인덱스-[%d] 범위 초과, addALElement()\n",
						position);
			}
		}
		else {
			printf("오류, 리스트 용량 초과-[%d]/[%d]\n", 
					position, pList->maxElementCount);
		}
	}

	return ret;
}

int removeALElement(ArrayList* pList, int position) {
	int ret = FALSE;
	int i=0;

	if (pList != NULL) {
		if (position >= 0 
				&& position < pList->currentElementCount) {
			for(i = position; i < pList->currentElementCount-1; i++) {
				pList->pElement[i] = pList->pElement[i+1];
			}
			pList->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("오류, 위치 인덱스-[%d] 범위 초과, removeALElement()\n",
					position);
		}
	}

	return ret;
}

ArrayListNode* getALElement(ArrayList* pList, int position) {
	ArrayListNode* pReturn = NULL;
	if (pList != NULL) {
		if (position >=0 && position < getArrayListLength(pList)) {
			pReturn = &(pList->pElement[position]);
		}
		else {
			printf("오류, 위치 인덱스-[%d] 범위 초과, getALElement()\n", position);
		}
	}

	return pReturn;
}

void displayArrayList(ArrayList* pList) {
	int i = 0;
	if (pList != NULL) {
		printf("최대 원소 개수: %d\n", pList->maxElementCount);
		printf("현재 원소 개수: %d\n", pList->currentElementCount);

		for(i = 0; i < pList->currentElementCount; i++) {
			printf("[%d],%d\n", i, getALElement(pList, i)->data);
		}
		
		i = pList->currentElementCount;
		for(; i < pList->maxElementCount; i++) {
			printf("[%d],Empty\n", i);
		}
	}
	else {
		printf("ArryList is NULL");
	}
}

int isArrayListFull(ArrayList* pList) {
	int ret = FALSE;

	if (pList != NULL) {
		if (pList->currentElementCount == pList->maxElementCount) {
			ret = TRUE;
		}
	}

	return ret;
}

int getArrayListLength(ArrayList* pList) {
	int ret = 0;

	if (pList != NULL) {
		ret = pList->currentElementCount;
	}

	return ret;
}

void deleteArrayList(ArrayList* pList)
{
	int i = 0;
	if (pList != NULL) {
		free(pList->pElement);
		free(pList);
	}
}
