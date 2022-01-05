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

	Node.data.ArrivalTime = 7;
	Node.data.ServiceTime = 3;
	Enqueue(pReturn, Node);

	Node.data.ArrivalTime = 7;
	Node.data.ServiceTime = 3;
	Enqueue(pReturn, Node);

	Node.data.ArrivalTime = 7;
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

void Process(int EndTime, int OfficerNum) {
	int TotalTime = 0;
	float TotalDelayTime = 0;
	Queue* pClients = NULL;
	Queue* pDelayQueue = NULL;
	Queue** pServiceQueue = (Queue**)malloc(sizeof(Queue*)*OfficerNum);
	QueueNode* pNode = NULL;
	pClients = InitClients();
	pDelayQueue = CreateQueue();
	int TotalClient = pClients->currentLength;
	if (pServiceQueue != NULL) {
		for (int i = 0; i < OfficerNum; i++) {
			*(pServiceQueue + i) = CreateQueue();
		}
	
		while (TotalTime < EndTime) {
			printf("\n����ð� : %d -----------------------\n", TotalTime);
		
			ClientArrive(pClients, pDelayQueue, TotalTime);
			
			ServiceStart(pDelayQueue, pServiceQueue, OfficerNum);

			ServiceEnd(pDelayQueue, pServiceQueue, TotalTime, OfficerNum);

			SumDelayTime(pDelayQueue, &TotalDelayTime);

			TotalTime++;
		}

		PrintResult(pClients, pDelayQueue, pServiceQueue, TotalTime, OfficerNum, (TotalDelayTime/(TotalClient - pClients->currentLength)));
	}
	for (int i = 0; i < OfficerNum; i++) {
		DeleteQueue(pServiceQueue[i]);
	}
	DeleteQueue(pDelayQueue);
	DeleteQueue(pClients);
	free(pServiceQueue);
}

void ClientArrive(Queue* pClients, Queue* pDelayQueue, int Time) {
	QueueNode* pNode = NULL;
	if (isEmpty(pClients) == FALSE) {
		while (isEmpty(pClients) == FALSE&&Time == Peek(pClients)->data.ArrivalTime) {
			pNode = Dequeue(pClients);
			printf("�� ����\n");
			Enqueue(pDelayQueue, *pNode);
		}
		DisplayDelayCount(pDelayQueue);
	}
	free(pNode);
}
void ServiceStart(Queue* pDelayQueue, Queue** pServiceQueue, int OfficerNum) {
	int BrakingOfficer = 0;
	for (int i = 0; i < OfficerNum; i++) {
		/*if (isEmpty(*(pServiceQueue + i)) == TRUE) {
			BrakingOfficer = i;
			break;
		}*/
		if (isEmpty(pServiceQueue[i]) == TRUE) {
			if (isEmpty(pDelayQueue) == FALSE) {
				QueueNode* pNode = Dequeue(pDelayQueue);
				for (int j= 0; j < pNode->data.ServiceTime; j++) {
					Enqueue(pServiceQueue[i], *pNode);
				}
				printf("Officer[%d] : ���� ���� \n", i);
			}
			else {
				printf("Officer[%d] : ���� ����ο��� �����ϴ�.\n", i);
			}
		}
		else {
			printf("Officer[%d] : �������Դϴ�.\n", i);
		}
		
	}
	
}

void ServiceEnd(Queue* pDelayQueue, Queue** pServiceQueue, int TotalTime, int OfficerNum) {
	QueueNode* pNode = NULL;
	QueueNode* peekNode = NULL;
	for (int i = 0; i < OfficerNum; i++) {
		if (isEmpty(pServiceQueue[i]) == FALSE) {
			DisplayDelayCount(pDelayQueue);
			if (pServiceQueue[i]->currentLength == 1) {
				pNode = Peek(pServiceQueue[i]);
				printf("Officer[%d] : �� ���� --> ", i);
				PrintClient(*pNode);
			}
			else {
				printf("Officer[%d] : ������...\n", i);
			}
			pNode = Dequeue(pServiceQueue[i]);

		}
	}
	
	free(pNode);
}

void DisplayDelayCount(Queue* pQueue) {
	printf("���� ��� �� : %d\n", pQueue->currentLength);
}

void PrintClient(QueueNode node) {
	printf("�����ð� : %d, ���񽺼ҿ� �ð� : %d\n", node.data.ArrivalTime, node.data.ServiceTime);
}

void SumDelayTime(Queue* pDelayQueue, float* pSum) {
	if (isEmpty(pDelayQueue) == FALSE) {
		*pSum = *pSum+ pDelayQueue->currentLength;
	}
}

void PrintResult(Queue* pClients, Queue* pDelay, Queue** pService, int Time, int Officer, float AvgDelayTime) {
	printf("\n\n");
	printf("=========== Result ============\n");
	printf("�ҿ�ð� : %d\n", Time);
	printf("��� ���ð� : %f\n", AvgDelayTime);
	if (isEmpty(pClients) == FALSE) {
		printf("�湮���� ���� �� : %d\n", pClients->currentLength);
	}
	else {
		printf("��� �� �湮 �Ϸ�\n");

	}
	printf("���� ����ο� : %d\n", pDelay->currentLength);
	for (int i = 0; i < Officer; i++) {
		printf("Officer[%d] : ", i);
		if (isEmpty(pService[i]) == FALSE) {
			printf("���� �� ����� �� --> ");
			PrintClient(*Peek(pService[i]));
		}
		else {
			printf("��� �� ó�� �Ϸ�\n");
		}
	}


	
	printf("=========== Result ============\n");
}