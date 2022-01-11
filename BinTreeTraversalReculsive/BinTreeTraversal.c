#include<stdio.h>
#include<stdlib.h>
#include"BinTree.h"
#include"BinTreeTraversal.h"

void PreorderTraversalRecursiveTree(Tree* pTree) {
	if (pTree != NULL) {
		PreorderTraversalRecursiveTreeNode(pTree->pRootNode);
	}
	else {
		printf("전위순회를 실행할 수 없습니다.\n");
	}
	printf("------- 전위순회 종료 --------\n");
}
void PreorderTraversalRecursiveTreeNode(TreeNode* pTreeNode) {
	if (pTreeNode != NULL) {
		printf("현재노드 %c\n", pTreeNode->data);
		if (pTreeNode->pLeftChild != NULL) {
			printf("%c의 왼쪽 자식노드를 찾았습니다.\n", pTreeNode->data);
			PreorderTraversalRecursiveTreeNode(pTreeNode->pLeftChild);
		}
		else {
			printf("%c의 왼쪽 자식노드가 없습니다.\n", pTreeNode->data);
		}
		if (pTreeNode->pRightChild != NULL) {
			printf("%c의 오른쪽 자식노드를 찾았습니다.\n", pTreeNode->data);
			PreorderTraversalRecursiveTreeNode(pTreeNode->pRightChild);
		}
		else {
			printf("%c의 오른쪽 자식노드가 없습니다.\n", pTreeNode->data);
		}
	}
	else {
		printf("해당 노드가 NULL입니다.\n");
	}
	
}

void InorderTraversalRecursiveTree(Tree* pTree) {
	if (pTree != NULL) {
		InorderTraversalRecursiveTreeNode(pTree->pRootNode);
	}
	else {
		printf("중위순회를 실행할 수 없습니다.\n");
	}
	printf("------- 중위순회 종료 --------\n");
}
void InorderTraversalRecursiveTreeNode(TreeNode* pTreeNode) {
	if (pTreeNode != NULL) {
		if (pTreeNode->pLeftChild != NULL) {
			printf("%c의 왼쪽 자식노드를 찾았습니다.\n", pTreeNode->data);
			InorderTraversalRecursiveTreeNode(pTreeNode->pLeftChild);
		}
		else {
			printf("%c의 왼쪽 자식노드가 없습니다.\n", pTreeNode->data);
		}
		printf("현재노드 %c\n", pTreeNode->data);
		if (pTreeNode->pRightChild != NULL) {
			printf("%c의 오른쪽 자식노드를 찾았습니다.\n", pTreeNode->data);
			InorderTraversalRecursiveTreeNode(pTreeNode->pRightChild);
		}
		else {
			printf("%c의 오른쪽 자식노드가 없습니다.\n", pTreeNode->data);
		}
	}
	else {
		printf("해당 노드가 NULL입니다.\n");
	}
}

void PostorderTraversalRecursiveTree(Tree* pTree) {
	if (pTree != NULL) {
		PostorderTraversalRecursiveTreeNode(pTree->pRootNode);
	}
	else {
		printf("후위순회를 실행할 수 없습니다.\n");
	}
	printf("------- 후위순회 종료 --------\n");
}
void PostorderTraversalRecursiveTreeNode(TreeNode* pTreeNode) {
	if (pTreeNode != NULL) {
		if (pTreeNode->pLeftChild != NULL) {
			printf("%c의 왼쪽 자식노드를 찾았습니다.\n", pTreeNode->data);
			PostorderTraversalRecursiveTreeNode(pTreeNode->pLeftChild);
		}
		else {
			printf("%c의 왼쪽 자식노드가 없습니다.\n", pTreeNode->data);
		}
		if (pTreeNode->pRightChild != NULL) {
			printf("%c의 오른쪽 자식노드를 찾았습니다.\n", pTreeNode->data);
			PostorderTraversalRecursiveTreeNode(pTreeNode->pRightChild);
		}
		else {
			printf("%c의 오른쪽 자식노드가 없습니다.\n", pTreeNode->data);
		}
		printf("현재노드 %c\n", pTreeNode->data);
	}
	else {
		printf("해당 노드가 NULL입니다.\n");
	}
}