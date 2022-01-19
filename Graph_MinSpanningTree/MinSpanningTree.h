#ifndef _MINSPANNINGTREEE_
#define _MINSPANNINGTREEE_
Graph* Kruskal(Graph *pGraph);
int AddEdgeWeightHeapNode(Graph* pGraph, HeapNode* pNode);
int FindCycle(Graph pGraph, HeapNode Node);
int IsAllVertexConnect(Graph *pGraph);
#endif