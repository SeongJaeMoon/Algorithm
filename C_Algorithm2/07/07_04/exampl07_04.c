#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "bintreeop.h"

BinTree* createExampleBinTree();

int main(int argc, char *argv[])
{
	int compareResult = FALSE;
	int count = 0;
	BinTree *pBinTree = NULL, *pCopyBinTree = NULL;

	pBinTree = createExampleBinTree();
	printf("이진 트리 원본:\n");
	displayBinTree(pBinTree);

	pCopyBinTree = copyBinTree(pBinTree);
	printf("이진 트리 복사본:\n");
	displayBinTree(pCopyBinTree);

	compareResult = equalBinTree(pBinTree, pCopyBinTree);
	printf("\n이진 트리 비교 결과: (%d)\n", compareResult);

	count = getNodeCountBT(pBinTree);
	printf("\n이진 트리 노드 개수: %d\n", count);

	count = getLeafNodeCountBT(pBinTree);
	printf("\n이진 트리 단말 노드 개수: %d\n", count);

	count = getHeightBT(pBinTree);
	printf("\n이진 트리의 높이: %d\n", count);

	deleteBinTree(pBinTree);
	deleteBinTree(pCopyBinTree);
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
