#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

#include "bintreetraversalrec.h"

BinTree* createExampleBinTree();

int main(int argc, char *argv[])
{
	BinTree *pBinTree = NULL;
	pBinTree = createExampleBinTree();
	if (pBinTree != NULL) {
		printf("Preorder Recursive Traversal\n");
		preorderTraversalRecursiveBinTree(pBinTree);

		printf("\nInorder Recursive Traversal\n");
		inorderTraversalRecursiveBinTree(pBinTree);

		printf("\nPostorder Recursive Traversal\n");
		postorderTraversalRecursiveBinTree(pBinTree);
		printf("\n");
		deleteBinTree(pBinTree);
	}

	return 0;
}

BinTree* createExampleBinTree()
{
	BinTree* pReturn = NULL;
	BinTreeNode *pNodeA = NULL, *pNodeB = NULL, *pNodeC = NULL;
	BinTreeNode *pNodeD = NULL, *pNodeE = NULL, *pNodeF = NULL;
	BinTreeNode *pNodeG = NULL, *pNodeH = NULL, *pNodeI = NULL;
	BinTreeNode *pNodeJ = NULL, *pNodeK = NULL, *pNodeL = NULL;
	BinTreeNode *pNodeM = NULL;
	BinTreeNode node = {0,};
	
	node.data = 'A';
	pReturn = makeBinTree(node);
	if (pReturn != NULL) {
		pNodeA = getRootNodeBT(pReturn);
		node.data = 'B';
		pNodeB = insertLeftChildNodeBT(pNodeA, node);
		node.data = 'C';
		pNodeC = insertRightChildNodeBT(pNodeA, node);
		if (pNodeB != NULL) {
			node.data = 'D';
			pNodeD = insertLeftChildNodeBT(pNodeB, node);
			node.data = 'E';
			pNodeE = insertRightChildNodeBT(pNodeB, node);
		}
		if (pNodeC != NULL) {
			node.data = 'F';
			pNodeF = insertLeftChildNodeBT(pNodeC, node);
			node.data = 'G';
			pNodeG = insertRightChildNodeBT(pNodeC, node);
		}
		if (pNodeD != NULL) {
			node.data = 'H';
			pNodeH = insertLeftChildNodeBT(pNodeD, node);
			node.data = 'I';
			pNodeI = insertRightChildNodeBT(pNodeD, node);
		}
		if (pNodeE != NULL) {
			node.data = 'J';
			pNodeJ = insertLeftChildNodeBT(pNodeE, node);
		}
		if (pNodeF != NULL) {
			node.data = 'K';
			pNodeK = insertRightChildNodeBT(pNodeF, node);
		}
		if (pNodeG != NULL) {
			node.data = 'L';
			pNodeL = insertLeftChildNodeBT(pNodeG, node);
			node.data = 'M';
			pNodeM = insertRightChildNodeBT(pNodeG, node);
		}
	}

	return pReturn;
}
