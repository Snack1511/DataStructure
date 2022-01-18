#include<stdio.h>
#include<stdlib.h>
#include"ArrayGraph.h"
#include"GraphTravelsal.h"

#define MAXGRAPHSIZE 8

int main() {
	Graph* pUDG = CreateGraph(MAXGRAPHSIZE);
	Graph* pDG = CreateDirectGraph(MAXGRAPHSIZE);
	if (pUDG != NULL) {
#pragma region 무방향 그래프 추가
		AddVertex(pUDG, 0);
		AddVertex(pUDG, 1);
		AddVertex(pUDG, 2);
		AddVertex(pUDG, 3);
		AddVertex(pUDG, 4);
		AddVertex(pUDG, 5);
		AddVertex(pUDG, 6);
		AddVertex(pUDG, 7);



		AddEdge(pUDG, 0, 1);
		AddEdge(pUDG, 0, 2);
		AddEdge(pUDG, 1, 3);
		AddEdge(pUDG, 1, 4);
		AddEdge(pUDG, 2, 5);
		AddEdge(pUDG, 2, 6);
		AddEdge(pUDG, 3, 7);
		AddEdge(pUDG, 4, 5);


		printf("UndirectGraph\n");
		DisplayEdge(pUDG);
#pragma endregion 무방향 그래프 추가
		//RemoveVertex(pUDG, 0);
		DisplayEdge(pUDG);
	}
	DFS(pUDG, 0);
	BFS(pUDG, 0);
	DeleteGraph(pUDG);
	
#pragma region 방향 그래프 추가
	if (pDG != NULL) {
		AddVertex(pDG, 0);
		AddVertex(pDG, 1);
		AddVertex(pDG, 2);
		AddVertex(pDG, 3);
		AddVertex(pDG, 4);
		AddVertex(pDG, 5);
		AddVertex(pDG, 6);

		AddEdge(pDG, 0, 1);
		AddEdge(pDG, 0, 2);
		AddEdge(pDG, 0, 3);

		AddEdge(pDG, 1, 0);
		AddEdge(pDG, 2, 0);
		AddEdge(pDG, 3, 0);


		AddEdge(pDG, 1, 4);
		AddEdge(pDG, 1, 5);
		AddEdge(pDG, 4, 1);


		AddEdge(pDG, 2, 3);
		AddEdge(pDG, 2, 6);
		AddEdge(pDG, 6, 2);


		AddEdge(pDG, 3, 5);
		AddEdge(pDG, 5, 3);
		AddEdge(pDG, 3, 6);
		
		printf("DirectGraph\n");
		DisplayEdge(pDG);
	}
#pragma endregion 방향 그래프 추가

	RemoveVertex(pDG, 0);
	DisplayEdge(pDG);

	return 0;
}