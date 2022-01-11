#include<stdio.h>
#include<stdlib.h>
#include"BinTree.h"
#include"BinTreeStack.h"
#include"BinTreeQueue.h"
#include"MyBinTreeTraversal.h"

void MyPreorderTraversalIterateTree(Tree* pTree) {
	if (pTree != NULL) {
		PreorderTraversalIterateTreeNode(pTree->pRootNode);
	}
	else {
		printf("������ȸ�� ������ �� �����ϴ�.\n");
	}
	printf("------- ������ȸ ���� --------\n");
}
void PreorderTraversalIterateTreeNode(TreeNode* pTreeNode) {
	Stack* pCheckNodeStack = CreateStack();
	StackNode CheckNode = { 0, };
	TreeNode* pNextNode = pTreeNode;
	

	while (pNextNode->Visit == FALSE || IsStackEmpty(pCheckNodeStack) == FALSE) {
		if (pNextNode->Visit == FALSE) {
			printf("������ %c\n", pNextNode->data);
			pNextNode->Visit = TRUE;
			CheckNode.data = pNextNode;
			Push(pCheckNodeStack, CheckNode);
		}
		else {
			Pop(pCheckNodeStack);
		}//�湮�� ���ÿ��� �湮�������

		if (pNextNode->pLeftChild != NULL && pNextNode->pLeftChild->Visit == FALSE) {
			pNextNode = pNextNode->pLeftChild;
		}//����Ž��
		else if (pNextNode->pRightChild != NULL && pNextNode->pRightChild->Visit == FALSE) {
			pNextNode = pNextNode->pRightChild;
		}//����Ž��
		else {
			if (IsStackEmpty(pCheckNodeStack) == FALSE) {
				pNextNode = PeekStack(pCheckNodeStack).data;
			}
		}//������� ��ȯ

	}
	DeleteStack(pCheckNodeStack);
}

void MyInorderTraversalIterateTree(Tree* pTree) {
	if (pTree != NULL) {
		InorderTraversalIterateTreeNode(pTree->pRootNode);
	}
	else {
		printf("������ȸ�� ������ �� �����ϴ�.\n");
	}
	printf("------- ������ȸ ���� --------\n");
}
void InorderTraversalIterateTreeNode(TreeNode* pTreeNode) {
	Stack* pCheckNodeStack = CreateStack();
	StackNode CheckNode = { 0, };
	TreeNode* pNextNode = pTreeNode;

	while (pNextNode->Visit == FALSE || IsStackEmpty(pCheckNodeStack) == FALSE) {//����Ž��
		if (pNextNode->pLeftChild != NULL && pNextNode->pLeftChild->Visit == FALSE) {
			CheckNode.data = pNextNode;
			Push(pCheckNodeStack, CheckNode);
			pNextNode = pNextNode->pLeftChild;
		}
		else {
			if (pNextNode->Visit == FALSE) {
				printf("������ %c\n", pNextNode->data);
				pNextNode->Visit = TRUE;
				//������ ���
				if (pNextNode->pRightChild != NULL && pNextNode->pRightChild->Visit == FALSE) {
					pNextNode = pNextNode->pRightChild;
				}//������� Ž��
			}
			else {
				if (IsStackEmpty(pCheckNodeStack) == FALSE) {
					pNextNode = Pop(pCheckNodeStack)->data;
				}
			}//�ܸ� ����̰ų� �湮�� ������ ���

		}

	}
	DeleteStack(pCheckNodeStack);

	
}

void MyPostorderTraversalIterateTree(Tree* pTree) {
	if (pTree != NULL) {
		PostorderTraversalIterateTreeNode(pTree->pRootNode);
	}
	else {
		printf("������ȸ�� ������ �� �����ϴ�.\n");
	}
	printf("------- ������ȸ ���� --------\n");
}
void PostorderTraversalIterateTreeNode(TreeNode* pTreeNode) {
	Stack* pCheckNodeStack = CreateStack();
	StackNode CheckNode = { 0, };
	TreeNode* pNextNode = pTreeNode;

	while (pNextNode->Visit == FALSE || IsStackEmpty(pCheckNodeStack) == FALSE) {
		if (pNextNode->pLeftChild != NULL && pNextNode->pLeftChild->Visit == FALSE) {
			CheckNode.data = pNextNode;
			Push(pCheckNodeStack, CheckNode);
			pNextNode = pNextNode->pLeftChild;
		}//����
		else {
			if (pNextNode->pRightChild != NULL && pNextNode->pRightChild->Visit == FALSE) {
				CheckNode.data = pNextNode;
				Push(pCheckNodeStack, CheckNode);
				pNextNode = pNextNode->pRightChild;
			}//����
			else {
				printf("������ %c\n", pNextNode->data);
				pNextNode->Visit = TRUE;
				if (IsStackEmpty(pCheckNodeStack) == FALSE) {
					pNextNode = Pop(pCheckNodeStack)->data;
				}
			}//����
		}
	}
	DeleteStack(pCheckNodeStack);
}



void MyLevelTraversalIterateTree(Tree* pTree) {
	if (pTree != NULL) {
		LevelTraversalIterateTreeNode(pTree->pRootNode);
	}
	else {
		printf("������ȸ�� ������ �� �����ϴ�.\n");
	}
	printf("------- ������ȸ ���� --------\n");
}
void LevelTraversalIterateTreeNode(TreeNode* pTreeNode) {
	Queue* pCheckQueue = CreateQueue();
	QueueNode CheckNode = { 0, };
	TreeNode* pNextNode = pTreeNode;

	CheckNode.data = pNextNode;
	Enqueue(pCheckQueue, CheckNode);

	while (isEmpty(pCheckQueue) == FALSE) {
		pNextNode = Dequeue(pCheckQueue)->data;
		if (pNextNode->pLeftChild != NULL) {
			CheckNode.data = pNextNode->pLeftChild;
			Enqueue(pCheckQueue, CheckNode);
		}
		if (pNextNode->pRightChild != NULL) {
			CheckNode.data = pNextNode->pRightChild;
			Enqueue(pCheckQueue, CheckNode);
		}
		printf("������ %c\n", pNextNode->data);
	}
	DeleteQueue(pCheckQueue);
}

void ResetVisitInformation(Tree* pTree) {
	Stack* pCheckNodeStack = CreateStack();
	StackNode CheckNode = { 0, };
	TreeNode* pNextNode = pTree->pRootNode;

	while (pNextNode->Visit == TRUE || IsStackEmpty(pCheckNodeStack) == FALSE) {//����Ž��
		if (pNextNode->pLeftChild != NULL && pNextNode->pLeftChild->Visit == TRUE) {
			CheckNode.data = pNextNode;
			Push(pCheckNodeStack, CheckNode);
			pNextNode = pNextNode->pLeftChild;
		}
		else {
			if (pNextNode->Visit == TRUE) {
				pNextNode->Visit = FALSE;
				//������ ���
				if (pNextNode->pRightChild != NULL && pNextNode->pRightChild->Visit == TRUE) {
					pNextNode = pNextNode->pRightChild;
				}//������� Ž��
			}
			else {
				if (IsStackEmpty(pCheckNodeStack) == FALSE) {
					pNextNode = Pop(pCheckNodeStack)->data;
				}
			}//�ܸ� ����̰ų� �湮�� ������ ���

		}

	}
}