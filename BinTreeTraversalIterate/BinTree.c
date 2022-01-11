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
			printf("%c 루트 할당완료 MakeBinTree \n", pReturn->pRootNode->data);
		}
		else {
			printf("pReturn의 RootNode 가 NULL입니다.\n");
		}
	}
	else {
		printf("pReturn 메모리 할당에러 MakeBinTree \n");
	}
	return pReturn;
}
TreeNode* GetRoot(Tree* pTree) {
	TreeNode* pReturn = NULL;
	if (pTree != NULL) {
		pReturn = pTree->pRootNode;
	}
	else {
		printf("pTree 메모리 오류 GetRoot \n");
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
				printf("%c 삽입완료 InsertRightChild \n", pNode->data);
			}
		}
		else {
			pNode = pParent->pLeftChild;
			printf("부모노드의 왼쪽 자식노드는 이미 존재합니다.\n");
		}
	}
	else {
		printf("부모노드가 NULL입니다. InsertLeftChild \n");
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
				printf("%c 삽입완료 InsertRightChild \n", pNode->data);
			}
		}
		else {
			pNode = pParent->pRightChild;
			printf("부모노드의 오른쪽 자식노드는 이미 존재합니다.\n");
		}
	}
	else {
		printf("부모노드가 NULL입니다. InsertLeftChild \n");
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
			printf("해당노드의 왼쪽 자식노드가 없습니다. GetLeftChild \n");
		}
	}
	else {
		printf("해당 노드가 NULL입니다. GetLeftChild \n");
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
			printf("해당노드의 오른쪽 자식노드가 없습니다. GetRightChild \n");
		}
	}
	else {
		printf("해당 노드가 NULL입니다. GetRightChild \n");
	}
	return pReturn;
}
void DeleteTree(Tree* pTree) {
	if (pTree != NULL) {
		DeleteTreeNode(pTree->pRootNode);
		free(pTree);
		printf("트리삭제 완료\n");
	}
}
void DeleteTreeNode(TreeNode* pNode) {
	if (pNode != NULL) {
		DeleteTreeNode(pNode->pLeftChild);
		DeleteTreeNode(pNode->pRightChild);
		free(pNode);
		printf("노드삭제 완료\n");
	}
}