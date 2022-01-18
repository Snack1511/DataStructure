#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ArrayGraph.h"
#include"UsedDataStruct.h"
#include"GraphTravelsal.h"

void DFS(Graph* pGraph, int Node) {
	Stack *pStack = createLNKStack();
	StackNode stackNode;
	int VertCnt = pGraph->curVertexCnt;
	int* pVisitArr = (int*)malloc(sizeof(int) * VertCnt);
	if (pVisitArr == NULL) {
		printf("방문배열 생성 실패\n");
		return;
	}

	memset(pVisitArr, NOTVISIT, sizeof(int) * VertCnt);

	stackNode.data = Node;
	Push(pStack, stackNode);

	int CurVertex = 0;

	if (pGraph != NULL) {
		while (IsStackEmpty(pStack) == FALSE) {
			CurVertex = Pop(pStack)->data;
			for (int i = VertCnt-1; i >= 0; i--) {
				if (pVisitArr[i] == NOTVISIT && pGraph->ppAdjEdge[CurVertex][i] != 0) {
					stackNode.data = i;
					Push(pStack, stackNode);
				}
			}

			if (pVisitArr[CurVertex] == NOTVISIT) {
				pVisitArr[CurVertex] = VISIT;
				printf("%d ", CurVertex);
			}
		}
	}
	printf("\n");
	free(pVisitArr);
	deleteLNKStack(pStack);
}
void BFS(Graph* pGraph, int Node) {

	int VertCnt = pGraph->curVertexCnt;
	int* pVisitArr = (int*)malloc(sizeof(int) * VertCnt);
	if (pVisitArr == NULL) {
		printf("방문배열 생성 실패\n");
		return;
	}

	memset(pVisitArr, NOTVISIT, sizeof(int) * VertCnt);

	Queue* pQueue = CreateQueue();
	QueueNode queueNode;
	int CurVertex = Node;
	
	if (pGraph != NULL) {
		while (pVisitArr[CurVertex] != VISIT) {
			if (pVisitArr[CurVertex] == NOTVISIT) {
				pVisitArr[CurVertex] = VISIT;
				printf("%d ", CurVertex);
			}
			for (int i = VertCnt - 1; i >= 0; i--) {
				if (pVisitArr[i] == NOTVISIT && pGraph->ppAdjEdge[CurVertex][i] != 0) {
					queueNode.data = i;
					Enqueue(pQueue, queueNode);
				}
			}
			while (pVisitArr[CurVertex] == VISIT && isQueueEmpty(pQueue) == FALSE) {
				CurVertex = Dequeue(pQueue)->data;
			}
		}
	}

	printf("\n");
	DeleteQueue(pQueue);
	free(pVisitArr);
}