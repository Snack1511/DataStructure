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
		DisplayHeap(pMinHeap);
		while (IsAllVertexConnect(pReturn) == FALSE) {
			pEdgeHeapNode = DeleteHeap(pMinHeap);
			if (pEdgeHeapNode->key != 0 && FindCycleHeapNode(pReturn, *pEdgeHeapNode) == FALSE) {
				AddEdgeWeightHeapNode(pReturn, pEdgeHeapNode);
			}
		}// ��ȯ�׷����� ���� �߰�

	}
	return pReturn;
}
Graph* Prim(Graph* pGraph) {
	Graph* pReturn = NULL;
	int CurVertex = 0;
	pReturn = CreateGraph(pGraph->maxLength);
	LinkedNode* pNode = NULL;
	LinkedNode *pMinNode = NULL;
	for (int i = 0; i < pReturn->maxLength; i++) {
		CurVertex = i;
		AddVertex(pReturn, CurVertex);
		pNode = pGraph->ppAdjacentList[CurVertex]->headerNode.pNextNode;
		pMinNode = pNode;
		while (pNode != NULL) {
			if (pMinNode->data.weight >= pNode->data.weight && FindCycle(pReturn, CurVertex, pNode->data.vertID) == FALSE) {
				pMinNode = pNode;
			}
			pNode = pNode->pNextNode;
		}
		if (FindCycle(pReturn, CurVertex, pMinNode->data.vertID) == FALSE) {
			AddEdgeWeigt(pReturn, CurVertex, pMinNode->data.vertID, pMinNode->data.weight);
		}
	}

	

	return pReturn;
}

int AddEdgeWeightHeapNode(Graph* pGraph, HeapNode* pNode) {
	return AddEdgeWeigt(pGraph, pNode->data.InVert, pNode->data.OutVert, pNode->key);
}

int FindCycleHeapNode(Graph* pGraph, HeapNode Node) {
	int ret = FindCycle(pGraph, Node.data.InVert, Node.data.OutVert);
}
/*����Ŭ Ž�� �Լ�*/
int FindCycle(Graph* pGraph, int Invert, int Outvert) {
	int ret = FALSE;
	if (pGraph == NULL) {
		return TRUE;
	}
	//Graph Search = *pGraph;

	int* pVisitArr = (int*)malloc(sizeof(int) * pGraph->maxLength);
	if (pVisitArr == NULL) {
		printf("�湮�迭 ���� ����\n");
	}
	for (int i = 0; i < pGraph->maxLength; i++) {
		pVisitArr[i] = NOTVISIT;
	}//�湮�迭 �ʱ�ȭ

	Stack* pStack = createLNKStack();
	StackNode Stacknode = {0, };
	LinkedNode* pNode = NULL;

	Stacknode.data = Invert;
	Push(pStack, Stacknode);
	int CurVertex = 0;
	while (IsStackEmpty(pStack) == FALSE) {
		CurVertex = Pop(pStack)->data;
		if (CurVertex == Outvert) {
			printf("������%d - ���۳��%d : ��������\n", CurVertex, Outvert);
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
	//DFS or BFS ���
	return ret;
}
/*�׷��� �� ��ü ��� ����Ȯ�� �Լ�*/
int IsAllVertexConnect(Graph *pGraph) {
	int ret = FALSE;
	if (pGraph == NULL) {
		return ret;
	}
	//Graph Search = *pGraph;

	int* pVisitArr = (int*)malloc(sizeof(int) * pGraph->maxLength);
	if (pVisitArr == NULL) {
		printf("�湮�迭 ���� ����\n");
	}
	for (int i = 0; i < pGraph->maxLength; i++) {
		pVisitArr[i] = NOTVISIT;
	}//�湮�迭 �ʱ�ȭ

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

