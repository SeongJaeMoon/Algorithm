#include <stdio.h>
#include <stdlib.h>
#include "avldef.h"
#include "avllinkedstack.h"
#include "avltree.h"

int main(int argc, char *argv[])
{
	AVLTree *pTree = NULL;
	AVLTreeNode *pSearch = NULL;
	int key = 0;

	AVLTreeNodeData eB = {9, "키 값이 9"};
	AVLTreeNodeData eG = {3, "키 값이 3"};
	AVLTreeNodeData eE = {1, "키 값이 1"};
	AVLTreeNodeData eC = {10, "키 값이 10"};
	AVLTreeNodeData eL = {12, "키 값이 12"};
	AVLTreeNodeData eH = {6, "키 값이 6"};
	AVLTreeNodeData eI = {4, "키 값이 4"};
	AVLTreeNodeData eF = {5, "키 값이 5"};

	pTree = createAVLTree();
	if (pTree != NULL) 
	{
		printf("1)\n");
		insertNodeAVL(pTree, eB);
		displayAVLTree(pTree);

		printf("\n2)\n");
		insertNodeAVL(pTree, eG);
		displayAVLTree(pTree);
		
		printf("\n3) LL 회전 발생\n");
		insertNodeAVL(pTree, eE);
		displayAVLTree(pTree);
		
		printf("\n4)\n");
		insertNodeAVL(pTree, eC);
		displayAVLTree(pTree);
		
		printf("\n5) RR 회전 발생\n");
		insertNodeAVL(pTree, eL);
		displayAVLTree(pTree);
		
		printf("\n6) RL 회전 발생\n");
		insertNodeAVL(pTree, eH);
		displayAVLTree(pTree);
		
		printf("\n7)\n");
		insertNodeAVL(pTree, eI);
		displayAVLTree(pTree);
		
		printf("\n8) LR 회전 발생\n");
		insertNodeAVL(pTree, eF);
		displayAVLTree(pTree);

		deleteAVLTree(pTree);
	}

	return 0;
}
