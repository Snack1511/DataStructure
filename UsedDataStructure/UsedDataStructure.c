#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"UsedDataStructure.h"
Stack* createLNKStack() {
	Stack* pReturn = NULL;
	pReturn = (Stack*)malloc(sizeof(Stack));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(Stack));
		printf("�޸� �Ҵ� �� �ʱ�ȭ �Ϸ�!\n");
	}
	else {
		printf("createLNKStack �޸� �Ҵ� ����\n");
	}
	return pReturn;
}
int Push(Stack* pStack, StackNode node) {
	int ret = FALSE;
	StackNode* pNewNode;
	if (pStack != NULL) {
		pNewNode = (StackNode*)malloc(sizeof(StackNode));
		if (pNewNode != NULL) {
			*pNewNode = node;
			pNewNode->pLink = pStack->pTop;
			pStack->pTop = pNewNode;
			pStack->currentLength++;
			ret = TRUE;
			printf("Push ����!\n");
		}
		else {
			printf("pushLS ��� �޸� ����\n");
		}

	}
	else {
		printf("pushLS ���� �޸� ����\n");
	}
}
StackNode* Pop(Stack* pStack) {
	StackNode* pReturnNode = NULL;
	if (pStack != NULL) {
		if (IsStackEmpty(pStack) == FALSE) {
			pReturnNode = (StackNode*)malloc(sizeof(StackNode));
			pReturnNode = pStack->pTop;
			pStack->pTop = pReturnNode->pLink;
			pReturnNode->pLink = NULL;
			pStack->currentLength--;
		}
		else {
			printf("popLS ����÷ο� ����\n");
		}
	}
	else {
		printf("popLS ���� �޸� ����\n");
	}
	return pReturnNode;
}
StackNode PeekStack(Stack* pStack) {
	StackNode ReturnNode = { 0, };
	if (pStack != NULL) {
		if (IsStackEmpty(pStack) == FALSE) {
			ReturnNode = *(pStack->pTop);
		}
		else {
			printf("peekLS ����÷ο� ����\n");
		}
	}
	else {
		printf("peekLs ���� �޸� ����\n");
	}
	return ReturnNode;
}
void deleteLNKStack(Stack* pStack) {
	StackNode* pNode = NULL;
	StackNode* pDelNode = NULL;

	if (pStack != NULL) {
		pNode = pStack->pTop;
		while (pNode != NULL) {
			pDelNode = pNode;
			pNode = pNode->pLink;
			free(pDelNode);
		}
		//	���� ����ü ��ü�� ���� �޸� ���� ������ 
		//		����� ���鿡 ���ؼ� ���� �޸� ������ �ǽ�
		printf("����� �޸� ���� �Ϸ�\n");
		free(pStack);
		printf("���� �޸� ���� �Ϸ�\n");
	}
}
int IsStackEmpty(Stack* pStack) {
	int ret = FALSE;
	if (pStack != NULL) {
		if (pStack->currentLength < 0) {
			ret = TRUE;
		}
	}
	else {
		printf("isStackEmpty ���� �޸� ����\n");
	}
	return ret;
}

Queue* CreateQueue() {
	Queue* pReturn = NULL;
	pReturn = (Queue*)malloc(sizeof(Queue));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(Queue));
		pReturn->pFront = &pReturn->Head;
		pReturn->pRear = &pReturn->Head;
	}
	else {
		printf("�޸� �Ҵ� ���� : CreateQueue\n");
	}
	return pReturn;
}
int Enqueue(Queue* pQueue, QueueNode element) {
	int ret = FALSE;

	if (pQueue != NULL) {
		QueueNode* pNode = NULL;
		QueueNode* pPrevNode = NULL;
		pNode = (QueueNode*)malloc(sizeof(QueueNode));
		if (pNode != NULL) {
			*pNode = element;
			pNode->pLink = NULL;
			if (isEmpty(pQueue) == TRUE) {
				pQueue->pFront = pNode;
				pQueue->pRear = pNode;
			}
			else {
				pQueue->pRear->pLink = pNode;
				pQueue->pRear = pNode;
			}
			pQueue->currentLength++;
			ret = TRUE;
		}
		else {
			printf("pNode�޸� �Ҵ� ���� : Enqueue\n");
		}
	}
	return ret;
}
QueueNode* Dequeue(Queue* pQueue) {
	int ret = FALSE;
	QueueNode* pNode = NULL;
	if (pQueue != NULL) {
		if (isEmpty(pQueue) == FALSE) {
			pNode = pQueue->pFront;
			pQueue->pFront = pQueue->pFront->pLink;
			pNode->pLink = NULL;
			pQueue->currentLength--;
		}
		else {
			printf("����÷ο� ���� : Dequeue\n");
			pQueue->pRear = NULL;
		}
	}
	return pNode;
}
QueueNode* PeekQueue(Queue* pQueue) {
	int ret = FALSE;
	QueueNode* pNode = NULL;
	if (pQueue != NULL) {
		pNode = pQueue->pFront;
	}
	return pNode;
}
void DeleteQueue(Queue* pQueue) {
	QueueNode* pNode = NULL;
	QueueNode* pDelNode = NULL;

	if (pQueue != NULL) {
		pNode = pQueue->pFront;
		while (pNode != NULL) {
			pDelNode = pNode;
			pNode = pNode->pLink;

			free(pDelNode);
		}
		free(pQueue);
	}

}
int isEmpty(Queue* pQueue) {
	if (pQueue != NULL) {
		if (pQueue->currentLength <= 0) {
			return TRUE;
		}
		else {
			return FALSE;
		}
	}
}