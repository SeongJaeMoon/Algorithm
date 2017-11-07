#ifndef _AVL_DEF_
#define _AVL_DEF_

#define VALUE_SIZE	100

typedef struct AVLTreeNodeDataType
{
	int key;
	char value[VALUE_SIZE + 1];
} AVLTreeNodeData;

typedef struct AVLTreeNodeType
{
	AVLTreeNodeData data;

	int balance;
	int height;
	struct AVLTreeNodeType* pLeftChild;
	struct AVLTreeNodeType* pRightChild;
} AVLTreeNode;

#endif