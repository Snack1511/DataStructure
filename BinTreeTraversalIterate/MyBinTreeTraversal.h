#ifndef _MYTREETRAVERSAL_
#define _MYTREETRAVERSAL_


void MyPreorderTraversalIterateTree(Tree* pTree);
void PreorderTraversalIterateTreeNode(TreeNode* pTreeNode);

void MyInorderTraversalIterateTree(Tree* pTree);
void InorderTraversalIterateTreeNode(TreeNode* pTreeNode);

void MyPostorderTraversalIterateTree(Tree* pTree);
void PostorderTraversalIterateTreeNode(TreeNode* pTreeNode);

void MyLevelTraversalIterateTree(Tree* pTree);
void LevelTraversalIterateTreeNode(TreeNode* pTreeNode);

void ResetVisitInformation(Tree* pTree);
#endif