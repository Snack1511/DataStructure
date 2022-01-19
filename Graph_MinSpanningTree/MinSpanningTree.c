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
		}//��ȯ�� �׷��� �ʱ�ȭ �� ���ؽ� �߰�
		for (int i = 0; i < pGraph->maxLength; i++) {
			maxHeapLength+=pGraph->ppAdjacentList[i]->currentElementCount;
		}// �� ���� ���� ��ü ���� �� Ȯ��
		pMinHeap = CreateHeap(maxHeapLength);
		for (int i = 0; i < pGraph->maxLength; i++) {
			pNode = pGraph->ppAdjacentList[i]->headerNode.pNextNode;
			while (pNode != NULL) {
				InsertHeapNode(pMinHeap, CreateEdgeNodeData(i, pNode->data.vertID, pNode->data.weight));
				pNode = pNode->pNextNode;
			}
		}//�ּ��� ����
		while (IsAllVertexConnect(pReturn) == FALSE) {
			pEdgeHeapNode = DeleteHeap(pMinHeap);
			if (FindCycle(*pGraph, *pEdgeHeapNode) == FALSE) {
				AddEdgeWeightHeapNode(pReturn, pEdgeHeapNode);
			}
		}// ��ȯ�׷����� ���� �߰�

	}
	return pReturn;
}


int AddEdgeWeightHeapNode(Graph* pGraph, HeapNode* pNode) {
	return AddEdgeWeigt(pGraph, pNode->data.InVert, pNode->data.OutVert, pNode->key);
}

/*����Ŭ Ž�� �Լ�*/
int FindCycle(Graph pGraph, HeapNode Node) {
	int ret = FALSE;
	Stack* pStack = createLNKStack();
	Graph Search = pGraph;
	

	//DFS or BFS ���
	return ret;
}
/*�׷��� �� ��ü ��� ����Ȯ�� �Լ�*/
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