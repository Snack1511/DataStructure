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
			AddVertex(pReturn, pGraph->pVertex[i]);
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
		while (IsAllVertexConnect(pReturn) == FALSE) {
			pEdgeHeapNode = DeleteHeap(pMinHeap);
			if (FindCycle(*pGraph, *pEdgeHeapNode) == FALSE) {
				AddEdgeWeightHeapNode(pReturn, pEdgeHeapNode);
			}
		}// 반환그래프에 간선 추가

	}
	return pReturn;
}


int AddEdgeWeightHeapNode(Graph* pGraph, HeapNode* pNode) {
	return AddEdgeWeigt(pGraph, pNode->data.InVert, pNode->data.OutVert, pNode->key);
}

/*사이클 탐색 함수*/
int FindCycle(Graph pGraph, HeapNode Node) {
	int ret = FALSE;
	Stack* pStack = createLNKStack();
	Graph Search = pGraph;
	

	//DFS or BFS 사용
	return ret;
}
/*그래프 내 전체 노드 연결확인 함수*/
int IsAllVertexConnect(Graph *pGraph) {
	int ret = TRUE;
	for (int i = 0; i < pGraph->maxLength; i++) {
		if (pGraph->pVertex[i] != NOTUSED) {
			if (pGraph->ppAdjacentList[i]->currentElementCount <= 0) {
				ret = FALSE;
				break;
			}
		}
	}
	return ret;
}