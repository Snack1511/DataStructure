#include<stdio.h>
#include<stdlib.h>
#include"LnkGraph.h"
#include"UsedDataStructure.h"
#include"Graph_ShortPath.h"

/*
	return : 거리정보 저장배열(int 배열)
	input : 그래프 주소, 시작노드

	로직
	for(전체노드)
		현재노드 방문상태 업데이트
		while(현재 방문노드의 인접리스트 != NULL)
			if시작노드에서 이전노드 거리 + 이전노드에서 현재노드의 거리 < 시작노드에서 현재노드
				시작노드에서 현재노드 최단거리 = 시작노드에서 이전노드 거리 + 이전노드에서 현재노드의 거리
			다음 리스트 노드 확인
*/
int* Dijkstra(Graph* pGraph, int StartVert) {
	
	int* pReturn = NULL;
	int* pSelected = NULL;
	int nodeCount = 0, MaxNodeCount = 0;
	int Weight = 0;

	int VertID = 0, y_w = 0, y_v = 0;

	LinkedNode* pNode = NULL;
	LinkedList* pList = NULL;
	// 필요변수 선언 ------------ 

	MaxNodeCount = pGraph->maxLength;
	nodeCount = pGraph->curLength;

	pReturn = (int*)malloc(sizeof(int) * MaxNodeCount);
	pSelected = (int*)malloc(sizeof(int) * MaxNodeCount);

	if (pGraph == NULL) {
		printf("Graph is NULL\n");
		goto RETURN;
	}
	if (pReturn == NULL || pSelected == NULL) {
		if (pReturn != NULL) {
			printf("메모리 할당 오류\n");
		}
		pReturn = NULL;
		goto RETURN;
	}

	for (int i = 0; i < MaxNodeCount; i++) {
		if (i == StartVert) {
			pReturn[i] = 0;
		}
		else {
			if (pGraph->pVertex[i] == USED) {
				pSelected[i] = TRUE;
				pReturn[i] = getEdgeWeight(pGraph, StartVert, i);
			}
			else {
				pSelected[i] = TRUE;
				pReturn[i] = INF;
			}
		}
	}
	// 변수 초기화 --------------
	
	for (int i = 0; i < MaxNodeCount; i++) {
		printf("%d, %d --> %d\n", StartVert, i, pReturn[i]);
	}
	// 초기화 후 거리정보 출력 -------------- 


	for (int i = 0; i < nodeCount - 1; i++) {
		printf("[%d] - ITERATION\n", i + 1);

		VertID = getMinDistance(pReturn, pSelected, MaxNodeCount); // 시작노드와 최단거리의 노드 반환
		pSelected[VertID] = FALSE;

		pList = pGraph->ppAdjacentList[VertID];

		pNode = pList->headerNode.pNextNode;

		while (pNode != NULL) {
			int ToVert = pNode->data.vertID;
			int weight = pNode->data.weight;

			y_v = pReturn[VertID]; // 목표노드 이전 인접노드까지의 최단거리
			y_w = pReturn[ToVert]; // 시작노드에서 목표노드까지의 거리

			if (y_v + weight < y_w) { 
				// (i ~ 목표인접노드까지 거리 + 인접노드에서 목표까지 거리) <  시작노드 ~ 목표 거리
				pReturn[ToVert] = y_v + weight;
			}

			pNode = pNode->pNextNode;
		}

		// 다익스트라알고리즘 실행 위한 반복 ----------------

		for (int j = 0; j < MaxNodeCount; j++) {
			printf("\t%d, %d --> %d\n", StartVert, j, pReturn[j]);
		}
		// 반복 실행 후 해당 노드의 상태 출력 -------------- 
	}

	free(pSelected);


	RETURN:
	return pReturn;
}

int getMinDistance(int* distance, int* isSelected, int maxNode) {

}
int getEdgeWeight(Graph* pGraph, int Invert, int OutVert);

int** Floyd(Graph* pGraph) {
	int** pReturn = NULL;
	int weight = 0;
	int maxNodeCount = 0;

	if (pGraph == NULL) {
		printf("Graph is NULL\n");
		return NULL;
	}
	maxNodeCount = pGraph->maxLength;//pGraph의 최대노드개수 확인

	pReturn = (int**)malloc(sizeof(int*) * maxNodeCount);
	if (pReturn == NULL) {
		printf("pReturn 메모리 할당 오류\n");
		return NULL;
	}//반환값 저장을 위한 메모리 할당 및 점검, 2차원 배열

	for (int i = 0; i < maxNodeCount; i++) {
		pReturn[i] = (int*)malloc(sizeof(int) * maxNodeCount);

		if (pReturn[i] == NULL) {
			printf("pReturn[%d] 메모리 할당 오류", i);
			return NULL;
		}
	}//반환값 저장, 루프를 돌면서 각각 1차원배열을 생성함

	//초기화. 배열pReturn의 초기화
	for (int i = 0; i < maxNodeCount; i++) {
		for (int j = 0; j < maxNodeCount; j++) {
			if (i == j) {
				pReturn[i][j] = 0;
			}
			else {
				pReturn[i][j] = getEdgeWeight(pGraph, i, j);
			}
		}
	}//각 노드 사이의 거리를 초기화, 두 노드를 연결시켜주는 간선의 가중치 값을 이용

	PrintMatrix(pReturn, maxNodeCount);

	//step1. 삼중 루프
	for (int i = 0; i < maxNodeCount; i++) {//v
		for (int j = 0; j < maxNodeCount; j++) {//r
			for (int k = 0; k < maxNodeCount; k++) {//s
				if (pReturn[j][i] + pReturn[i][k] < pReturn[j][k]) {
					pReturn[j][k] = pReturn[j][i] + pReturn[i][k];
				}
			}
		}
		printf("[%d] - 루프\n", i + 1);
	}//삼중루프를 돌면서 최단거리 변경을 수행

	return pReturn;
}

void PrintPath(Queue* pPath) {
	if (pPath != NULL) {
		printf("Path : ");
		while (IsQueueEmpty(pPath) == FALSE) {
			printf("%d    ", Dequeue(pPath)->data);
		}
		printf("\n");
	}
}