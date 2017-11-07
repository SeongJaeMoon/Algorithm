#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

int main(int argc, char *argv[])
{
	BinTree *pBinTree = NULL;
	BinTreeNode *pNodeA = NULL, *pNodeB = NULL, *pNodeC = NULL;
	BinTreeNode *pNodeD = NULL, *pNodeE = NULL, *pNodeF = NULL;
	BinTreeNode node = {0,};
	
	node.data = 'A';
	pBinTree = makeBinTree(node);
	if (pBinTree != NULL) {
		pNodeA = getRootNodeBT(pBinTree);

		node.data = 'B';
		pNodeB = insertLeftChildNodeBT(pNodeA, node);

		node.data = 'C';
		pNodeC = insertRightChildNodeBT(pNodeA, node);

		if (pNodeB != NULL) {
			node.data = 'D';
			pNodeD = insertLeftChildNodeBT(pNodeB, node);
		}
		if (pNodeC != NULL) {
			node.data = 'E';
			pNodeE = insertLeftChildNodeBT(pNodeC, node);

			node.data = 'F';
			pNodeF = insertRightChildNodeBT(pNodeC, node);
		}
		deleteBinTree(pBinTree);
	}

	return 0;
}
