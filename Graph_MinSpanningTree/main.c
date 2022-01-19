#include<stdio.h>
#include<stdlib.h>
#include"LnkGraph.h"
#include"GraphTravelsal.h"

#define MAXGRAPHSIZE 6

int main() {
	Graph* pG = CreateGraph(MAXGRAPHSIZE);
	Graph* pMST_Kruskal = NULL;

	if (pG != NULL) {
		for (int i = 0; i < MAXGRAPHSIZE; i++) {
			AddVertex(pG, i);
		}

		AddEdgeWeigt(pG, 0, 1, 4);
		AddEdgeWeigt(pG, 0, 2, 3);
		AddEdgeWeigt(pG, 1, 2, 2);
		AddEdgeWeigt(pG, 2, 3, 1);
		AddEdgeWeigt(pG, 3, 4, 1);
		AddEdgeWeigt(pG, 3, 5, 5);
		AddEdgeWeigt(pG, 4, 5, 6);


		printf("G : \n");
		DisplayEdge(pG);

	}
	

	return 0;
}