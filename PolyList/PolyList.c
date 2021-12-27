#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"PolyList.h"
void addLastElement(LinkedList* pList, int Degree, float Coef) {
	LinkedNode* pNode = NULL, *pNewNode = NULL;
	pNewNode = (LinkedNode*)malloc(sizeof(LinkedNode));
	if (pNewNode != NULL) {
		memset(pNewNode, 0, sizeof(LinkedNode));
		pNewNode->coef = Coef;
		pNewNode->degree = Degree;
		pNewNode->pNextNode = NULL;
	}
	else {
		printf("pNewNode is NULL\n");
	}
	if (pList != NULL) {
		pNode = &(pList->headerNode);
		while (pNode->pNextNode != NULL) {
			pNode = pNode->pNextNode;
		}
		pNode->pNextNode = pNewNode;
		pList->currentElementCount++;
	}
}
LinkedList* addPolyList(LinkedList* pListA, LinkedList* pListB) {
	int DegreeA=0, DegreeB = 0;
	float CoefSum = 0;
	LinkedList* pReturn = NULL;
	pReturn = (LinkedList*)malloc(sizeof(LinkedList));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedList));
	}
	LinkedNode* pNodeA = NULL, * pNodeB = NULL;
	if (pListA != NULL && pListB != NULL) {
		pNodeA = pListA->headerNode.pNextNode;
		pNodeB = pListB->headerNode.pNextNode;
		while (pNodeA != NULL && pNodeB != NULL) {
			DegreeA = pNodeA->degree;
			DegreeB = pNodeB->degree;
			if (DegreeA > DegreeB) {
				CoefSum = pNodeA->coef;
				addLastElement(pReturn, DegreeA, CoefSum);
				pNodeA = pNodeA->pNextNode;
				
			}
			else if (DegreeA < DegreeB) {
				CoefSum = pNodeB->coef;
				addLastElement(pReturn, DegreeB, CoefSum);
				pNodeB = pNodeB->pNextNode;
				
			}
			else {
				CoefSum = pNodeA->coef + pNodeB->coef;
				addLastElement(pReturn, DegreeA, CoefSum);
				pNodeA = pNodeA->pNextNode;
				pNodeB = pNodeB->pNextNode;

			}
		}
		while (pNodeA != NULL) {
			DegreeA = pNodeA->degree;
			CoefSum = pNodeA->coef;
			addLastElement(pReturn, DegreeA, CoefSum);
			pNodeA = pNodeA->pNextNode;
		}
		while (pNodeB != NULL) {
			DegreeB = pNodeB->degree;
			CoefSum = pNodeB->coef;
			addLastElement(pReturn, DegreeB, CoefSum);
			pNodeB = pNodeB->pNextNode;
		}
	}

	return pReturn;
}

void DisPlayPoly(LinkedList* pList) {
	LinkedNode* pNode = NULL;
	if (pList != NULL) {
		pNode = pList->headerNode.pNextNode;
		for (int i = 0; i < pList->currentElementCount; i++) {
			if (pNode->degree > 0) {
				printf("%4.1fx^%d", pNode->coef, pNode->degree);
			}
			else {
				printf("%4.1f", pNode->coef);
				
			}
			if (pNode->pNextNode != NULL) {
				printf(" + ");
			}
			else {
				printf("\n");
			}
			pNode = pNode->pNextNode;
		}
	}
}