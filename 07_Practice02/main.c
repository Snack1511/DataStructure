#include<stdio.h>
#include<stdlib.h>

#include"LinkedListMaxHeap.h"

void DisplayHeap(Heap* pHeap) {
	Node* pNode = NULL;
	if (pHeap != NULL) {
		pNode = pHeap->Root;
		for (int i = 0; i < pHeap->currentLength; i++) {
			printf("[%d] %d    ", i, pNode->key);
			pNode = pNode->pLink;
		}
		printf("\n");
	}
}

int main() {

	Heap* pHeap = NULL;

	Node* pNode = NULL;
	Node e1 = { 10 };
	Node e2 = { 20 };
	Node e3 = { 30 };
	Node e4 = { 4 };
	Node e5 = { 17 };
	Node e6 = { 15 };
	Node e7 = { 22 };
	Node e8 = { 35 };
	Node e9 = { 49 };
	Node e10 = { 5 };

	pHeap = CreateHeap();
	if (pHeap != NULL) {
		InsertHeapNode(pHeap, e1);
		InsertHeapNode(pHeap, e2);
		InsertHeapNode(pHeap, e3);
		InsertHeapNode(pHeap, e4);
		InsertHeapNode(pHeap, e5);
		InsertHeapNode(pHeap, e6);
		InsertHeapNode(pHeap, e7);
		InsertHeapNode(pHeap, e8);
		InsertHeapNode(pHeap, e9);
		InsertHeapNode(pHeap, e10);

		printf("MaxHeap : ");
		DisplayHeap(pHeap);
		pNode = DeleteHeapNode(pHeap);
		if (pNode != NULL) {
			printf("DeleteHeap : %d\n", pNode->key);
			free(pNode);
		}
		printf("MaxHeap : ");
		DisplayHeap(pHeap);

		/*
		pNode = DeleteHeapNode(pHeap);
		if (pNode != NULL) {
			printf("DeleteHeap : %d\n", pNode->key);
			free(pNode);
		}
		printf("MaxHeap : ");
		DisplayHeap(pHeap);

		pNode = DeleteHeapNode(pHeap);
		if (pNode != NULL) {
			printf("DeleteHeap : %d\n", pNode->key);
			free(pNode);
		}
		printf("MaxHeap : ");
		DisplayHeap(pHeap);
		*/
		DeleteHeap(pHeap);
	}
	return 0;
}