#include <stdio.h>
#include <stdlib.h>
#include "binsearchtree.h"

void displayBinSearchTreeInternal(BinSearchTreeNode *pTreeNode, int level, char type)
{
    int i = 0;
	for (i = 0; i < level ; i++) {
		printf("    ");
	}

	if (pTreeNode != NULL) {
		printf("-[%i,%c]%i-%c\n", level, type, 
			pTreeNode->key, pTreeNode->value);

		displayBinSearchTreeInternal(pTreeNode->pLeftChild, level + 1, 'L');
		displayBinSearchTreeInternal(pTreeNode->pRightChild, level + 1, 'R');
	}
	else {
		printf("NULL\n");
	}
}

int main(int argc, char *argv[])
{
	BinSearchTree *pTree = NULL;
	BinSearchTreeNode *pSearchNode = NULL;
	int key = 0;

	BinSearchTreeNode e1 = {30, 'A'};
	BinSearchTreeNode e2 = {20, 'B'};
	BinSearchTreeNode e3 = {40, 'C'};
	BinSearchTreeNode e4 = {10, 'D'};
	BinSearchTreeNode e5 = {24, 'E'};
	BinSearchTreeNode e6 = {34, 'F'};
	BinSearchTreeNode e7 = {46, 'G'};
	BinSearchTreeNode e8 = {6, 'H'};
	BinSearchTreeNode e9 = {14, 'I'};
	BinSearchTreeNode e10 = {22, 'I'};

	pTree = createBinSearchTree();
	if (pTree != NULL) 
	{
		insertElementBST(pTree, e1);
		insertElementBST(pTree, e2);
		insertElementBST(pTree, e3);
		insertElementBST(pTree, e4);
		insertElementBST(pTree, e5);
		insertElementBST(pTree, e6);
		insertElementBST(pTree, e7);
		insertElementBST(pTree, e8);
		insertElementBST(pTree, e9);
		insertElementBST(pTree, e10);
		displayBinSearchTreeInternal(pTree->pRootNode, 0, 'R');


		key = 14;
		pSearchNode = searchBST(pTree, key);
		if (pSearchNode != NULL) {
			printf("검색: 키-[%d], 결과-[%c]\n", key, pSearchNode->value);
		}
		else {
			printf("검색: 키-[%d],발견하지 못하였습니다\n", key);
		}

		key = 30;
		printf("자료 제거: 키-[%d]\n", key);
		deleteElementBST(pTree, key);
		displayBinSearchTreeInternal(pTree->pRootNode, 0, 'R');

		pSearchNode = searchRecursiveBST(pTree, key);
		if (pSearchNode != NULL) {
			printf("검색: 키-[%d], 결과-[%c]\n", key, pSearchNode->value);
		}
		else {
			printf("검색: 키-[%d],발견하지 못하였습니다\n", key);
		}


		deleteBinSearchTree(pTree);
	}

	return 0;
}
