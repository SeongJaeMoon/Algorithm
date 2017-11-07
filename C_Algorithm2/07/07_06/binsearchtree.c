#include <stdio.h>
#include <stdlib.h>
#include "binsearchtree.h"

BinSearchTree* createBinSearchTree()
{
	BinSearchTree *pReturn = NULL;
	pReturn = (BinSearchTree *)malloc(sizeof(BinSearchTree));
	if (pReturn != NULL) {
		pReturn->pRootNode = NULL;
	}
	else {
		printf("오류, 메모리 할당,createBinSearchTree()\n");
	}

	return pReturn;
}

int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode element)
{
	int ret = TRUE;
	BinSearchTreeNode* pParentNode = NULL;
	BinSearchTreeNode* pNewNode = NULL;

	if (pBinSearchTree == NULL) {
		ret = FALSE;
		return ret;
	}

	pParentNode = pBinSearchTree->pRootNode;
	while(pParentNode != NULL) {
		if (element.key == pParentNode->key) {
			printf("오류,중복된 키-[%d],insertElementBST()\n", element.key);
			ret = FALSE;
			return ret;
		}
		else if (element.key < pParentNode->key) {
			if (pParentNode->pLeftChild == NULL) {
				break;
			}
			else {
				pParentNode = pParentNode->pLeftChild;
			}
		}
		else {
			if (pParentNode->pRightChild == NULL) {
				break;
			}
			else {
				pParentNode = pParentNode->pRightChild;
			}
		}
	}

	pNewNode = (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode));
	if (pNewNode != NULL) {
		*pNewNode = element;
		pNewNode->pLeftChild = NULL;
		pNewNode->pRightChild = NULL;

		if (pParentNode == NULL) {
			pBinSearchTree->pRootNode = pNewNode;
		}
		else {
			if (pNewNode->key < pParentNode->key) {
				pParentNode->pLeftChild = pNewNode;
			}
			else {
				pParentNode->pRightChild = pNewNode;
			}
		}

		ret = TRUE;
	}
	else {
		printf("오류,메모리 할당,insertElementBST()\n");
		ret = FALSE;
	}

	return ret;
}


int deleteElementBST(BinSearchTree* pBinSearchTree, int key)
{
	int ret = TRUE;
	BinSearchTreeNode *pDelNode = NULL, *pParentNode = NULL;
	BinSearchTreeNode *pPredecessor = NULL, *pSuccessor = NULL;
	BinSearchTreeNode* pChildNode = NULL;

	if (pBinSearchTree == NULL) {
		ret = FALSE;
		return ret;
	}
	pParentNode = NULL;
	pDelNode = pBinSearchTree->pRootNode;
	while(pDelNode != NULL) {
		if (key == pDelNode->key) {
			break;
		}
		pParentNode = pDelNode;

		if (key < pDelNode->key) {
			pDelNode = pDelNode->pLeftChild;
		}
		else {
			pDelNode = pDelNode->pRightChild;
		}
	}
	if (pDelNode == NULL) {
		printf("오류,존재하지 않는 키-[%d],deleteElementBST()\n", key);
		ret = FALSE;
		return ret;
	}
	if (pDelNode->pLeftChild == NULL && pDelNode->pRightChild == NULL) {
		if (pParentNode != NULL) {
			if (pParentNode->pLeftChild == pDelNode) {
				pParentNode->pLeftChild = NULL;
			}
			else {
				pParentNode->pRightChild = NULL;
			}
		}
		else {
			pBinSearchTree->pRootNode = NULL;
		}
	}
	else if (pDelNode->pLeftChild != NULL && pDelNode->pRightChild != NULL) {
		pPredecessor = pDelNode;
		pSuccessor = pDelNode->pLeftChild;

		while(pSuccessor->pRightChild != NULL) {
			pPredecessor = pSuccessor;
			pSuccessor = pSuccessor->pRightChild;
		}

		pPredecessor->pRightChild = pSuccessor->pLeftChild;
		pSuccessor->pLeftChild = pDelNode->pLeftChild;
		pSuccessor->pRightChild = pDelNode->pRightChild;

		if (pParentNode != NULL) {
			if (pParentNode->pLeftChild == pDelNode) {
				pParentNode->pLeftChild = pSuccessor;
			}
			else {
				pParentNode->pRightChild = pSuccessor;
			}
		}
		else {
			pBinSearchTree->pRootNode = pSuccessor;
		}
	}
	else {
		if (pDelNode->pLeftChild != NULL) {
			pChildNode = pDelNode->pLeftChild;
		}
		else {
			pChildNode = pDelNode->pRightChild;
		}

		if (pParentNode != NULL) {
			if (pParentNode->pLeftChild == pDelNode) {
				pParentNode->pLeftChild = pChildNode;
			}
			else {
				pParentNode->pRightChild = pChildNode;
			}
		}
		else {
			pBinSearchTree->pRootNode = pChildNode;
		}
	}

	free( pDelNode );
	return ret;
}

BinSearchTreeNode* searchRecursiveBST(BinSearchTree* pBinSearchTree, int key)
{
	BinSearchTreeNode* pReturn = NULL;

	if (pBinSearchTree == NULL) {
		return NULL;
	}
	pReturn = searchInternalRecursiveBST(pBinSearchTree->pRootNode, key);

	return pReturn;
}

BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode* pTreeNode, int key)
{
	BinSearchTreeNode* pReturn = NULL;

	if (pTreeNode == NULL) {
		return NULL;
	}

	if (key == pTreeNode->key) {
		pReturn = pTreeNode;
	}
	else if (key < pTreeNode->key) {
		pReturn = searchInternalRecursiveBST(pTreeNode->pLeftChild, key);
	}
	else {
		pReturn = searchInternalRecursiveBST(pTreeNode->pRightChild, key);
	}

	return pReturn;
}

BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key)
{
	BinSearchTreeNode* pReturn = NULL;

	if (pBinSearchTree == NULL) {
		return NULL;
	}
	pReturn = pBinSearchTree->pRootNode;
	while(pReturn != NULL) {
		if (key == pReturn->key) {
			break;
		}
		else if (key < pReturn->key) {
			pReturn = pReturn->pLeftChild;
		}
		else {
			pReturn = pReturn->pRightChild;
		}
	}

	return pReturn;
}

void deleteBinSearchTree(BinSearchTree* pBinSearchTree)
{
	if (pBinSearchTree != NULL) {
		deleteBinSearchTreeInternal(pBinSearchTree->pRootNode);
		free(pBinSearchTree);
	}
}

void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode)
{
	if (pTreeNode != NULL) {
		deleteBinSearchTreeInternal(pTreeNode->pLeftChild);
		deleteBinSearchTreeInternal(pTreeNode->pRightChild);
		free(pTreeNode);
	}
}
