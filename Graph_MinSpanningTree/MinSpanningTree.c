#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"
#include"UsedDataStruct.h"
#include"LnkGraph.h"
#include"ArrayHeap.h"
#include"MinSpanningTree.h"


Graph* Kruskal(Graph *pGraph) {
	int maxHeapLength = 0;
	Data Edgedata = { 0, };
	Heap* pMinHeap = NULL;
	Graph *pReturn= NULL;
	LinkedNode * pNode = NULL;
	HeapNode* pEdgeHeapNode = NULL;
	if (pGraph != NULL) {
		pReturn = CreateGraph(pGraph->maxLength);
		for (int i = 0; i < pGraph->maxLength; i++) {
			if (pGraph->pVertex[i] != NOTUSED) {
				AddVertex(pReturn, i);
			}
		}//반환될 그래프 초기화 및 버텍스 추가
		for (int i = 0; i < pGraph->maxLength; i++) {
			maxHeapLength+=pGraph->ppAdjacentList[i]->currentElementCount;
		}// 힙 생성 위한 전체 간선 수 확인
		pMinHeap = CreateHeap(maxHeapLength);
		for (int i = 0; i < pGraph->maxLength; i++) {
			pNode = pGraph->ppAdjacentList[i]->headerNode.pNextNode;
			while (pNode != NULL) {
				InsertHeapNode(pMinHeap, CreateEdgeNodeData(i, pNode->data.vertID, pNode->data.weight));
				pNode = pNode->pNextNode;
			}
		}//최소힙 정렬
		DisplayHeap(pMinHeap);
		while (IsAllVertexConnect(pReturn) == FALSE) {
			pEdgeHeapNode = DeleteHeap(pMinHeap);
			if (pEdgeHeapNode->key != 0 && FindCycle(pReturn, *pEdgeHeapNode) == FALSE) {
				AddEdgeWeightHeapNode(pReturn, pEdgeHeapNode);
			}
		}// 반환그래프에 간선 추가

	}
	return pReturn;
}
Graph* Prim(Graph* pGraph) {
	Graph* pReturn = NULL;

	return pReturn;
}

int AddEdgeWeightHeapNode(Graph* pGraph, HeapNode* pNode) {
	return AddEdgeWeigt(pGraph, pNode->data.InVert, pNode->data.OutVert, pNode->key);
}

/*사이클 탐색 함수*/
int FindCycle(Graph* pGraph, HeapNode Node) {
	int ret = FALSE;
	if (pGraph == NULL) {
		return TRUE;
	}
	//Graph Search = *pGraph;

	int* pVisitArr = (int*)malloc(sizeof(int) * pGraph->maxLength);
	if (pVisitArr == NULL) {
		printf("방문배열 생성 오류\n");
	}
	for (int i = 0; i < pGraph->maxLength; i++) {
		pVisitArr[i] = NOTVISIT;
	}//방문배열 초기화

	Stack* pStack = createLNKStack();
	StackNode Stacknode = {0, };
	LinkedNode* pNode = NULL;

	Stacknode.data = Node.data.InVert;
	Push(pStack, Stacknode);
	int CurVertex = 0;
	while (IsStackEmpty(pStack) == FALSE) {
		CurVertex = Pop(pStack)->data;
		if (CurVertex == Node.data.OutVert) {
			printf("현재노드%d - 시작노드%d : 간선존재\n", CurVertex, Node.data.OutVert);
			return TRUE;
		}
		pNode = pGraph->ppAdjacentList[CurVertex]->headerNode.pNextNode;
		while (pNode != NULL)
		{
			if(pVisitArr[pNode->data.vertID] != VISIT){
				Stacknode.data = pNode->data.vertID;
				Push(pStack, Stacknode);
				pVisitArr[pNode->data.vertID] = VISIT;
			}
			pNode = pNode->pNextNode;
		}
		

	}
	deleteLNKStack(pStack);
	free(pVisitArr);
	//DFS or BFS 사용
	return ret;
}
/*그래프 내 전체 노드 연결확인 함수*/
int IsAllVertexConnect(Graph *pGraph) {
	int ret = FALSE;
	if (pGraph == NULL) {
		return ret;
	}
	//Graph Search = *pGraph;

	int* pVisitArr = (int*)malloc(sizeof(int) * pGraph->maxLength);
	if (pVisitArr == NULL) {
		printf("방문배열 생성 오류\n");
	}
	for (int i = 0; i < pGraph->maxLength; i++) {
		pVisitArr[i] = NOTVISIT;
	}//방문배열 초기화

	Stack* pStack = createLNKStack();
	StackNode Stacknode = { 0, };
	LinkedNode* pNode = NULL;

	Stacknode.data = 0;
	Push(pStack, Stacknode);
	pVisitArr[0] = VISIT;

	int CurVertex = 0;
	while (IsStackEmpty(pStack) == FALSE) {
		CurVertex = Pop(pStack)->data;
		pNode = pGraph->ppAdjacentList[CurVertex]->headerNode.pNextNode;
		while (pNode != NULL) {
			if (pVisitArr[pNode->data.vertID] == NOTVISIT) {
				Stacknode.data = pNode->data.vertID;
				Push(pStack, Stacknode);
				pVisitArr[pNode->data.vertID] = VISIT;
			}
			pNode = pNode->pNextNode;
		}
	}
	int NodeCount = 0;
	for (int i = 0; i < pGraph->maxLength; i++) {
		if (pVisitArr[i] == VISIT) {
			NodeCount++;
		}
	}
	if (NodeCount == pGraph->curLength) {
		ret = TRUE;
	}

	return ret;
}