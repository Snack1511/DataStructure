#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ArrayGraph.h"

Graph* CreateGraph(int MaxVertCount) {
	Graph* pReturn = NULL;
	pReturn = (Graph*)malloc(sizeof(Graph));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(Graph));
		pReturn->maxVertexCnt = MaxVertCount;
		pReturn->GraphType = UNDIRECT;
		pReturn->pVertex = (int*)malloc(sizeof(int)*MaxVertCount);
		if (pReturn->pVertex != NULL) {
			memset(pReturn->pVertex, 0, sizeof(int)*MaxVertCount);
			
		}
		else
		{
			printf("pVertex 메모리 할당 오류\n");
		}
		pReturn->ppAdjEdge = (int**)malloc((sizeof(int*) * MaxVertCount));
		if (pReturn->ppAdjEdge != NULL) {
			for (int i = 0; i < MaxVertCount; i++) {
				pReturn->ppAdjEdge[i] = (int*)malloc(sizeof(int) * MaxVertCount);
				if (pReturn->ppAdjEdge[i] != NULL) {
					memset(pReturn->ppAdjEdge[i], 0, (sizeof(int) * MaxVertCount));
				}
			}

		}
		else {
			printf("ppAdjEdge 메모리 할당 오류\n");

		}
	}
	else{
		printf("메모리 할당 오류\n");
	}

	return pReturn;
}
Graph* CreateDirectGraph(int MaxVertCount) {
	Graph* pReturn = NULL;
	pReturn = (Graph*)malloc(sizeof(Graph));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(Graph));
		pReturn->maxVertexCnt = MaxVertCount;
		pReturn->GraphType = DIRECT;
		pReturn->pVertex = (int*)malloc(sizeof(int) * MaxVertCount);


		if (pReturn->pVertex != NULL) {
			memset(pReturn->pVertex, NOTUSED, sizeof(int) * MaxVertCount);
			pReturn->ppAdjEdge = (int**)malloc((sizeof(int*) * MaxVertCount));

			if (pReturn->ppAdjEdge != NULL) {
				for (int i = 0; i < MaxVertCount; i++) {
					pReturn->ppAdjEdge[i] = (int*)malloc(sizeof(int) * MaxVertCount);
					if (pReturn->ppAdjEdge[i] != NULL) {
						memset(pReturn->ppAdjEdge[i], 0, (sizeof(int) * MaxVertCount));
					}
				}

			}
			else {
				printf("ppAdjEdge 메모리 할당 오류\n");

			}
		}
		else
		{
			printf("pVertex 메모리 할당 오류\n");
		}

	}
	else {
		printf("메모리 할당 오류\n");
	}

	return pReturn;
}

int AddVertex(Graph* pGraph, int Vert) {
	int ret = FALSE;
	if (pGraph != NULL) {
		if (pGraph->pVertex != NULL) {
			pGraph->pVertex[Vert] = USED;
			pGraph->curVertexCnt++;
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
	if (pGraph != NULL) {
		if (pGraph->GraphType == UNDIRECT) {
			pGraph->ppAdjEdge[InVert][OutVert] = weight;
			pGraph->ppAdjEdge[OutVert][InVert] = weight;
		}
		else {
			pGraph->ppAdjEdge[InVert][OutVert] = weight;

		}
		ret = TRUE;
	}
	return ret;
}

int RemoveVertex(Graph* pGraph, int Vert) {
	if (pGraph != NULL) {
		for (int i = 0; i < pGraph->curVertexCnt; i++) {
			if (i == Vert) {
				RemoveEdge(pGraph, Vert, i);
				RemoveEdge(pGraph, i, Vert);
			}
		}

		pGraph->pVertex[Vert] = NOTUSED;
		pGraph->curVertexCnt--;
	}
}
int RemoveEdge(Graph* pGraph, int EnterVert, int OutVert) {
	int ret = FALSE;
	if (pGraph != NULL) {
		if (pGraph->GraphType == UNDIRECT) {
			pGraph->ppAdjEdge[EnterVert][OutVert] = 0;
			pGraph->ppAdjEdge[OutVert][EnterVert] = 0;
		}
		else {
			pGraph->ppAdjEdge[EnterVert][OutVert] = 0;

		}
	}
	return ret;
}
void displayGraph(Graph* pGraph);

void DisplayLastVertex(Graph* pGraph) {
	if (pGraph != NULL) {
		printf("LastIndex : %d    LastIndex's Vertex : %d\n", pGraph->curVertexCnt-1, pGraph->pVertex[pGraph->curVertexCnt-1]);
		
	}
}

void DisplayEdge(Graph* pGraph) {
	if (pGraph != NULL) {
		for (int i = 0; i < pGraph->curVertexCnt; i++) {
			for (int j = 0; j < pGraph->curVertexCnt; j++) {
				printf("%d  ", pGraph->ppAdjEdge[i][j]);
			}
			printf("\n");
		}

	}
	printf("\n");
}

void DeleteGraph(Graph* pGraph) {
	if (pGraph != NULL) {
		free(pGraph->pVertex);
		for (int i = 0; i < pGraph->maxVertexCnt; i++) {
			if (pGraph->ppAdjEdge[i] != NULL) {
				free(pGraph->ppAdjEdge[i]);
			}
		}
		free(pGraph->ppAdjEdge);
	}
	free(pGraph);
	printf("Delete Complete!\n");
}
