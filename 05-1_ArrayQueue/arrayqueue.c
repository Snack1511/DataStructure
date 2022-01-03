#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"arrayqueue.h"

/*
 ť����
 �Ű����� int maxLength
*/
Queue* CreateQueue(int maxLength) {
	Queue* rQueue = NULL;
	rQueue = (Queue*)malloc(sizeof(Queue));			//��ȯ�� ť�� ������ �Ҵ�
	if (rQueue != NULL) {
		memset(rQueue, 0, sizeof(Queue));
		if (maxLength > 0) {
			/************************************/
			rQueue->maxLength = maxLength;
			rQueue->front = -1;
			rQueue->rear = -1;

			rQueue->pElements = (QueueNode*)malloc(sizeof(QueueNode) * maxLength);	//�迭 �ִ� ũ�⸸ŭ �޸� �Ҵ�
			if (rQueue->pElements != NULL) {
				memset(rQueue->pElements, 0, sizeof(QueueNode) * maxLength);
			}
			else {
				printf("element �޸� �Ҵ� ����:CreateQueue\n");
				rQueue->pElements = NULL;
				free(rQueue->pElements);
				rQueue = NULL;
			}
			/************** �ʱ�ȭ *************/
		}
		else {
			printf("�ִ�ũ��� 0���� Ŀ���մϴ�.:CreateQueue\n");
			rQueue = NULL;
		}
	}
	else {
		printf("rQueue �޸� �Ҵ� ����:CreateQueue\n");

	}
	return rQueue;
}
/*
��ť
�Ű����� Queue* pQueue, QueueNode element
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
			printf("�����÷ο� ����:Enqueue \n");
		}
	}
	else {
		printf("pQueue �޸� ����:Enqueue\n");
	}
	return ret;
}
/*
��ť
�Ű����� : Queue* pQueue
���ο� ��带 ����(�޸� �Ҵ�)�� �� �����͸� ����
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
			printf("����÷ο� ����:Dequeue \n");
		}
	}
	else {
		printf("pQueue �޸� ����:Dequeue\n");
	}
	return pNode;
}
/*
��ũ
�Ű����� : Queue* pQueue
������忡 ���� �����͸� ����
*/
QueueNode* Peek(Queue* pQueue) {
	QueueNode* pNode = NULL;
	if (pQueue != NULL) {
		if (isEmpty(pQueue) == FALSE) {
			pNode = &pQueue->pElements[pQueue->front+1];
			
		}
		else {
			printf("����÷ο� ����:Dequeue \n");
		}
	}
	else {
		printf("pQueue �޸� ����:Dequeue\n");
	}
	return pNode;
}
int isFull(Queue* pQueue) {
	if (pQueue->currentLength >= pQueue->maxLength || pQueue->rear == pQueue->maxLength - 1) {
		//������ ��ġ�� ���� ���迭�� ���� �������� ������ ť�� ������ ���
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