#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"LnkGraph.h"

Graph* CreateGraph(int MaxVertCount) {
	Graph* pReturn = NULL;
	pReturn = (Graph*)malloc(sizeof(Graph));
	if (pReturn == NULL) {
		printf("pReturn 메모리 할당 오류\n");
		return NULL;
	}
	pReturn->curLength = 0;
	pReturn->maxLength = MaxVertCount;
	pReturn->DirectMode = UNDIRECT;

	pReturn->pVertex = (int*)malloc(sizeof(int) * MaxVertCount);
	if (pReturn->pVertex == NULL) {
		printf("pVertex 메모리 할당오류\n");
		return;
	}
	memset(pReturn->pVertex, 0, sizeof(int) * MaxVertCount);

	pReturn->ppAdjacentList = (LinkedList**)malloc(sizeof(LinkedList*)*MaxVertCount);
	if (pReturn->ppAdjacentList == NULL) {
		printf("pAdjacentList 메모리 할당 오류\n");
	}
	for (int i = 0; i < MaxVertCount; i++) {
		pReturn->ppAdjacentList[i] = createList();
	}
	return pReturn;
}
Graph* CreateDirectGraph(int MaxVertCount) {
	Graph* pReturn = NULL;
	pReturn = CreateGraph(MaxVertCount);
	if (pReturn != NULL) {
		pReturn->DirectMode = DIRECT;
	}
	return pReturn;
}
void DeleteGraph(Graph* pGraph) {
	if (pGraph != NULL) {
		if(pGraph->pVertex!= NULL){
			free(pGraph->pVertex);
		}
		if (pGraph->ppAdjacentList != NULL) {
			for (int i = 0; i < pGraph->maxLength; i++) {
				deleteLinkedList(pGraph->ppAdjacentList[i]);
			}
			free(pGraph->ppAdjacentList);
		}
	}
	free(pGraph);
	printf("삭제완료!\n");
}

int AddVertex(Graph* pGraph, int Vert) {
	int ret = FALSE;
	if (pGraph != NULL) {
		if (pGraph->pVertex != NULL) {
			pGraph->pVertex[Vert] = USED;
			pGraph->curLength++;
			ret = TRUE;
		}
		else {
			printf("pVertex 가 NULL\n");
		}
	}
	else {
		printf("pGraph 가 NULL\n");
	}
	return ret;
}
int AddEdge(Graph* pGraph, int EnterVert, int OutVert) {
	int ret = FALSE;
	if (pGraph != NULL) {
		ret = AddEdgeWeigt(pGraph, EnterVert, OutVert, 1);
	}
	return ret;
}
int AddEdgeWeigt(Graph* pGraph, int InVert, int OutVert, int weight) {
	int ret = FALSE;
	LinkedNode Node;
	if (pGraph != NULL) {
		if (pGraph->DirectMode == UNDIRECT) {
			Node.data.vertID = OutVert;
			Node.data.weight = weight;
			addLLElement(pGraph->ppAdjacentList[InVert], pGraph->ppAdjacentList[InVert]->currentElementCount, Node);
			Node.data.vertID = InVert;
			Node.data.weight = weight;
			addLLElement(pGraph->ppAdjacentList[OutVert], pGraph->ppAdjacentList[OutVert]->currentElementCount, Node);
		}
		else {
			Node.data.vertID = OutVert;
			Node.data.weight = weight;
			addLLElement(pGraph->ppAdjacentList[InVert], pGraph->ppAdjacentList[InVert]->currentElementCount, Node);
		}
		ret = TRUE;
	}
	return ret;
}

int RemoveVertex(Graph* pGraph, int Vert) {
	if (pGraph != NULL) {
		for (int i = 0; i < pGraph->curLength; i++) {
			if (i == Vert) {
				RemoveEdge(pGraph, Vert, i);
				RemoveEdge(pGraph, i, Vert);
			}
		}

		pGraph->pVertex[Vert] = NOTUSED;
		pGraph->curLength--;
	}
}
int RemoveEdge(Graph* pGraph, int EnterVert, int OutVert){
	int ret = FALSE;
	LinkedNode Node;
	if (pGraph != NULL) {
		Node.data.vertID = OutVert;
		removeLLElement(pGraph->ppAdjacentList[EnterVert], GetPosition(pGraph, Node));
	}
	return ret;
}//뭔가 이상함


void displayGraph(Graph* pGraph);
void DisplayLastVertex(Graph* pGraph);
void DisplayEdge(Graph* pGraph) {
	for (int i = 0; i < pGraph->curLength; i++) {
		displayLinkedList(pGraph->ppAdjacentList[i]);
	}
}