#ifndef _AVL_TREE_
#define _AVL_TREE_

typedef struct AVLTreeType
{
	AVLTreeNode *pRootNode;
} AVLTree;

// 트리의 생성
AVLTree* createAVLTree();

// 트리의 삭제
void deleteAVLTree(AVLTree* pAVLTree);

// 트리 노드의 삭제(재귀적)
void deleteAVLTreeNode(AVLTreeNode* pAVLTreeNode);

// 새로운 노드 삽입.
int insertNodeAVL(AVLTree* pAVLTree, AVLTreeNodeData data);

// 기존 노드 삭제.
int deleteNodeAVL(AVLTree* pAVLTree, int key);

// 균형 잡기.
void balanceAVLTree(AVLTree* pAVLTree, LinkedStack* pStack);

int pushAVLTreeNode(LinkedStack* pStack, AVLTreeNode* data);

AVLTreeNode *popAVLTreeNode(LinkedStack* pStack);

AVLTreeNode *peekAVLTreeNode(LinkedStack* pStack);

// 균형 잡기: LL 회전
AVLTreeNode* rotateLLAVLTree(AVLTreeNode *pParentNode);

// 균형 잡기: LR 회전
AVLTreeNode* rotateLRAVLTree(AVLTreeNode *pParentNode);

// 균형 잡기: RR 회전
AVLTreeNode* rotateRRAVLTree(AVLTreeNode *pParentNode);

// 균형 잡기: RL 회전
AVLTreeNode* rotateRLAVLTree(AVLTreeNode *pParentNode);

// 높이, 균형 정보 변경.
void updateHeightAndBalanceAVL(AVLTreeNode* pNode);

// (반복적) 탐색.
AVLTreeNode* searchAVL(AVLTree* pAVLTree, int key);

void displayAVLTree(AVLTree *pTree);

void displayAVLTreeInternal(AVLTreeNode *pTreeNode, int level, char type);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif