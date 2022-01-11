#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BinTree.h"


Tree* MakeBinTree(TreeNode Rootnode) {
	Tree* pReturn = NULL;
	pReturn = (Tree*)malloc(sizeof(Tree));
	if (pReturn != NULL) {
		pReturn->pRootNode = (TreeNode*)malloc(sizeof(TreeNode));
		if (pReturn->pRootNode != NULL) {
			*(pReturn->pRootNode) = Rootnode;
			pReturn->pRootNode->pLeftChild = NULL;
			pReturn->pRootNode->pRightChild = NULL;
			printf("%c ��Ʈ �Ҵ�Ϸ� MakeBinTree \n", pReturn->pRootNode->data);
		}
		else {
			printf("pReturn�� RootNode �� NULL�Դϴ�.\n");
		}
	}
	else {
		printf("pReturn �޸� �Ҵ翡�� MakeBinTree \n");
	}
	return pReturn;
}
TreeNode* GetRoot(Tree* pTree) {
	TreeNode* pReturn = NULL;
	if (pTree != NULL) {
		pReturn = pTree->pRootNode;
	}
	else {
		printf("pTree �޸� ���� GetRoot \n");
	}
	return pReturn;
}
TreeNode* InsertLeftChild(TreeNode* pParent, TreeNode node) {
	TreeNode* pNode = NULL;
	if (pParent != NULL) {
		if (pParent->pLeftChild == NULL) {
			pParent->pLeftChild = (TreeNode*)malloc(sizeof(TreeNode));
			if (pParent->pLeftChild != NULL) {
				*(pParent->pLeftChild) = node;
				pParent->pLeftChild->pLeftChild = NULL;
				pParent->pLeftChild->pRightChild = NULL;
				pNode = pParent->pLeftChild;
				printf("%c ���ԿϷ� InsertRightChild \n", pNode->data);
			}
		}
		else {
			pNode = pParent->pLeftChild;
			printf("�θ����� ���� �ڽĳ��� �̹� �����մϴ�.\n");
		}
	}
	else {
		printf("�θ��尡 NULL�Դϴ�. InsertLeftChild \n");
	}
	return pNode;
}
TreeNode* InsertRightChild(TreeNode* pParent, TreeNode node) {
	TreeNode* pNode = NULL;
	if (pParent != NULL) {
		if (pParent->pRightChild == NULL) {
			pParent->pRightChild = (TreeNode*)malloc(sizeof(TreeNode));
			if (pParent->pRightChild != NULL) {
				*(pParent->pRightChild) = node;
				pParent->pRightChild->pLeftChild = NULL;
				pParent->pRightChild->pRightChild = NULL;
				pNode = pParent->pRightChild;
				printf("%c ���ԿϷ� InsertRightChild \n", pNode->data);
			}
		}
		else {
			pNode = pParent->pRightChild;
			printf("�θ����� ������ �ڽĳ��� �̹� �����մϴ�.\n");
		}
	}
	else {
		printf("�θ��尡 NULL�Դϴ�. InsertLeftChild \n");
	}
	return pNode;
}
TreeNode* GetLeftChild(TreeNode* pNode) {
	TreeNode* pReturn = NULL;
	if (pNode != NULL) {
		if (pNode->pLeftChild != NULL) {
			pReturn = pNode->pLeftChild;
		}
		else {
			printf("�ش����� ���� �ڽĳ�尡 �����ϴ�. GetLeftChild \n");
		}
	}
	else {
		printf("�ش� ��尡 NULL�Դϴ�. GetLeftChild \n");
	}
	return pReturn;
}
TreeNode* GetRightChild(TreeNode* pNode) {
	TreeNode* pReturn = NULL;
	if (pNode != NULL) {
		if (pNode->pRightChild != NULL) {
			pReturn = pNode->pRightChild;
		}
		else {
			printf("�ش����� ������ �ڽĳ�尡 �����ϴ�. GetRightChild \n");
		}
	}
	else {
		printf("�ش� ��尡 NULL�Դϴ�. GetRightChild \n");
	}
	return pReturn;
}
void DeleteTree(Tree* pTree) {
	if (pTree != NULL) {
		DeleteTreeNode(pTree->pRootNode);
		free(pTree);
		printf("Ʈ������ �Ϸ�\n");
	}
}
void DeleteTreeNode(TreeNode* pNode) {
	if (pNode != NULL) {
		DeleteTreeNode(pNode->pLeftChild);
		DeleteTreeNode(pNode->pRightChild);
		free(pNode);
		printf("������ �Ϸ�\n");
	}
}