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
		printf("\n����ð� : %d -----------------------\n", TotalTime);
		
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
			printf("�� ����\n");
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
			printf("���� ���� \n");
		}
		else {
			printf("���� ����ο��� �����ϴ�.\n");
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
			printf("�� ���� --> ");
			PrintClient(*pNode);
		}
		else {
			printf("������...\n");
		}
		pNode = Dequeue(pServiceQueue);
		
	}
	else {
		
	}
	
	free(pNode);
}

void DisplayDelayCount(Queue* pQueue) {
	printf("���� ��� �� : %d\n", pQueue->currentLength);
}

void PrintClient(QueueNode node) {
	printf("�����ð� : %d, ���񽺼ҿ� �ð� : %d\n", node.data.ArrivalTime, node.data.ServiceTime);
}

void PrintResult(Queue* pClients, Queue* pDelay, Queue* pService, int Time) {
	printf("\n\n");
	printf("=========== Result ============\n");
	printf("�ҿ�ð� : %d\n", Time);
	if (isEmpty(pClients) == FALSE) {
		printf("�湮���� ���� �� : %d\n", pClients->currentLength);
	}
	else {
		printf("��� �� �湮 �Ϸ�\n");

	}
	printf("���� ����ο� : %d\n", pDelay->currentLength);
	if (isEmpty(pService) == FALSE) {
		printf("���� �� ����� �� --> ");
		PrintClient(*Peek(pService));
	}
	else {
		printf("��� �� ó�� �Ϸ�\n");
	}
	printf("=========== Result ============\n");
}