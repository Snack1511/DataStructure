#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"
#include"UsedDataStruct.h"
#include"LnkGraph.h"
#include"ArrayHeap.h"
#include"MinSpanningTree.h"

#define MAXGRAPHSIZE 6

int main() {
	Graph* pG = CreateGraph(MAXGRAPHSIZE);
	Graph* pMST_Kruskal = NULL;
	Graph* pMST_Prim = NULL;
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
		printf("Kruskal : \n");
		pMST_Kruskal = Kruskal(pG);
		DisplayEdge(pMST_Kruskal);

		printf("Prim : \n");
		pMST_Prim = Prim(pG);
		DisplayEdge(pMST_Prim);

	}
	

	return 0;
}