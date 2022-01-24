#ifndef _SHORTPATH_
#define _SHORTPATH_
#define INF 99999999


int* Dijkstra(Graph* pGraph, int iStartVert);
int** Floyd(Graph* pGraph);
int getMinDistance(int* distance, int* isSelected, int maxNode);
int getEdgeWeight(Graph* pGraph, int Invert, int OutVert);
void PrintPath(Queue* pPath);
void PrintMatrix(int** A, int maxlength);

#endif