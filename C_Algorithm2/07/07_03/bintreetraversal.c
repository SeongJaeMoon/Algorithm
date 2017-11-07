#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "bintreelinkedstack.h"
#include "bintreelinkedqueue.h"
#include "bintreetraversal.h"

int pushLSBinTreeNode(LinkedStack* pStack, BinTreeNode *pNode)
{
	StackNode node = {0,};
	node.data = pNode;
	return pushLS(pStack, node);
}

int enqueueLQBinTreeNode(LinkedQueue* pQueue, BinTreeNode *pNode)
{
	QueueNode node = {0,};
	node.data = pNode;
	return enqueueLQ(pQueue, node);
}

void preorderTraversalBinTree(BinTree *pBinTree)
{
	LinkedStack* pStack = NULL;
	StackNode* pStackNode = NULL;
	BinTreeNode *pRootNode = NULL, *pLeftChildNode = NULL, *pRightChildNode = NULL;

	if (pBinTree == NULL) {
		return;
	}
	pRootNode = getRootNodeBT(pBinTree);
	if (pRootNode == NULL){
		return;
	}
	pStack = createLinkedStack();
	if (pStack == NULL) {
		return;
	}
	pushLSBinTreeNode(pStack, pRootNode);
	while(1) {
		if (isLinkedStackEmpty(pStack) == TRUE) {
			break;
		}
		else {
			pStackNode = popLS(pStack);
			if (pStackNode != NULL) {
				pRootNode = pStackNode->data;
				printf("%c ", pRootNode->data);

				pLeftChildNode = getLeftChildNodeBT(pRootNode);
				pRightChildNode = getRightChildNodeBT(pRootNode);
				if (pRightChildNode != NULL) {
					pushLSBinTreeNode(pStack, pRightChildNode);
				}
				if (pLeftChildNode != NULL) {
					pushLSBinTreeNode(pStack, pLeftChildNode);
				}

				free(pStackNode);
			}
		}
	}
	deleteLinkedStack(pStack);
}

void inorderTraversalBinTree(BinTree *pBinTree)
{
	LinkedStack* pStack = NULL;
	StackNode* pStackNode = NULL;
	BinTreeNode *pRootNode = NULL, *pNode = NULL;

	if (pBinTree == NULL) {
		return;
	}
	pRootNode = getRootNodeBT(pBinTree);
	if (pRootNode == NULL){
		return;
	}
	pStack = createLinkedStack();
	if (pStack == NULL) {
		return;
	}
	pNode = pRootNode;
	while(1) {
		for(;pNode != NULL; pNode = getLeftChildNodeBT(pNode)) {
			pushLSBinTreeNode(pStack, pNode);
		}
		
		if (isLinkedStackEmpty(pStack) == TRUE) {
			break;
		}
		else {
			pStackNode = popLS(pStack);
			if (pStackNode != NULL) {
				pNode = pStackNode->data;
				printf("%c ", pNode->data);
				pNode = getRightChildNodeBT(pNode);
				free(pStackNode);
			}
		}
	}
	deleteLinkedStack(pStack);
}

void postorderTraversalBinTree(BinTree *pBinTree)
{
	LinkedStack* pStack = NULL;
	StackNode* pStackNode = NULL;
	BinTreeNode *pRootNode = NULL, *pLeftChildNode = NULL, *pRightChildNode = NULL;

	if (pBinTree == NULL) {
		return;
	}
	pRootNode = getRootNodeBT(pBinTree);
	if (pRootNode == NULL){
		return;
	}
	pStack = createLinkedStack();
	if (pStack == NULL) {
		return;
	}
	pushLSBinTreeNode(pStack, pRootNode);
	while(1) {
		if (isLinkedStackEmpty(pStack) == TRUE) {
			break;
		}
		else {
			pStackNode = peekLS(pStack);
			if (pStackNode != NULL) {
				pRootNode = pStackNode->data;

				pLeftChildNode = getLeftChildNodeBT(pRootNode);
				if (pLeftChildNode != NULL && pLeftChildNode->visited == FALSE) {
					pushLSBinTreeNode(pStack, pLeftChildNode);
				}
				else {
					pRightChildNode = getRightChildNodeBT(pRootNode);
					if (pRightChildNode != NULL && pRightChildNode->visited == FALSE) {
						pushLSBinTreeNode(pStack, pRightChildNode);
					}
					else {
						pRootNode->visited = TRUE;
						printf("%c ", pRootNode->data);

						free( popLS(pStack) );
					}
				}
			} // end-of-if
		} //end-of-else
	} //end-of-while
	deleteLinkedStack(pStack);
}

void levelOrderTraversalBinTree(BinTree *pBinTree)
{
	LinkedQueue* pQueue = NULL;
	QueueNode* pQueueNode = NULL;
	BinTree* pSubTree = NULL;
	BinTreeNode *pRootNode = NULL, *pLeftChildNode = NULL, *pRightChildNode = NULL;

	if (pBinTree == NULL) {
		return;
	}
	pRootNode = getRootNodeBT(pBinTree);
	if (pRootNode == NULL){
		return;
	}
	pQueue = createLinkedQueue();
	if (pQueue == NULL) {
		return;
	}
	enqueueLQBinTreeNode(pQueue, pRootNode);
	while(1) {
		if (isLinkedQueueEmpty(pQueue) == TRUE) {
			return;
		}
		else {
			pQueueNode = dequeueLQ(pQueue);
			if (pQueueNode != NULL) {
				pRootNode = pQueueNode->data;

				if (pRootNode != NULL) {
					printf("%c ", pRootNode->data);
				}
				pLeftChildNode = getLeftChildNodeBT(pRootNode);
				pRightChildNode = getRightChildNodeBT(pRootNode);
				if (pLeftChildNode != NULL) {
					enqueueLQBinTreeNode(pQueue, pLeftChildNode);
				}
				if (pRightChildNode != NULL) {
					enqueueLQBinTreeNode(pQueue, pRightChildNode);
				}

				free( pQueueNode );
			}
		}
	}
	deleteLinkedQueue(pQueue);
}
