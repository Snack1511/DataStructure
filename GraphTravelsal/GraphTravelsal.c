#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LnkGraph.h"
#include"UsedDataStruct.h"
#include"GraphTravelsal.h"

void DFS(Graph* pGraph, int Node) {
	Stack *pStack = createLNKStack();
	LinkedNode* pNode = NULL;
	StackNode stackNode;
	int VertCnt = pGraph->curLength;
	int* pVisitArr = (int*)malloc(sizeof(int) * VertCnt);
	if (pVisitArr == NULL) {
		printf("방문배열 생성 실패\n");
		return;
	}

	memset(pVisitArr, NOTVISIT, sizeof(int) * VertCnt);

	stackNode.data = Node;
	Push(pStack, stackNode);
	pVisitArr[Node] = VISIT;

	int CurVertex = 0;
	if (pGraph != NULL) {
		while (IsStackEmpty(pStack) == FALSE) {
 			CurVertex = Pop(pStack)->data;
			printf("%d ", CurVertex);
			pNode = pGraph->ppAdjacentList[CurVertex]->headerNode.pNextNode;
			while (pNode != NULL) {
				if (pVisitArr[pNode->data.vertID] == NOTVISIT) {
					stackNode.data = pNode->data.vertID;
					Push(pStack, stackNode);
					pVisitArr[pNode->data.vertID] = VISIT;
				}
				pNode = pNode->pNextNode;
			}
			
		}
	}
	printf("\n");
	free(pVisitArr);
	deleteLNKStack(pStack);
}
void BFS(Graph* pGraph, int Node) {
	LinkedNode* pNode = NULL;
	int VertCnt = pGraph->curLength;
	int* pVisitArr = (int*)malloc(sizeof(int) * VertCnt);
	if (pVisitArr == NULL) {
		printf("방문배열 생성 실패\n");
		return;
	}

	memset(pVisitArr, NOTVISIT, sizeof(int) * VertCnt);

	Queue* pQueue = CreateQueue();
	QueueNode queueNode;
	int CurVertex = Node;
	pVisitArr[CurVertex] = VISIT;
	queueNode.data = CurVertex;
	Enqueue(pQueue, queueNode);
	while (isQueueEmpty(pQueue) == FALSE) {
		CurVertex = Dequeue(pQueue)->data;
		printf("%d", CurVertex);
		
		if (pGraph->ppAdjacentList[CurVertex] > 0) {
			pNode = pGraph->ppAdjacentList[CurVertex]->headerNode.pNextNode;
			while (pNode != NULL) {
				if (pVisitArr[pNode->data.vertID] == NOTVISIT && pNode != NULL) {
					queueNode.data = pNode->data.vertID;
					Enqueue(pQueue, queueNode);
					pVisitArr[pNode->data.vertID] = VISIT;
				}
				pNode = pNode->pNextNode;
			}
		}
	}

	printf("\n");
	DeleteQueue(pQueue);
	free(pVisitArr);
}