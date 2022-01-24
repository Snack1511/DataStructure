#include<stdio.h>
#include<stdlib.h>
#include"LnkGraph.h"
#include"UsedDataStructure.h"
#include"Graph_ShortPath.h"

/*
	return : �Ÿ����� ����迭(int �迭)
	input : �׷��� �ּ�, ���۳��

	����
	for(��ü���)
		������ �湮���� ������Ʈ
		while(���� �湮����� ��������Ʈ != NULL)
			if���۳�忡�� ������� �Ÿ� + ������忡�� �������� �Ÿ� < ���۳�忡�� ������
				���۳�忡�� ������ �ִܰŸ� = ���۳�忡�� ������� �Ÿ� + ������忡�� �������� �Ÿ�
			���� ����Ʈ ��� Ȯ��
*/
int* Dijkstra(Graph* pGraph, int StartVert) {
	
	int* pReturn = NULL;
	int* pSelected = NULL;
	int nodeCount = 0, MaxNodeCount = 0;
	int Weight = 0;

	int VertID = 0, y_w = 0, y_v = 0;

	LinkedNode* pNode = NULL;
	LinkedList* pList = NULL;
	// �ʿ亯�� ���� ------------ 

	MaxNodeCount = pGraph->maxLength;
	nodeCount = pGraph->curLength;

	pReturn = (int*)malloc(sizeof(int) * MaxNodeCount);
	pSelected = (int*)malloc(sizeof(int) * MaxNodeCount);

	if (pGraph == NULL) {
		printf("Graph is NULL\n");
		goto RETURN;
	}
	if (pReturn == NULL || pSelected == NULL) {
		if (pReturn != NULL) {
			printf("�޸� �Ҵ� ����\n");
		}
		pReturn = NULL;
		goto RETURN;
	}

	for (int i = 0; i < MaxNodeCount; i++) {
		if (i == StartVert) {
			pReturn[i] = 0;
		}
		else {
			if (pGraph->pVertex[i] == USED) {
				pSelected[i] = TRUE;
				pReturn[i] = getEdgeWeight(pGraph, StartVert, i);
			}
			else {
				pSelected[i] = TRUE;
				pReturn[i] = INF;
			}
		}
	}
	// ���� �ʱ�ȭ --------------
	
	for (int i = 0; i < MaxNodeCount; i++) {
		printf("%d, %d --> %d\n", StartVert, i, pReturn[i]);
	}
	// �ʱ�ȭ �� �Ÿ����� ��� -------------- 


	for (int i = 0; i < nodeCount - 1; i++) {
		printf("[%d] - ITERATION\n", i + 1);

		VertID = getMinDistance(pReturn, pSelected, MaxNodeCount); // ���۳��� �ִܰŸ��� ��� ��ȯ
		pSelected[VertID] = FALSE;

		pList = pGraph->ppAdjacentList[VertID];

		pNode = pList->headerNode.pNextNode;

		while (pNode != NULL) {
			int ToVert = pNode->data.vertID;
			int weight = pNode->data.weight;

			y_v = pReturn[VertID]; // ��ǥ��� ���� ������������ �ִܰŸ�
			y_w = pReturn[ToVert]; // ���۳�忡�� ��ǥ�������� �Ÿ�

			if (y_v + weight < y_w) { 
				// (i ~ ��ǥ���������� �Ÿ� + ������忡�� ��ǥ���� �Ÿ�) <  ���۳�� ~ ��ǥ �Ÿ�
				pReturn[ToVert] = y_v + weight;
			}

			pNode = pNode->pNextNode;
		}

		// ���ͽ�Ʈ��˰��� ���� ���� �ݺ� ----------------

		for (int j = 0; j < MaxNodeCount; j++) {
			printf("\t%d, %d --> %d\n", StartVert, j, pReturn[j]);
		}
		// �ݺ� ���� �� �ش� ����� ���� ��� -------------- 
	}

	free(pSelected);


	RETURN:
	return pReturn;
}

int getMinDistance(int* distance, int* isSelected, int maxNode) {

}
int getEdgeWeight(Graph* pGraph, int Invert, int OutVert);

int** Floyd(Graph* pGraph) {
	int** pReturn = NULL;
	int weight = 0;
	int maxNodeCount = 0;

	if (pGraph == NULL) {
		printf("Graph is NULL\n");
		return NULL;
	}
	maxNodeCount = pGraph->maxLength;//pGraph�� �ִ��尳�� Ȯ��

	pReturn = (int**)malloc(sizeof(int*) * maxNodeCount);
	if (pReturn == NULL) {
		printf("pReturn �޸� �Ҵ� ����\n");
		return NULL;
	}//��ȯ�� ������ ���� �޸� �Ҵ� �� ����, 2���� �迭

	for (int i = 0; i < maxNodeCount; i++) {
		pReturn[i] = (int*)malloc(sizeof(int) * maxNodeCount);

		if (pReturn[i] == NULL) {
			printf("pReturn[%d] �޸� �Ҵ� ����", i);
			return NULL;
		}
	}//��ȯ�� ����, ������ ���鼭 ���� 1�����迭�� ������

	//�ʱ�ȭ. �迭pReturn�� �ʱ�ȭ
	for (int i = 0; i < maxNodeCount; i++) {
		for (int j = 0; j < maxNodeCount; j++) {
			if (i == j) {
				pReturn[i][j] = 0;
			}
			else {
				pReturn[i][j] = getEdgeWeight(pGraph, i, j);
			}
		}
	}//�� ��� ������ �Ÿ��� �ʱ�ȭ, �� ��带 ��������ִ� ������ ����ġ ���� �̿�

	PrintMatrix(pReturn, maxNodeCount);

	//step1. ���� ����
	for (int i = 0; i < maxNodeCount; i++) {//v
		for (int j = 0; j < maxNodeCount; j++) {//r
			for (int k = 0; k < maxNodeCount; k++) {//s
				if (pReturn[j][i] + pReturn[i][k] < pReturn[j][k]) {
					pReturn[j][k] = pReturn[j][i] + pReturn[i][k];
				}
			}
		}
		printf("[%d] - ����\n", i + 1);
	}//���߷����� ���鼭 �ִܰŸ� ������ ����

	return pReturn;
}

void PrintPath(Queue* pPath) {
	if (pPath != NULL) {
		printf("Path : ");
		while (IsQueueEmpty(pPath) == FALSE) {
			printf("%d    ", Dequeue(pPath)->data);
		}
		printf("\n");
	}
}