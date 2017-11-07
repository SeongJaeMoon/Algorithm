#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btreedef.h"
#include "btlinkedstack.h"
#include "btree.h"

// 트리의 생성
BTree* createBTree()
{
	BTree *pReturn = NULL;

	pReturn = (BTree *)malloc(sizeof(BTree));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(BTree));
	}
	else {
		printf("오류, 메모리할당 in createBTree()\n");
		return NULL;
	}

	return pReturn;
}

BTreeNodeData* searchBT(BTree* pBTree, int key) 
{
	BTreeNodeData* pReturn = NULL;
	BTreeNode* pCurrentNode = NULL;
	int i = 0;

	if (pBTree != NULL) {
		pCurrentNode = pBTree->pRootNode;
		while(pCurrentNode != NULL)	{
			for (i = 0; i < pCurrentNode->elementCount; i++) {
				int parentKey = pCurrentNode->element[i].key;
				if (key == parentKey) {
					pReturn = &pCurrentNode->element[i];
					return pReturn;
				}
				else if (key < parentKey) {
					break;
				}
			}
			pCurrentNode = pCurrentNode->pChildren[i];
		}
	}

	return pReturn;
}

int pushBTreeNode(LinkedStack* pStack, BTreeNode* data)
{
	StackNode node = {0,};
	node.data = data;

	return pushLS(pStack, node);
}

// 새로운 자료 삽입.
int insertNodeBT(BTree* pBTree, BTreeNodeData element)
{
	int ret = TRUE;
	int i = 0;
	BTreeNode *pParentNode = NULL, *pCurrentNode = NULL, *pNewNode = NULL;
	LinkedStack* pStack = NULL;

	if (pBTree == NULL) {
		ret = FALSE;
		return ret;
	}
	pStack = createLinkedStack();
	if (pStack == NULL) {
		ret = FALSE;
		return ret;
	}
	// INSERT할 leaf node 찾기.
	pCurrentNode = pBTree->pRootNode;
	while(pCurrentNode != NULL) {
		pParentNode = pCurrentNode;
		pushBTreeNode(pStack, pParentNode);

		for (i = 0; i < pCurrentNode->elementCount; i++) {
			int parentKey = pCurrentNode->element[i].key;
			if (element.key == parentKey) {
				printf("오류,중복된 키-[%d],insertNodeBT()\n", element.key);
				ret = FALSE;
				deleteLinkedStack(pStack);
				return ret;
			}
			else if (element.key < parentKey) {
				break;
			}
		}
		pCurrentNode = pCurrentNode->pChildren[i];
	}
	if (pParentNode == NULL) {	// ROOT 노드가 아직 없는 경우.
		pBTree->pRootNode = createBTreeNode(element);
	}
	else {
		insertNodeElementBT(pParentNode, element, NULL);

		splitNodeBT(pBTree, pStack);
	}
	ret = TRUE;
	deleteLinkedStack(pStack);

	return ret;
}

void splitNodeBT(BTree* pBTree, LinkedStack* pStack)
{
	StackNode* pParentStackNode = NULL;
	StackNode* pCurrentStackNode = NULL;
	BTreeNode* pParentBTreeNode = NULL;
	BTreeNode* pCurrentBTreeNode = NULL;
	BTreeNode* pNewBTreeNode = NULL;
	BTreeNodeData pivotElement = {0,};
	int pivotIndex = BTREE_ORDER / 2;
	int i = 0;

	if (pStack == NULL) {
		return;
	}
	pCurrentStackNode = popLS(pStack);
	while(pCurrentStackNode != NULL) {
		pCurrentBTreeNode =  pCurrentStackNode->data;
		if (pCurrentBTreeNode->elementCount >= BTREE_ORDER) {
			pNewBTreeNode = (BTreeNode *)malloc(sizeof(BTreeNode));
			if (pNewBTreeNode != NULL) {
				memset(pNewBTreeNode, 0, sizeof(BTreeNode));
			}
			else {
				printf("Error, malloc() in splitNodeBT()\n");
				break;
			}

			pivotElement = pCurrentBTreeNode->element[pivotIndex];
			memset(&pCurrentBTreeNode->element[pivotIndex], 0, sizeof(BTreeNodeData));

			for(i = pivotIndex + 1; i < BTREE_ORDER; i++) {
				pNewBTreeNode->element[i - pivotIndex - 1] = pCurrentBTreeNode->element[i];
				pNewBTreeNode->pChildren[i - pivotIndex - 1] = pCurrentBTreeNode->pChildren[i];

				memset(&pCurrentBTreeNode->element[i], 0, sizeof(BTreeNodeData));
				pCurrentBTreeNode->pChildren[i] = NULL;
			}
			pNewBTreeNode->pChildren[i - pivotIndex - 1] = pCurrentBTreeNode->pChildren[i];
			pCurrentBTreeNode->pChildren[i] = NULL;
			pNewBTreeNode->elementCount = BTREE_ORDER - pivotIndex - 1;
			pCurrentBTreeNode->elementCount = pivotIndex;

			pParentStackNode = popLS(pStack);
			if (pParentStackNode != NULL) {
				insertNodeElementBT(pParentStackNode->data, pivotElement, pNewBTreeNode);
			}
			else {
				// 트리 전체 Depth가 1증가.
				pBTree->pRootNode = createBTreeNode(pivotElement);
				pBTree->pRootNode->pChildren[0] = pCurrentBTreeNode;
				pBTree->pRootNode->pChildren[1] = pNewBTreeNode;
			}
		}
		
		if (pCurrentStackNode != NULL) {
			free(pCurrentStackNode);
		}
		pCurrentStackNode = pParentStackNode;
		pParentStackNode = NULL;
	}

	if (pCurrentStackNode != NULL) free(pCurrentStackNode);
	if (pParentStackNode != NULL) free(pParentStackNode);
}

