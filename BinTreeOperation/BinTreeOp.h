#ifndef _BINTREEOP_
#define _BINTREEOP_

Tree* CopyBinTree(Tree* pSource);
TreeNode* CopyBinTreeNode(TreeNode* pSourceNode);

int EqualBinTree(Tree* pFirst, Tree* pSecond);
int EqualBinTreeNode(TreeNode* pFirstNode, TreeNode* pSecondNode);

int GetNodeCountTree(Tree* pSource);
int GetNodeCountTreeNode(TreeNode* pSourceNode);

int GetLeafNodeCountTree(Tree* pSource);
int GetLeafNodeCountTreeNode(TreeNode* pSourceNode);

int GetHeightTree(Tree* pSource);
int GetHeightTreeNode(TreeNode* pSourceNode);

void DisplayTree(Tree* pSource);
void DisplayTreeNode(TreeNode* pSourceNode, int level, char type);


#endif // !_BINTREEOP_
