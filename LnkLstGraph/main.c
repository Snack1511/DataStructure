#include<stdio.h>
#include<stdlib.h>
#include"LnkGraph.h"
#define MAXVERTSIZE 8
int main() {
	Graph* pUDGraph = CreateGraph(MAXVERTSIZE);
	if (pUDGraph != NULL) {
		AddVertex(pUDGraph, 0);
		AddVertex(pUDGraph, 1);
		AddVertex(pUDGraph, 2);
		AddVertex(pUDGraph, 3);
		AddVertex(pUDGraph, 4);
		AddVertex(pUDGraph, 5);
		AddVertex(pUDGraph, 6);


		AddEdge(pUDGraph, 0, 1);
		AddEdge(pUDGraph, 0, 2);
		AddEdge(pUDGraph, 0, 3);
		AddEdge(pUDGraph, 1, 4);
		AddEdge(pUDGraph, 1, 5);
		AddEdge(pUDGraph, 2, 3);
		AddEdge(pUDGraph, 2, 6);
		AddEdge(pUDGraph, 3, 5);
		AddEdge(pUDGraph, 3, 6);
		DisplayEdge(pUDGraph);
		RemoveVertex(pUDGraph, 3);
		printf("RemoveVertex 3 \n");
		DisplayEdge(pUDGraph);

	}
	DeleteGraph(pUDGraph);
	return 0;

}