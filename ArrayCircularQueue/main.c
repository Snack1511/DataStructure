#include<stdio.h>
#include<stdlib.h>
#include"arrayqueue.h"

void displayQueue(Queue* pQueue) {
	int i = 0;
	int maxEleLength = 0, pos = 0;
	if (pQueue != NULL) {
		printf("큐의 크기 : %d, 현재 노드 개수 : %d\n", pQueue->maxLength, pQueue->currentLength);

		maxEleLength = pQueue->front + pQueue->currentLength;		//변경
		for (i = pQueue->front+1; i <= maxEleLength; i++) {			//변경
			pos = i % pQueue->maxLength;							//변경
			printf("[%d] %c    ", i, pQueue->pElements[pos].data);	//변경
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

		EnqueueChar(pQueue, 'E');
		displayQueue(pQueue);
	}
	return 0;
}