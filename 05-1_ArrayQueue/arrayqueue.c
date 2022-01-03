#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"arrayqueue.h"

/*
 큐생성
 매개변수 int maxLength
*/
Queue* CreateQueue(int maxLength) {
	Queue* rQueue = NULL;
	rQueue = (Queue*)malloc(sizeof(Queue));			//반환할 큐의 포인터 할당
	if (rQueue != NULL) {
		memset(rQueue, 0, sizeof(Queue));
		if (maxLength > 0) {
			/************************************/
			rQueue->maxLength = maxLength;
			rQueue->front = -1;
			rQueue->rear = -1;

			rQueue->pElements = (QueueNode*)malloc(sizeof(QueueNode) * maxLength);	//배열 최대 크기만큼 메모리 할당
			if (rQueue->pElements != NULL) {
				memset(rQueue->pElements, 0, sizeof(QueueNode) * maxLength);
			}
			else {
				printf("element 메모리 할당 오류:CreateQueue\n");
				rQueue->pElements = NULL;
				free(rQueue->pElements);
				rQueue = NULL;
			}
			/************** 초기화 *************/
		}
		else {
			printf("최대크기는 0보다 커야합니다.:CreateQueue\n");
			rQueue = NULL;
		}
	}
	else {
		printf("rQueue 메모리 할당 오류:CreateQueue\n");

	}
	return rQueue;
}
/*
인큐
매개변수 Queue* pQueue, QueueNode element
*/
int Enqueue(Queue* pQueue, QueueNode element) {
	int ret = FALSE;
	if (pQueue != NULL) {
		if (isFull(pQueue) == FALSE) {
			pQueue->rear++;
			pQueue->pElements[pQueue->rear] = element;
			pQueue->currentLength++;
			ret = TRUE;
		}
		else {
			printf("오버플로우 오류:Enqueue \n");
		}
	}
	else {
		printf("pQueue 메모리 오류:Enqueue\n");
	}
	return ret;
}
/*
디큐
매개변수 : Queue* pQueue
새로운 노드를 생성(메모리 할당)해 그 포인터를 전달
*/
QueueNode* Dequeue(Queue* pQueue) {
	QueueNode* pNode = NULL;
	if (pQueue != NULL) {
		if (isEmpty(pQueue) == FALSE) {
			pNode = (QueueNode*)malloc(sizeof(QueueNode));
			if (pNode != NULL) {
				pQueue->front++;
				pNode->data = pQueue->pElements[pQueue->front].data;
				pQueue->currentLength--;
			}
		}
		else {
			printf("언더플로우 오류:Dequeue \n");
		}
	}
	else {
		printf("pQueue 메모리 오류:Dequeue\n");
	}
	return pNode;
}
/*
피크
매개변수 : Queue* pQueue
기존노드에 대한 포인터만 전달
*/
QueueNode* Peek(Queue* pQueue) {
	QueueNode* pNode = NULL;
	if (pQueue != NULL) {
		if (isEmpty(pQueue) == FALSE) {
			pNode = &pQueue->pElements[pQueue->front+1];
			
		}
		else {
			printf("언더플로우 오류:Dequeue \n");
		}
	}
	else {
		printf("pQueue 메모리 오류:Dequeue\n");
	}
	return pNode;
}
int isFull(Queue* pQueue) {
	if (pQueue->currentLength >= pQueue->maxLength || pQueue->rear == pQueue->maxLength - 1) {
		//리어의 위치가 현재 노드배열의 제일 마지막인 경우또한 큐가 가득찬 경우
		return TRUE;
	}
	else {
		return FALSE;
	}
}
int isEmpty(Queue* pQueue) {
	if (pQueue->currentLength <= 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
void DeleteQueue(Queue* pQueue) {
	if (pQueue != NULL) {
		if (isEmpty(pQueue) == FALSE) {
			memset(pQueue->pElements, NULL, sizeof(QueueNode) * pQueue->maxLength);
		}
		pQueue->pElements = NULL;
		free(pQueue->pElements);
	}
	pQueue = NULL;

}