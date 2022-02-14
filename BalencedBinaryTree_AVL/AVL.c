#include<stdio.h>
#include<string.h>

#include"AVL.h"

Tree* CreateBSTree() {
	Tree* pReturn = NULL;

	pReturn = (Tree*)malloc(sizeof(Tree));
	pReturn->pRoot = NULL;
	return pReturn;
}
void InsertElement(Tree* pTree, int Key, DATA data) {
	TreeNode* pAdd = (TreeNode*)malloc(sizeof(TreeNode));
	pAdd->key = Key;
	pAdd->Data = data;
	pAdd->pLeft = NULL;
	pAdd->pRight = NULL;

	if (NULL != pTree) {
		TreeNode* pNode = pTree->pRoot;
		if (NULL != pNode) {
			while (NULL!= pNode->pLeft || NULL != pNode->pRight) {
				if ((pNode->key < pAdd->key) && NULL != pNode->pRight) {
					pNode = pNode->pRight;
				}
				else if((pNode->key > pAdd->key) && NULL != pNode->pLeft){
					pNode = pNode->pLeft;
				}
			}
			if (pNode->key < pAdd->key) {
				pNode->pRight = pAdd;
			}
			else {
				pNode->pLeft = pAdd;

			}
		}
		else {
			pTree->pRoot = pAdd;
		}
	}

	// Ʈ�� ��ü Ž��
		/*
		 * ������ �̿��� ����Ž��
		 * Ž������ --> �ܸ��� ���θ����
		 * ������ --> IsBalence �� ������ �ޱ�
		 * LL, RR, LR, RL ���� ȸ�� --> SetBalence
		 * ��ȭ ������ ������� ��, ��ȭ ����� �ش��� ���
		*/
	// ����
}
void RemoveElement(Tree* pTree, int Key) {
	TreeNode* pNode = NULL, *pTarget = NULL;

	if (NULL != pTree && NULL != pTree->pRoot) {
		pNode = pTree->pRoot;
		if (NULL != pNode) {
			while (Key != pNode->key) {
				if (Key > pNode->key) {
					pNode = pNode->pRight;

				}
				else {
					pNode = pNode->pLeft;
				}
			}
			pTarget = pNode->pLeft;
			if (NULL != pTarget) {
				while (NULL != pTarget->pRight) {
					pTarget = pTarget->pRight;
				}
				Swap(pNode, pTarget);
			}
			free(pTarget);
			pTarget = NULL;
		}
	}
}
DATA GetElement(Tree* pTree, int Key) {
	TreeNode* pNode = NULL;
	if (NULL != pTree && NULL != pTree->pRoot) {
		pNode = pTree->pRoot;
		while (Key != pNode->key) {
			if (Key > pNode->key) {
				pNode = pNode->pRight;
			}
			else {
				pNode = pNode->pLeft;
			}
		}
	}
	else {
		return -1;
	}
	return pNode->Data;
}
void DisplayTree(TreeNode* pTreeNode, int level, char type)
{
	int i = 0;
	for (i = 0; i < level; i++) {
		printf("    ");
	}

	if (pTreeNode != NULL) {
		printf("-[%i,%c]%i-%c\n", level, type,
			pTreeNode->key, pTreeNode->Data);

		DisplayTree(pTreeNode->pLeft, level + 1, 'L');
		DisplayTree(pTreeNode->pRight, level + 1, 'R');
	}
	else {
		printf("NULL\n");
	}
}
void DeleteTree(Tree* pTree);

int GetHeight(TreeNode* pTreeNode) {

	int LHeight = 0;
	int RHeight = 0;
	if (pTreeNode != NULL) {
		LHeight = GetHeight(pTreeNode->pLeft) + 1;
		RHeight = GetHeight(pTreeNode->pRight) + 1;
	}
	else return -1;

	if (LHeight < RHeight) {
		return RHeight;
	}
	else {
		return LHeight;
	}

}
int IsBalenced(TreeNode* pTreeNode) {
	int LHeight = GetHeight(pTreeNode->pLeft);
	int RHeight = GetHeight(pTreeNode->pRight);

	return (LHeight - RHeight);
}
void SetBalence(TreeNode* pTreeNode, int iBalence);
void LLRotate(TreeNode* pTreeNode);
void RRRotate(TreeNode* pTreeNode);
void LRRotate(TreeNode* pTreeNode);
void RLRotate(TreeNode* pTreeNode);

void Swap(TreeNode* pA, TreeNode* pB) {
	TreeNode tmp = *pA;

	*pA = *pB;
	*pB = tmp;
}