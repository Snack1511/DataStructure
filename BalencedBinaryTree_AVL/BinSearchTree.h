#ifndef _BINSEARCH_
#define _BINSEARCH_
typedef struct BinSearchTreeNodeType TreeNode;
typedef struct BinSearchTreeType Tree;
struct BinSearchTreeNodeType {
	int key;
	char data;

	TreeNode* pLeft;
	TreeNode* pRight;
};
struct BinSearchTreeType {
	TreeNode* pRoot;
	
};

Tree* CreateTree();
int InsertNode(Tree* pTree, TreeNode node);
int DeleteNode(Tree* pTree, int key);

TreeNode* SearchRecursiveTree(Tree* pTree, int key);
TreeNode* SearchInternalRecursiveTree(Tree* pTree, int key);
TreeNode* SearchTree(Tree* pTree, int key);

void DeleteTree(Tree* pTree);
void DeleteTreeInternal(TreeNode* pNode);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_! 