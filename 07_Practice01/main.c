#include<stdio.h>
#include<stdlib.h>

#include"ArrayHeap.h"
/*
	ÃÖ¼ÒÈü
*/
void DisplayHeap(Heap* pHeap) {
	if (pHeap != NULL) {
		for (int i = 1; i < pHeap->currentLength; i++) {
			printf("[%d] %d    ", i, pHeap->HeapArray[i].key);
		}
		printf("\n");
	}
}

int main() {
	int maxHeapSize = 20;

	Heap* pHeap = NULL;
	
	HeapNode* pNode = NULL;
	HeapNode e1 = { 10 };
	HeapNode e2 = { 20 };
	HeapNode e3 = { 30 };
	HeapNode e4 = { 4 };
	HeapNode e5 = { 17 };
	HeapNode e6 = { 15 };
	HeapNode e7 = { 22 };
	HeapNode e8 = { 35 };
	HeapNode e9 = { 49 };
	HeapNode e10 = { 5 };

	pHeap = CreateHeap(maxHeapSize);
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

		printf("MinHeap : ");
		DisplayHeap(pHeap);
		
		pNode = DeleteHeap(pHeap);
		if (pNode != NULL) {
			printf("DeleteHeap : %d\n", pNode->key);
			free(pNode);
		}
		printf("MinHeap : ");
		DisplayHeap(pHeap);

		pNode = DeleteHeap(pHeap);
		if (pNode != NULL) {
			printf("DeleteHeap : %d\n", pNode->key);
			free(pNode);
		}
		printf("MinHeap : ");
		DisplayHeap(pHeap);

		pNode = DeleteHeap(pHeap);
		if (pNode != NULL) {
			printf("DeleteHeap : %d\n", pNode->key);
			free(pNode);
		}
		printf("MinHeap : ");
		DisplayHeap(pHeap);
		
		DeleteHeapArray(pHeap);
	}
	return 0;
}