BTreeNode* createBTreeNode(BTreeNodeData element)
{
	BTreeNode* pReturn = NULL;

	pReturn = (BTreeNode *)malloc(sizeof(BTreeNode));
	if (pReturn != NULL) {	// 메모리 할당 성공 검증
		// 데이터 초기화.
		memset(pReturn, 0, sizeof(BTreeNode));
		pReturn->element[0] = element;
		pReturn->elementCount = 1;
	}
	else {
		printf("Error, malloc() in createBTreeNode()\n");
	}

	return pReturn;
}

void insertNodeElementBT(BTreeNode* pCurrentNode, 
				BTreeNodeData element,
				BTreeNode* pRChildNode) {
	int i = 0;
	for(i = pCurrentNode->elementCount - 1; i >= 0; i--) {
		int tempKey = pCurrentNode->element[i].key;
		if (element.key < tempKey) {
			pCurrentNode->element[i+1] = pCurrentNode->element[i];
			pCurrentNode->pChildren[i+2] = pCurrentNode->pChildren[i+1];
		}
		else {
			break;
		}
	}
	pCurrentNode->element[i+1] = element;
	pCurrentNode->pChildren[i+2] = pRChildNode;
	pCurrentNode->elementCount++;
}

// 기존 자료 삭제.
int deleteNodeBT(BTree* pBTree, int key)
{
	int ret = TRUE;
	int i = 0;
	int isFind = FALSE;
	int isFinish = FALSE;
	BTreeNode* pParentNode = NULL;
	BTreeNode* pCurrentNode = NULL;
	BTreeNode* pNewNode = NULL;
	LinkedStack* pStack = NULL;

	if (pBTree == NULL) {
		ret = FALSE;
		return ret;
	}

	pStack = createLinkedStack();
	if (pStack == NULL) {
		ret = FALSE;
		return ret;
	}

	// DELETE할 node 찾기.
	pCurrentNode = pBTree->pRootNode;
	while(pCurrentNode != NULL && isFind == FALSE) {
		pParentNode = pCurrentNode;
		pushBTreeNode(pStack, pParentNode);

		for (i = 0; i < pCurrentNode->elementCount; i++) {
			int parentKey = pCurrentNode->element[i].key;
			if (key == parentKey) {
				isFind = TRUE;
				break;
			}
			else if (key < parentKey) {
				break;
			}
		}
		pCurrentNode = pCurrentNode->pChildren[i];
	}

	if (isFind == TRUE) {
		if (isLeafNode(pParentNode) == FALSE) {
			pParentNode = replaceLeafNodeBT(pBTree, pParentNode, i, pStack);
		}
		else {
			deleteKeyBT(pParentNode, i);
		}
		if (pParentNode->elementCount < (BTREE_ORDER/2)) {
			balanceBTree(pBTree, pStack);
		}

		ret = TRUE;
	}
	else {
		ret = FALSE;
		printf("오류,검색키-[%d]가 발견되지 않습니다,deleteNodeBT()\n", key);

	}
	deleteLinkedStack(pStack);

	return ret;
}

