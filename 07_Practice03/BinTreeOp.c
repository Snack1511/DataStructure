#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BinTree.h"
#include"BinTreeOp.h"

Tree* CopyBinTree(Tree* pSource) {
	Tree* pReturn = NULL;
	if (pSource != NULL) {
		pReturn = (Tree*)malloc(sizeof(Tree));
		if (pReturn != NULL) {
			pReturn->pRootNode = CopyBinTreeNode(pSource->pRootNode);
		}
	}
	return pReturn;
}
TreeNode* CopyBinTreeNode(TreeNode* pSourceNode) {
	TreeNode* pReturn = NULL;
	if (pSourceNode != NULL) {
		pReturn = (TreeNode*)malloc(sizeof(TreeNode));
		if (pReturn != NULL) {
			*pReturn = *pSourceNode;
			pReturn->pLeftChild = CopyBinTreeNode(pSourceNode->pLeftChild);
			pReturn->pRightChild = CopyBinTreeNode(pSourceNode->pRightChild);
		}
	}
	return pReturn;
}

int EqualBinTree(Tree* pFirst, Tree* pSecond) {
	int ret = FALSE;
	if (pFirst == NULL && pSecond == NULL) {
		ret = TRUE;
	}
	else if (pFirst != NULL && pSecond != NULL && EqualBinTreeNode(pFirst->pRootNode, pSecond->pRootNode)) {
		ret = TRUE;
	}
	return ret;
}
int EqualBinTreeNode(TreeNode* pFirstNode, TreeNode* pSecondNode) {
	int ret = FALSE;
	if (pFirstNode == NULL && pSecondNode == NULL) {
		ret = TRUE;
	}
	else if (pFirstNode != NULL && pSecondNode != NULL) {
		if (pFirstNode->data == pSecondNode->data && EqualBinTreeNode(pFirstNode->pLeftChild, pSecondNode->pLeftChild) && EqualBinTreeNode(pFirstNode->pRightChild, pSecondNode->pRightChild)) {
			ret = TRUE;
		}
	}
	return ret;
}

int GetNodeCountTree(Tree* pSource) {
	int ret = 0;
	if (pSource != NULL) {
		ret = GetNodeCountTreeNode(pSource->pRootNode);
	}
	return ret;
}
int GetNodeCountTreeNode(TreeNode* pSourceNode) {
	int ret = 0;
	if (pSourceNode != NULL) {
		ret = GetNodeCountTreeNode(pSourceNode->pLeftChild) + GetHeightTreeNode(pSourceNode->pRightChild) + 1;
	}
	return ret;
}

int GetLeafNodeCountTree(Tree* pSource) {
	int ret = 0;
	if (pSource != NULL) {
		ret = GetLeafNodeCountTreeNode(pSource->pRootNode);
	}
	return ret;
}
int GetLeafNodeCountTreeNode(TreeNode* pSourceNode) {
	int ret = 0;
	if (pSourceNode != NULL) {
		if (pSourceNode->pLeftChild == NULL && pSourceNode->pRightChild == NULL) {
			ret = 1;
		}
		else {
			ret = GetLeafNodeCountTreeNode(pSourceNode->pLeftChild) + GetLeafNodeCountTreeNode(pSourceNode->pRightChild);
		}
	}
	
	return ret;
}

int GetHeightTree(Tree* pSource) {
	int ret = 0;
	if (pSource != NULL) {
		ret = GetHeightTreeNode(pSource->pRootNode);
	}
	return ret;
}
int GetHeightTreeNode(TreeNode* pSourceNode) {
	int ret = 0;
	if (pSourceNode != NULL) {
		if (pSourceNode->pLeftChild == NULL && pSourceNode->pRightChild == NULL) {
			ret = 1;
		}
		else {
			int LeftHeight = GetLeafNodeCountTreeNode(pSourceNode->pLeftChild);
			int RightHeight = GetLeafNodeCountTreeNode(pSourceNode->pRightChild);

			if (LeftHeight >= RightHeight) {
				ret = LeftHeight + 1;
			}
			else {
				ret = RightHeight + 1;
			}
		}
	}
	return ret;
}

void DisplayTree(Tree* pSource) {
	if (pSource != NULL) {
		DisplayTreeNode(pSource->pRootNode, 0, 'O');
	}
}
void DisplayTreeNode(TreeNode* pSourceNode, int level, char type) {
	int i = 0; 
	for (i = 0; i < level; i++) {
		printf("    ");
	}
	if (pSourceNode != NULL) {
		printf("-[%i,%c]%c\n", level, type, pSourceNode->data);
		DisplayTreeNode(pSourceNode->pLeftChild, level + 1, 'L');
		DisplayTreeNode(pSourceNode->pRightChild, level + 1, 'R');
	}
	else {
		printf("\n");
	}
}

int GetNodeCountInternalNodeTree(Tree* pSource) {
	int ret = 0;
	if (pSource != NULL) {
		ret = GetNodeCountInternalNodeTreeNode(pSource->pRootNode);
	}
	return ret;
}
int GetNodeCountInternalNodeTreeNode(TreeNode* pSourceNode) {
	int ret = 0;
	if (pSourceNode != NULL) {
		ret += GetLeafNodeCountTreeNode(pSourceNode->pLeftChild);
		ret += GetLeafNodeCountTreeNode(pSourceNode->pRightChild);
		if (pSourceNode->pLeftChild == NULL && pSourceNode->pRightChild == NULL) {
			ret += 0;
		}
		else {
			ret += 1;
		}
			//ret = GetLeafNodeCountTreeNode(pSourceNode->pLeftChild) + GetLeafNodeCountTreeNode(pSourceNode->pRightChild);
		
	}
	return ret;
}

void InCreaseKeyTree(Tree* pSource) {
	if (pSource != NULL) {
		InCreaseKeyTreeNode(pSource->pRootNode);
	}
}
void InCreaseKeyTreeNode(TreeNode* pSourceNode) {
	if (pSourceNode != NULL) {
		pSourceNode->data += 2;
		InCreaseKeyTreeNode(pSourceNode->pLeftChild);
		InCreaseKeyTreeNode(pSourceNode->pRightChild);
	}
}