#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BinSearchTree.h"

Tree* CreateTree() {
	Tree* pReturn = NULL;
	pReturn = (Tree*)malloc(sizeof(Tree));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(Tree));
	}
	return pReturn;
}
int InsertNode(Tree* pTree, TreeNode node) {
	int ret = FALSE;
	TreeNode *pNode = NULL, *pParent = NULL;

	pParent = pTree->pRoot;

	while (pParent != NULL) {
		if (pParent->key == node.key) {
			printf("%d�� Ű���� �����մϴ�.\n", node.key);
			return ret;
		}
		else {
			if (pParent->key > node.key) {
				if (pParent->pLeft != NULL) {
					pParent = pParent->pLeft;
				}
				else {
					break;
				}
			}
			else {
				if (pParent->pRight != NULL) {
					pParent = pParent->pRight;
				}
				else {
					break;
				}
			}
		}

		
	}
	pNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (pNode != NULL) {
		*pNode = node;
	}
	if (pParent == NULL) {
		pTree->pRoot = pNode;
		ret = TRUE;
	}
	else {
		if (pParent->key > node.key) {
			pParent->pLeft = pNode;
		}
		else {
			pParent->pRight = pNode;
		}
		ret = TRUE;
	}
	return ret;
}
int DeleteNode(Tree* pTree, int key) {
	int ret = FALSE;

	TreeNode* pParent = NULL, *pDelete = NULL;
	pDelete = pTree->pRoot;
	if (pDelete != NULL) {
		while (TRUE) {
			if (pDelete->key == key) {
				break;
			}
			else {
				if (pDelete->key < key) {
					if (pDelete->pRight != NULL) {
						pParent = pDelete;
						pDelete = pDelete->pRight;
					}
					else {
						printf("�ش� Ű�� ã�� �� �����ϴ�.\n");
						return ret;
					}
				}
				else {
					if (pDelete->pLeft != NULL) {
						pParent = pDelete;
						pDelete = pDelete->pLeft;
					}
					else {
						printf("�ش� Ű�� ã�� �� �����ϴ�.\n");
						return ret;
					}
				}
			}
		}

		
		TreeNode* pSwap = NULL, *pSwapParent= NULL;
		pSwap = pDelete->pLeft;
		while (pSwap->pRight != NULL) {
			pSwapParent = pSwap;
			pSwap = pSwap->pRight;
		}
		if (pSwapParent != NULL) {
			pSwapParent->pRight = pSwap->pLeft;
		}
		if (pParent != NULL) {
			if (pParent->pLeft == pDelete) {
				pParent->pLeft = pSwap;
			}
			else {
				pParent->pRight = pSwap;

			}
		}
		else {
			pTree->pRoot = pSwap;
		}
		
		pSwap->pLeft = pDelete->pLeft;
		pSwap->pRight = pDelete->pRight;

		pDelete->pLeft = NULL;
		pDelete->pRight = NULL;

		
	}
	else {
		printf("Ʈ���� ����ֽ��ϴ�.\n");
	}
	free(pDelete);

	return ret;
}

TreeNode* SearchTree(Tree* pTree, int key) {
	TreeNode* pReturn = NULL;
	if (pTree != NULL) {
		pReturn = pTree->pRoot;

		while (pReturn != NULL) {
			if (pReturn->key == key) {
				break;
			}
			else {
				if (pReturn->key > key) {
					pReturn = pReturn->pLeft;
				}
				else {
					pReturn = pReturn->pRight;
				}
			}
		}
	}
	return pReturn;
}

void DeleteTree(Tree* pTree) {
	if (pTree != NULL) {
		DeleteTreeInternal(pTree->pRoot);
	}
	free(pTree);
	printf("Ʈ������ �Ϸ�\n");
}
void DeleteTreeInternal(TreeNode* pNode) {
	if (pNode != NULL) {
		DeleteTreeInternal(pNode->pLeft);
		DeleteTreeInternal(pNode->pRight);
	}
	free(pNode);
	printf("������ �Ϸ�\n");
}