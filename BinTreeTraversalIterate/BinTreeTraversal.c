#include<stdio.h>
#include<stdlib.h>
#include"BinTree.h"
#include"BinTreeStack.h"
#include"BinTreeQueue.h"
#include"BinTreeTraversal.h"



void PreorderTraversalIterateTree(Tree* pTree) {
	if (pTree == NULL) {
		return;
	}
	Stack* pStack = CreateStack();
	if (pStack == NULL) {
		return;
	}
	TreeNode* pRoot = GetRoot(pTree);
	if (pRoot == NULL) {
		return;
	}

	TreeNode* pRight = NULL;
	TreeNode* pLeft = NULL;
	StackNode *pStackNode = NULL;
	StackNode PushNode = { 0, };
	PushNode.data = pRoot;
	Push(pStack, PushNode);

	while (1)
	{
		if (IsStackEmpty(pStack) == TRUE) {
			break;
		}
		else {
			pStackNode = Pop(pStack);//현재노드
			if (pStackNode != NULL) {
				pRoot = pStackNode->data;
				printf("현재 노드 %c\n", pRoot->data);

				pLeft = GetLeftChild(pRoot);//좌측노드
				pRight = GetRightChild(pRoot);//우측노드

				if (pRight != NULL) {//우측 푸시
					PushNode.data = pRight;
					Push(pStack, PushNode);
				}
				if (pLeft != NULL) {//좌측 푸시
					PushNode.data = pLeft;
					Push(pStack, PushNode);
				}
				free(pStackNode);
			}
		}
	}
	DeleteStack(pStack);
}

void InorderTraversalIterateTree(Tree* pTree) {
	if (pTree == NULL) {
		return;
	}
	Stack* pStack = CreateStack();
	if (pStack == NULL) {
		return;
	}
	TreeNode* pRoot = GetRoot(pTree);
	if (pRoot == NULL) {
		return;
	}

	TreeNode* pNode = NULL;
	StackNode* pStackNode = NULL;
	StackNode PushNode = { 0, };
	pNode = pRoot;

	while (1) {
		for (; pNode != NULL; pNode = GetLeftChild(pNode)) {
			PushNode.data = pNode;
			Push(pStack, PushNode);
		}//왼쪽 서브트리 푸시
		if (IsStackEmpty(pStack) == TRUE) {
			break;
		}
		else {
			pStackNode = Pop(pStack);
			if (pStackNode != NULL) {
				pNode = pStackNode->data;
				printf("현재 노드 %c\n", pNode->data);
				pNode = GetRightChild(pNode);
				free(pStackNode);
			}
		}
	}
	DeleteStack(pStack);
}

void PostorderTraversalIterateTree(Tree* pTree) {
	if (pTree == NULL) {
		return;
	}
	Stack* pStack = CreateStack();
	if (pStack == NULL) {
		return;
	}
	TreeNode* pRoot = GetRoot(pTree);
	if (pRoot == NULL) {
		return;
	}

	TreeNode* pNode = NULL;
	TreeNode* pRight = NULL;
	StackNode* pStackNode = NULL;
	StackNode PushNode = { 0, };
	pNode = pRoot;

	while (1) {
		for (; pNode != NULL && pNode->Visit == FALSE; pNode = GetLeftChild(pNode)) {
			PushNode.data = pNode;
			Push(pStack, PushNode);
		}//왼쪽 서브트리 푸시
		if (IsStackEmpty(pStack) == TRUE) {
			break;
		}
		else {

			pStackNode = Pop(pStack);
			if (pStackNode != NULL) {
				pNode = pStackNode->data;
				if (GetRightChild(pNode) != NULL&& GetRightChild(pNode)->Visit == FALSE) {
					PushNode.data = pNode;
					Push(pStack, PushNode);
					pNode = GetRightChild(pNode);
				}
				else {
					if (pNode->Visit == FALSE) {
						printf("현재 노드 %c\n", pNode->data);
						pNode->Visit = TRUE;
						pNode = GetRightChild(pNode);
					}
				}
				free(pStackNode);
			}
			

		}
	}
	DeleteStack(pStack);
}

void LevelTraversalIterateTree(Tree* pTree) {
	Queue* pQueue = CreateQueue();
	QueueNode* pQueueNode = NULL;
	QueueNode InsertNode = { 0, };
	Tree* pSubTree = NULL;
	TreeNode* pRoot = NULL, * pLeft = NULL, * pRight = NULL;
	if (pTree == NULL) {
		return;
	}
	if (pQueue == NULL) {
		return;
	}
	pRoot = GetRoot(pTree);
	if (pRoot == NULL) {
		return;
	}

	InsertNode.data = pRoot;
	Enqueue(pQueue, InsertNode);

	while (1) {
		if (IsQueueEmpty(pQueue) == TRUE) {
			break;
		}
		else {
			pQueueNode = Dequeue(pQueue);
			if (pQueueNode != NULL) {
				pRoot = pQueueNode->data;
				if (pRoot != NULL) {
					printf("현재 노드 %c\n", pRoot->data);
				}
				pLeft = GetLeftChild(pRoot);
				pRight = GetRightChild(pRoot);

				if (pLeft != NULL) {
					InsertNode.data = pLeft;
					Enqueue(pQueue, InsertNode);
				}
				if (pRight != NULL) {
					InsertNode.data = pRight;
					Enqueue(pQueue, InsertNode);
				}

				free(pQueueNode);
			}
		}
	}
	DeleteQueue(pQueue);
}