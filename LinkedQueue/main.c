#include<stdio.h>
#include<stdlib.h>
#include"linkedqueue.h"

void displayQueue(Queue* pQueue) {
	/********* My Logic *************
	if (pQueue != NULL) {
		printf("현재 노드 개수 : %d\n", pQueue->currentLength);
		QueueNode* pNode = NULL;
		pNode = &pQueue->Head;
		while (pNode->pLink != NULL) {
			pNode = pNode->pLink;
			printf("%c    ", pNode->data);	//변경
		}
		printf("\n");
	}
	*********************************/
	QueueNode* pNode = NULL;
	int i = 0;
	if (pQueue != NULL) {
		printf("현재 노드개수 : %d\n", pQueue->currentLength);
		pNode = pQueue->pFront;
		while (pNode != NULL) {
			printf("%d %c     ", i, pNode->data);
			i++;
			pNode = pNode->pLink;
		}
		printf("\n");
	}
}

void displayCharData(QueueNode* pNode) {
	if (pNode != NULL) {
		printf("Dequeue Value - [%c]\n", pNode->data);
	}
	else {
		printf("pNode 메모리 오류:main\n");
	}
}

int EnqueueChar(Queue* pQueue, char data) {
	QueueNode node = { 0, };
	node.data = data;
	return Enqueue(pQueue, node);
}

int main(int argc, char* argv[]) {
	Queue* pQueue = NULL;
	QueueNode* pNode = NULL;

	pQueue = CreateQueue(4);

	if (pQueue != NULL) {
		EnqueueChar(pQueue, 'A');
		EnqueueChar(pQueue, 'B');
		EnqueueChar(pQueue, 'C');
		EnqueueChar(pQueue, 'D');
		EnqueueChar(pQueue, 'E');
		displayQueue(pQueue);
		
		pNode = Dequeue(pQueue);
		displayCharData(pNode);
		free(pNode);
		displayQueue(pQueue);
		
		pNode = Peek(pQueue);
		displayCharData(pNode);
		displayQueue(pQueue);

		pNode = Dequeue(pQueue);
		displayCharData(pNode);
		free(pNode);
		displayQueue(pQueue);

		pNode = Dequeue(pQueue);
		displayCharData(pNode);
		free(pNode);
		displayQueue(pQueue);

		pNode = Dequeue(pQueue);
		displayCharData(pNode);
		free(pNode);
		displayQueue(pQueue);

		pNode = Dequeue(pQueue);
		displayCharData(pNode);
		free(pNode);
		displayQueue(pQueue);

		pNode = Dequeue(pQueue);
		displayCharData(pNode);
		free(pNode);
		displayQueue(pQueue);
		
		EnqueueChar(pQueue, 'E');
		displayQueue(pQueue);

		EnqueueChar(pQueue, 'A');
		EnqueueChar(pQueue, 'B');
		EnqueueChar(pQueue, 'C');
		displayQueue(pQueue);

		DeleteQueue(pQueue);
		/********* My Logic *************
		free(pQueue);
		pQueue = NULL;
		displayQueue(pQueue);
		*********************************/
	}
	return 0;
}