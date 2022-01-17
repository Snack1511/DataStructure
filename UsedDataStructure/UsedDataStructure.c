#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"UsedDataStructure.h"
Stack* createLNKStack() {
	Stack* pReturn = NULL;
	pReturn = (Stack*)malloc(sizeof(Stack));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(Stack));
		printf("메모리 할당 및 초기화 완료!\n");
	}
	else {
		printf("createLNKStack 메모리 할당 오류\n");
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
			printf("Push 성공!\n");
		}
		else {
			printf("pushLS 노드 메모리 오류\n");
		}

	}
	else {
		printf("pushLS 스택 메모리 오류\n");
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
			printf("popLS 언더플로우 오류\n");
		}
	}
	else {
		printf("popLS 스택 메모리 오류\n");
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
			printf("peekLS 언더플로우 오류\n");
		}
	}
	else {
		printf("peekLs 스택 메모리 오류\n");
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
		//	스택 구조체 자체에 대한 메모리 해제 이전에 
		//		저장된 노드들에 대해서 먼저 메모리 해제를 실시
		printf("저장된 메모리 해제 완료\n");
		free(pStack);
		printf("스택 메모리 해제 완료\n");
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
		printf("isStackEmpty 스택 메모리 오류\n");
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
		printf("메모리 할당 오류 : CreateQueue\n");
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
			printf("pNode메모리 할당 오류 : Enqueue\n");
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
			printf("언더플로우 오류 : Dequeue\n");
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