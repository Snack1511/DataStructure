#include<stdio.h>
#include<stdlib.h>
#include"BinTree.h"
#include"BinTreeTraversal.h"

void PreorderTraversalRecursiveTree(Tree* pTree) {
	if (pTree != NULL) {
		PreorderTraversalRecursiveTreeNode(pTree->pRootNode);
	}
	else {
		printf("������ȸ�� ������ �� �����ϴ�.\n");
	}
	printf("------- ������ȸ ���� --------\n");
}
void PreorderTraversalRecursiveTreeNode(TreeNode* pTreeNode) {
	if (pTreeNode != NULL) {
		printf("������ %c\n", pTreeNode->data);
		if (pTreeNode->pLeftChild != NULL) {
			printf("%c�� ���� �ڽĳ�带 ã�ҽ��ϴ�.\n", pTreeNode->data);
			PreorderTraversalRecursiveTreeNode(pTreeNode->pLeftChild);
		}
		else {
			printf("%c�� ���� �ڽĳ�尡 �����ϴ�.\n", pTreeNode->data);
		}
		if (pTreeNode->pRightChild != NULL) {
			printf("%c�� ������ �ڽĳ�带 ã�ҽ��ϴ�.\n", pTreeNode->data);
			PreorderTraversalRecursiveTreeNode(pTreeNode->pRightChild);
		}
		else {
			printf("%c�� ������ �ڽĳ�尡 �����ϴ�.\n", pTreeNode->data);
		}
	}
	else {
		printf("�ش� ��尡 NULL�Դϴ�.\n");
	}
	
}

void InorderTraversalRecursiveTree(Tree* pTree) {
	if (pTree != NULL) {
		InorderTraversalRecursiveTreeNode(pTree->pRootNode);
	}
	else {
		printf("������ȸ�� ������ �� �����ϴ�.\n");
	}
	printf("------- ������ȸ ���� --------\n");
}
void InorderTraversalRecursiveTreeNode(TreeNode* pTreeNode) {
	if (pTreeNode != NULL) {
		if (pTreeNode->pLeftChild != NULL) {
			printf("%c�� ���� �ڽĳ�带 ã�ҽ��ϴ�.\n", pTreeNode->data);
			InorderTraversalRecursiveTreeNode(pTreeNode->pLeftChild);
		}
		else {
			printf("%c�� ���� �ڽĳ�尡 �����ϴ�.\n", pTreeNode->data);
		}
		printf("������ %c\n", pTreeNode->data);
		if (pTreeNode->pRightChild != NULL) {
			printf("%c�� ������ �ڽĳ�带 ã�ҽ��ϴ�.\n", pTreeNode->data);
			InorderTraversalRecursiveTreeNode(pTreeNode->pRightChild);
		}
		else {
			printf("%c�� ������ �ڽĳ�尡 �����ϴ�.\n", pTreeNode->data);
		}
	}
	else {
		printf("�ش� ��尡 NULL�Դϴ�.\n");
	}
}

void PostorderTraversalRecursiveTree(Tree* pTree) {
	if (pTree != NULL) {
		PostorderTraversalRecursiveTreeNode(pTree->pRootNode);
	}
	else {
		printf("������ȸ�� ������ �� �����ϴ�.\n");
	}
	printf("------- ������ȸ ���� --------\n");
}
void PostorderTraversalRecursiveTreeNode(TreeNode* pTreeNode) {
	if (pTreeNode != NULL) {
		if (pTreeNode->pLeftChild != NULL) {
			printf("%c�� ���� �ڽĳ�带 ã�ҽ��ϴ�.\n", pTreeNode->data);
			PostorderTraversalRecursiveTreeNode(pTreeNode->pLeftChild);
		}
		else {
			printf("%c�� ���� �ڽĳ�尡 �����ϴ�.\n", pTreeNode->data);
		}
		if (pTreeNode->pRightChild != NULL) {
			printf("%c�� ������ �ڽĳ�带 ã�ҽ��ϴ�.\n", pTreeNode->data);
			PostorderTraversalRecursiveTreeNode(pTreeNode->pRightChild);
		}
		else {
			printf("%c�� ������ �ڽĳ�尡 �����ϴ�.\n", pTreeNode->data);
		}
		printf("������ %c\n", pTreeNode->data);
	}
	else {
		printf("�ش� ��尡 NULL�Դϴ�.\n");
	}
}