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
			pStackNode = Pop(pStack);//������
			if (pStackNode != NULL) {
				pRoot = pStackNode->data;
				printf("���� ��� %c\n", pRoot->data);

				pLeft = GetLeftChild(pRoot);//�������
				pRight = GetRightChild(pRoot);//�������

				if (pRight != NULL) {//���� Ǫ��
					PushNode.data = pRight;
					Push(pStack, PushNode);
				}
				if (pLeft != NULL) {//���� Ǫ��
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
		}//���� ����Ʈ�� Ǫ��
		if (IsStackEmpty(pStack) == TRUE) {
			break;
		}
		else {
			pStackNode = Pop(pStack);
			if (pStackNode != NULL) {
				pNode = pStackNode->data;
				printf("���� ��� %c\n", pNode->data);
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
		}//���� ����Ʈ�� Ǫ��
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
						printf("���� ��� %c\n", pNode->data);
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
					printf("���� ��� %c\n", pRoot->data);
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