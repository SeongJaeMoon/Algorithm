#ifndef _B_TREE_
#define _B_TREE_

typedef struct BTreeType
{
	BTreeNode *pRootNode;
} BTree;

// 트리의 생성
BTree* createBTree();

BTreeNode* createBTreeNode(BTreeNodeData element);

// 트리의 삭제
void deleteBTree(BTree* pBTree);

// 트리 노드의 삭제(재귀적)
void deleteBTreeNode(BTreeNode* pBTreeNode);

// 새로운 노드 삽입.
int insertNodeBT(BTree* pBTree, BTreeNodeData element);

void insertNodeElementBT(BTreeNode* pCurrentNode, 
				BTreeNodeData element,
				BTreeNode* pRChildNode);

void splitNodeBT(BTree* pBTree, struct LinkedStackType* pStack);

// 기존 자료 삭제.
int deleteNodeBT(BTree* pBTree, int key);

int isLeafNode(BTreeNode* pParentNode);

BTreeNode* replaceLeafNodeBT(BTree *pBTree, BTreeNode* pDelNode, int index,
								struct LinkedStackType* pStack);

void deleteKeyBT(BTreeNode* pNode, int index);

// 균형 잡기.
void balanceBTree(BTree* pBTree, struct LinkedStackType* pStack);

int getIndexInfo(BTreeNode* pParentNode, BTreeNode* pCurrentNode);

void borrowRightNodeBT(BTreeNode* pParentNode, BTreeNode* pCurrentNode, int index, BTreeNode* pRightNode);

void borrowLeftNodeBT(BTreeNode* pParentNode, BTreeNode* pCurrentNode, int index, BTreeNode* pLeftNode);

void mergeNodeBT(BTree *pBTree, struct LinkedStackType* pStack, BTreeNode* pParentBTreeNode, BTreeNode* pCurrentBTreeNode, int index);

// (반복적) 탐색.
BTreeNodeData* searchBT(BTree* pBTree, int key);

void displayBTree(BTree *pTree);

void displayBTreeNode(BTreeNode *pNode);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif