#include<stdio.h>
#include<stdlib.h>
#include"linkedqueue.h"

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
			/********* My Logic *************
			pPrevNode = pQueue->pFront;
			while(pPrevNode->pLink != NULL){
				pPrevNode = pPrevNode->pLink;
			}
			pPrevNode->pLink = pNode;
			pQueue->pRear = pNode;
			*********************************/
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
			/********* My Logic *************
			pNode = pQueue->pFront->pLink;
			pQueue->pFront->pLink = pNode->pLink;
			*********************************/
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
QueueNode* Peek(Queue* pQueue) {
	int ret = FALSE;
	QueueNode* pNode = NULL;
	if (pQueue != NULL) {
		/********* My Logic *************
		pNode = pQueue->pFront->pLink;
		*********************************/
		pNode = pQueue->pFront;
	}
	return pNode;
}
void DeleteQueue(Queue* pQueue) {
	/********* My Logic *************
	QueueNode* pNode = NULL;
	while (isEmpty(pQueue) == FALSE) {
		pNode = Dequeue(pQueue);
		free(pNode);
	}
	pQueue->pFront = NULL;
	pQueue->pRear = NULL;
	pQueue->Head.pLink = NULL;
	pQueue->currentLength = 0;
	*********************************/
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
//int isFull(Queue* pQueue);
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