void balanceBTree(BTree *pBTree, LinkedStack* pStack)
{
	int ret = FALSE;

	StackNode* pParentStackNode = NULL;
	StackNode* pCurrentStackNode = NULL;
	BTreeNode* pParentBTreeNode = NULL;
	BTreeNode* pCurrentBTreeNode = NULL;
	BTreeNode* pNewBTreeNode = NULL;

	BTreeNode* pLeftBTreeNode = NULL;
	BTreeNode* pRightBTreeNode = NULL;

	BTreeNodeData pivotElement = {0,};
	int pivotIndex = BTREE_ORDER / 2;
	int i = 0;
	int index = 0;

	if (pStack == NULL) {
		return;
	}
	pCurrentStackNode = popLS(pStack);
	if (pCurrentStackNode == NULL) {
		return;
	}

	pCurrentBTreeNode =  pCurrentStackNode->data;
	if (pCurrentBTreeNode->elementCount >= (BTREE_ORDER/2)) {
		free(pCurrentStackNode);
		return;
	}

	pParentStackNode = popLS(pStack);
	if (pParentStackNode == NULL) {
		free(pCurrentStackNode);
		return;
	}

	pParentBTreeNode = pParentStackNode->data;
	index = getIndexInfo(pParentBTreeNode, pCurrentBTreeNode);

	// 오른쪽에서 빌려옴.
	if (index < pParentBTreeNode->elementCount
		&& pParentBTreeNode->pChildren[index+1]->elementCount >= (BTREE_ORDER/2 + 1)) {
		borrowRightNodeBT(pParentBTreeNode, pCurrentBTreeNode, index, pParentBTreeNode->pChildren[index+1]);
	// 왼쪽에서 빌려옴.
	} else if (index > 0
			&& pParentBTreeNode->pChildren[index-1]->elementCount >= (BTREE_ORDER/2 + 1)) {
		borrowLeftNodeBT(pParentBTreeNode, pCurrentBTreeNode, index, pParentBTreeNode->pChildren[index-1]);
	}
	else {
		// 병합.
		mergeNodeBT(pBTree, pStack, pParentBTreeNode, pCurrentBTreeNode, index);
	}

	if (pCurrentStackNode != NULL) {
		free(pCurrentStackNode);
	}
	if (pParentStackNode != NULL) {
		free(pParentStackNode);
	}
}

void borrowRightNodeBT(BTreeNode* pParentNode, 
					 BTreeNode* pCurrentNode, int index, 
					 BTreeNode* pRightNode)
{
	int elementCount = 0;

	if (pParentNode == NULL || pCurrentNode == NULL || pRightNode == NULL) {
		return;
	}

	// Parent 노드에서 자료 한 개 가져오기.
	elementCount = pCurrentNode->elementCount;
	pCurrentNode->element[elementCount] = pParentNode->element[index];
	pCurrentNode->elementCount++;

	// 오른쪽 노드의 가장 왼쪽 자료 가져오기.
	pParentNode->element[index] = pRightNode->element[0];

	// 오른쪽 노드 왼쪽으로 한칸씩 Shift.
	deleteKeyBT(pRightNode, 0);
}

void borrowLeftNodeBT(BTreeNode* pParentNode, 
					BTreeNode* pCurrentNode, int index, 
					BTreeNode* pLeftNode)
{
	int elementCount = 0;
	BTreeNodeData leftElement = {0,};
	BTreeNodeData parentElement = {0,};

	if (pParentNode == NULL || pCurrentNode == NULL || pLeftNode == NULL) {
		return;
	}

	//왼쪽 노드의 가장 오른쪽 자료를 부모 노드로 이동.
	elementCount = pLeftNode->elementCount;
	leftElement = pLeftNode->element[elementCount - 1];
	parentElement = pParentNode->element[index - 1];
	deleteKeyBT(pLeftNode, elementCount - 1);

	pParentNode->element[index - 1] = leftElement;

	// Parent 노드의 자료를 오른쪽 노드의 가장 왼쪽으로 insert하기.
	insertNodeElementBT(pCurrentNode, 
				parentElement,
				NULL);
}

