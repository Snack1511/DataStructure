#ifndef _AVLBBT_
#define _AVLBBT_

typedef struct TreeNodeType TreeNode;
typedef struct TreeType Tree;
typedef char DATA;
struct TreeNodeType {
	int key;
	DATA Data;
	TreeNode* pLeft;
	TreeNode* pRight;
};

struct TreeType {
	TreeNode* pRoot;
};

Tree* CreateBSTree();
void InsertElement(Tree* pTree, int Key, DATA data);
void RemoveElement(Tree* pTree, int Key);
DATA GetElement(Tree* pTree, int Key);
void DisplayTree(TreeNode* pTreeNode, int level, char type);
void DeleteTree(Tree* pTree);

int GetHeight(TreeNode* pTreeNode);
int IsBalenced(TreeNode* pTreeNode);
void SetBalence(TreeNode* pTreeNode, int iBalence);
void LLRotate(TreeNode* pTreeNode);
void RRRotate(TreeNode* pTreeNode);
void LRRotate(TreeNode* pTreeNode);
void RLRotate(TreeNode* pTreeNode);

#endif

#ifndef _COMMON_
#define _COMMON_

void Swap(TreeNode* pA, TreeNode* pB);
#endif 
