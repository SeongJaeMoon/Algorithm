#include <stdio.h>
#include <stdlib.h>
#include "doublylist.h"

int main(int argc, char *argv[])
{
	int i = 0;
	int arrayCount = 0;
	DoublyList *pList = NULL;
	DoublyListNode *pValue = NULL;
	DoublyListNode node = {0,};

	// 배열리스트 생성
	pList = createDoublyList(6);
	if (pList != NULL)
	{
		node.data = 1;
		addDLElement(pList, 0, node);
		node.data = 3;
		addDLElement(pList, 1, node);
		node.data = 5;
		addDLElement(pList, 2, node);
		displayDoublyList(pList);

		removeDLElement(pList, 0);
		displayDoublyList(pList);

		deleteDoublyList(pList);
	}

	return 0;
}