void mergeNodeBT(BTree *pBTree, LinkedStack* pStack, 
				BTreeNode* pParentBTreeNode, 
				BTreeNode* pCurrentBTreeNode, int index)
{
	StackNode* pParentStackNode = NULL;
	BTreeNode* pParentParentNode = NULL;
	BTreeNode* pLeftNode = NULL;
	BTreeNode* pRightNode = NULL;
	BTreeNodeData parentElement = {0,};
	int i = 0;
	int pivotIndex = 0;

	if (pBTree == NULL || pStack == NULL 
		|| pParentBTreeNode == NULL || pCurrentBTreeNode == NULL) {
		return;
	}

	// 오른쪽 노드와 병합.
	if (index < pParentBTreeNode->elementCount) {
		pLeftNode = pCurrentBTreeNode;
		pRightNode = pParentBTreeNode->pChildren[index+1];
		pivotIndex = index;
		parentElement = pParentBTreeNode->element[pivotIndex];
	}
	else {
		//왼쪽 노드와 병합.
		pLeftNode = pParentBTreeNode->pChildren[index-1];
		pRightNode = pCurrentBTreeNode;
		pivotIndex = index-1;
		parentElement = pParentBTreeNode->element[pivotIndex];
	}

	// 왼쪽 노드에 Parent 자료 추가.
	insertNodeElementBT(pLeftNode, parentElement, pRightNode->pChildren[0]);

	// 왼쪽 노드에 오른쪽 노드 자료들 추가.
	for(i = 0; i < pRightNode->elementCount; i++) {
		insertNodeElementBT(pLeftNode, pRightNode->element[i], pRightNode->pChildren[i+1]);
	}
	deleteKeyBT(pParentBTreeNode, pivotIndex);
	free(pRightNode);

	if (pParentBTreeNode->elementCount < (BTREE_ORDER/2)) {
		int index = 0;
		pParentStackNode = popLS(pStack);
		if (pParentStackNode != NULL) {
			pParentParentNode = pParentStackNode->data;
			index = getIndexInfo(pParentParentNode, pParentBTreeNode);

			//displayBTree(pBTree);

			mergeNodeBT(pBTree, pStack, 
					pParentParentNode, 
					pParentBTreeNode, index);

			free( pParentStackNode );
		}
		else {
			if (pParentBTreeNode->elementCount == 0) {
				free( pBTree->pRootNode );
				pBTree->pRootNode = pLeftNode;
				//printf("LAST: %d, %c", pLeftNode->element[0].key, pLeftNode->element[0].value);
			}
		}
	}
}

BTreeNode* replaceLeafNodeBT(BTree *pBTree, BTreeNode* pDelNode, int index,
								LinkedStack* pStack)
{
	BTreeNode* pReturn = NULL;
	BTreeNodeData leafNodeElement = {0,};
	BTreeNode *pChildNode = NULL;
	BTreeNode* pParentNode = pDelNode;
	int elementCount = index;

	if (pBTree == NULL || pDelNode == NULL) {
		return pReturn;
	}

	do {
		pChildNode = pParentNode->pChildren[elementCount];
		pushBTreeNode(pStack, pChildNode);

		elementCount = pChildNode->elementCount;
		pParentNode = pChildNode;
	}
	while(pChildNode->pChildren[elementCount] != NULL);

	leafNodeElement = pChildNode->element[elementCount - 1];
	pDelNode->element[index] = leafNodeElement;
	deleteKeyBT(pChildNode, elementCount - 1);

	pReturn = pChildNode;

	return pReturn;
}

int isLeafNode(BTreeNode* pParentNode)
{
	int ret = FALSE;

	if (pParentNode != NULL) {
		if (pParentNode->pChildren[0] == NULL) {
			ret = TRUE;
		}
	}

	return ret;
}

int getIndexInfo(BTreeNode* pParentNode, BTreeNode* pCurrentNode)
{
	int ret = 0;
	int i = 0;

	if (pParentNode != NULL) {
		for(i = 0; i <= pParentNode->elementCount; i++) {
			if (pParentNode->pChildren[i] == pCurrentNode) {
				ret = i;
				break;
			}
		}
	}

	return ret;
}

void deleteKeyBT(BTreeNode* pNode, int index)
{
	int i = 0;
	if (pNode != NULL) {
		for(i = index + 1; i < pNode->elementCount; i++) {
			pNode->element[i - 1] = pNode->element[i];
			pNode->pChildren[i] = pNode->pChildren[i+1];
		}
		memset(&pNode->element[pNode->elementCount - 1], 0, sizeof(BTreeNodeData));
		pNode->pChildren[pNode->elementCount] = NULL;

		pNode->elementCount--;
	}
}

void displayBTree(BTree *pTree)
{
	if (pTree != NULL) {
		displayBTreeNode(pTree->pRootNode);
	}
}

void displayBTreeNode(BTreeNode *pNode)
{
    int i;
    static int x = 0;
	if (pNode != NULL) {
		x += 2;
		for (i = 2; i < x; i++) {
			printf("   ");
		}
		for (i = 0; i < pNode->elementCount; i++) {
			printf("(%d,%c) ", pNode->element[i].key, pNode->element[i].value);
		}
		printf("\n");
		for (i = 0; i < pNode->elementCount + 1; i++) {
			displayBTreeNode(pNode->pChildren[i]);
		}
		x -= 2;
	}
}

// 트리의 삭제
void deleteBTree(BTree* pBTree)
{
	if (pBTree != NULL) {
		deleteBTreeNode(pBTree->pRootNode);
		free(pBTree);
	}
}

// 트리 노드의 삭제(재귀적)
void deleteBTreeNode(BTreeNode* pBTreeNode)
{
	int i = 0;
	if (pBTreeNode != NULL) {
		for(i = 0; i <= pBTreeNode->elementCount; i++) {
			deleteBTreeNode(pBTreeNode->pChildren[i]);
		}
		free(pBTreeNode);
	}
}

