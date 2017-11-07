#include <stdio.h>
#include <stdlib.h>
#include "btreedef.h"
#include "btree.h"

int main(int argc, char *argv[])
{
	BTree *pTree = NULL;
	BTreeNodeData *pSearchElement = NULL;
	int key = 0;

	BTreeNodeData eA = {9, 'A'};
	BTreeNodeData eB = {12, 'B'};
	BTreeNodeData eC = {19, 'C'};
	BTreeNodeData eD = {39, 'D'};
	BTreeNodeData eE = {65, 'E'};
	BTreeNodeData eF = {53, 'F'};
	BTreeNodeData eG = {63, 'G'};
	BTreeNodeData eH = {89, 'H'};
	BTreeNodeData eI = {48, 'I'};
	BTreeNodeData eJ = {36, 'J'};

	pTree = createBTree();
	if (pTree != NULL) 
	{
		insertNodeBT(pTree, eA);
		insertNodeBT(pTree, eB);
		insertNodeBT(pTree, eC);
		insertNodeBT(pTree, eD);
		printf("\n01-자료 추가중\n");
		displayBTree(pTree);

		insertNodeBT(pTree, eE);
		printf("\n02-자료 추가중\n");
		displayBTree(pTree);

		insertNodeBT(pTree, eF);
		insertNodeBT(pTree, eG);
		insertNodeBT(pTree, eH);
		printf("\n03-자료 추가중\n");
		displayBTree(pTree);

		insertNodeBT(pTree, eI);
		insertNodeBT(pTree, eJ);

		printf("\n자료 추가가 끝났습니다\n");
		displayBTree(pTree);

		deleteNodeBT(pTree, 9);
		printf("\n검색 키 9이 삭제되었습니다\n");
		displayBTree(pTree);

		deleteNodeBT(pTree, 89);
		printf("\n검색 키 89이 삭제되었습니다\n");
		displayBTree(pTree);

		deleteNodeBT(pTree, 39);
		printf("\n검색 키 39가 삭제되었습니다\n");
		displayBTree(pTree);

		deleteNodeBT(pTree, 63);
		deleteNodeBT(pTree, 53);
		printf("\n검색 키 63, 53이 삭제되었습니다\n");
		displayBTree(pTree);

		deleteNodeBT(pTree, 36);
		printf("\n검색 키 36가 삭제되었습니다\n");
		displayBTree(pTree);

		key = 19;
		pSearchElement = searchBT(pTree, key);
		if (pSearchElement != NULL) {
			printf("검색 키-[%d], 결과-[%c]\n", key, pSearchElement->value);
		}
		else {
			printf("검색 키-[%d], 결과 실패\n", key);
		}

		deleteBTree(pTree);
	}
	return 0;
}
