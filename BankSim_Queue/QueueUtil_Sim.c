#include<stdio.h>
#include<stdlib.h>
#include"linkedqueue.h"
#include"QueueUtil_Sim.h"

Queue* InitClients() {
	Queue* pReturn = NULL;
	QueueNode Node;
	pReturn = CreateQueue();
	Node.data.ArrivalTime = 0;
	Node.data.ServiceTime = 3;
	Enqueue(pReturn, Node);

	Node.data.ArrivalTime = 2;
	Node.data.ServiceTime = 2;
	Enqueue(pReturn, Node);

	Node.data.ArrivalTime = 4;
	Node.data.ServiceTime = 1;
	Enqueue(pReturn, Node);

	Node.data.ArrivalTime = 4;
	Node.data.ServiceTime = 2;
	Enqueue(pReturn, Node);

	Node.data.ArrivalTime = 6;
	Node.data.ServiceTime = 3;
	Enqueue(pReturn, Node);

	Node.data.ArrivalTime = 8;
	Node.data.ServiceTime = 3;
	Enqueue(pReturn, Node);

	Node.data.ArrivalTime = 8;
	Node.data.ServiceTime = 3;
	Enqueue(pReturn, Node);

	Node.data.ArrivalTime = 8;
	Node.data.ServiceTime = 3;
	Enqueue(pReturn, Node);

	Node.data.ArrivalTime = 8;
	Node.data.ServiceTime = 3;
	Enqueue(pReturn, Node);

	Node.data.ArrivalTime = 12;
	Node.data.ServiceTime = 3;
	Enqueue(pReturn, Node);

	return pReturn;
}

void Process(int EndTime) {
	int TotalTime = 0;
	Queue* pClients = NULL;
	Queue* pDelayQueue = NULL;
	Queue* pServiceQueue = NULL;
	QueueNode* pNode = NULL;
	pClients = InitClients();
	pDelayQueue = CreateQueue();
	pServiceQueue = CreateQueue();
	while (TotalTime < EndTime) {
		printf("\n현재시간 : %d -----------------------\n", TotalTime);
		
		ServiceEnd(pDelayQueue, pServiceQueue, TotalTime);

		ClientArrive(pClients, pDelayQueue, TotalTime);

		ServiceStart(pDelayQueue, pServiceQueue);
		
		TotalTime++;
	}

	PrintResult(pClients, pDelayQueue, pServiceQueue, TotalTime);
	
	DeleteQueue(pServiceQueue);
	DeleteQueue(pDelayQueue);
	DeleteQueue(pClients);
}

void ClientArrive(Queue* pClients, Queue* pDelayQueue, int Time) {
	QueueNode* pNode = NULL;
	if (isEmpty(pClients) == FALSE) {
		while (Time == Peek(pClients)->data.ArrivalTime) {
			pNode = Dequeue(pClients);
			printf("고객 도착\n");
			Enqueue(pDelayQueue, *pNode);
		}
		DisplayDelayCount(pDelayQueue);
	}
	free(pNode);
}
void ServiceStart(Queue* pDelayQueue, Queue* pServiceQueue) {
	if (isEmpty(pServiceQueue) == TRUE) {
		if (isEmpty(pDelayQueue) == FALSE) {
			QueueNode* pNode = Dequeue(pDelayQueue);
			for (int i = 0; i < pNode->data.ServiceTime; i++) {
				Enqueue(pServiceQueue, *pNode);
			}
			printf("서비스 시작 \n");
		}
		else {
			printf("현재 대기인원이 없습니다.\n");
		}
	}
}

void ServiceEnd(Queue* pDelayQueue, Queue* pServiceQueue, int TotalTime) {
	QueueNode* pNode = NULL;
	QueueNode* peekNode = NULL;

	if (isEmpty(pServiceQueue) == FALSE) {
		DisplayDelayCount(pDelayQueue);
		if (pServiceQueue->currentLength == 1) {
			pNode = Peek(pServiceQueue);
			printf("고객 퇴장 --> ");
			PrintClient(*pNode);
		}
		else {
			printf("서비스중...\n");
		}
		pNode = Dequeue(pServiceQueue);
		
	}
	else {
		
	}
	
	free(pNode);
}

void DisplayDelayCount(Queue* pQueue) {
	printf("현재 대기 고객 : %d\n", pQueue->currentLength);
}

void PrintClient(QueueNode node) {
	printf("도착시간 : %d, 서비스소요 시간 : %d\n", node.data.ArrivalTime, node.data.ServiceTime);
}

void PrintResult(Queue* pClients, Queue* pDelay, Queue* pService, int Time) {
	printf("\n\n");
	printf("=========== Result ============\n");
	printf("소요시간 : %d\n", Time);
	if (isEmpty(pClients) == FALSE) {
		printf("방문하지 못한 고객 : %d\n", pClients->currentLength);
	}
	else {
		printf("모든 고객 방문 완료\n");

	}
	printf("남은 대기인원 : %d\n", pDelay->currentLength);
	if (isEmpty(pService) == FALSE) {
		printf("서비스 중 종료된 고객 --> ");
		PrintClient(*Peek(pService));
	}
	else {
		printf("모든 고객 처리 완료\n");
	}
	printf("=========== Result ============\n");
}