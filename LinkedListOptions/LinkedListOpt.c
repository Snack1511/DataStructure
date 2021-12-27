#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkedListOpt.h"


void iterateLinkedList(LinkedList* pList) {
	LinkedNode* pNode;
	int count = 0;
	if (pList != NULL) {
		pNode = &(pList->headerNode);
		pNode = pNode->pNextNode;
		while (pNode != NULL) {
			printf("[%d] %d   ", count, pNode->data);
			count++;
			pNode = pNode->pNextNode;
		}
		printf("\n");
		printf("Total Count : %d\n", count);
	}
}
void concatLinkedList(LinkedList* pListA, LinkedList* pListB) {
	LinkedNode* pNodeA;
	int ListBLength = 0;
	ListBLength = pListB->currentElementCount;
	if (pListA != NULL) {
		pNodeA = &(pListA->headerNode);
		while (pNodeA->pNextNode != NULL) {
			pNodeA = pNodeA->pNextNode;
		}
		pNodeA->pNextNode = pListB->headerNode.pNextNode;
		pListA->currentElementCount += ListBLength;
		pListB->headerNode.pNextNode = NULL;
		pListB->currentElementCount = 0;
	}
}
void reverseLinkedList(LinkedList* pList) {
	LinkedNode* pPrevNode = NULL,* pCurrentNode=NULL, * pNode=NULL;
	if (pList != NULL) {
		pNode = pList->headerNode.pNextNode;
		while (pNode != NULL) {
			pPrevNode = pCurrentNode;
			pCurrentNode = pNode;
			pNode = pNode->pNextNode;
			pCurrentNode->pNextNode = pPrevNode;
		}
		pList->headerNode.pNextNode = pCurrentNode;
	}
}