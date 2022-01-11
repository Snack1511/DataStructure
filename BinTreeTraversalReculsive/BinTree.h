#pragma once
#ifndef _BINTREE_
#define _BINTREE_
typedef struct  BinTreeNodeType TreeNode;
typedef struct BinTreeType Tree;

struct BinTreeNodeType{
	char data;
	TreeNode* pLeftChild;
	TreeNode* pRightChild;
};
struct BinTreeType {
	TreeNode* pRootNode;
};

Tree* MakeBinTree(TreeNode Rootnode);
TreeNode* GetRoot(Tree* pTree);
TreeNode* InsertLeftChild(TreeNode* pParent, TreeNode node);
TreeNode* InsertRightChild(TreeNode* pParent, TreeNode node);
TreeNode* GetLeftChild(TreeNode* pNode);
TreeNode* GetRightChild(TreeNode* pNode);
void DeleteTree(Tree* pTree);
void DeleteTreeNode(TreeNode* pNode);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_! 