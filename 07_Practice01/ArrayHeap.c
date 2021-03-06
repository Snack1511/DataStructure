#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ArrayHeap.h"

Heap* CreateHeap(int MaxLength) {
	Heap* pReturn = NULL;
	pReturn = (Heap*)malloc(sizeof(Heap));
	if (pReturn != NULL) {
		if (MaxLength > 0) {
			pReturn->HeapArray = (HeapNode*)malloc(sizeof(HeapNode) * (MaxLength+1));
			if (pReturn->HeapArray != NULL) {
				memset(pReturn->HeapArray, 0, sizeof(HeapNode) * (MaxLength + 1));
				pReturn->maxLength = (MaxLength + 1);
				pReturn->currentLength = 0;
			}
		}
	}


	return pReturn;
}
void DeleteHeapArray(Heap* pHeap) {
	if (pHeap != NULL) {
		free(pHeap->HeapArray);
	}
	free(pHeap);
}
void InsertHeapNode(Heap* pHeap, HeapNode node) {
	HeapNode tmp;
	int idx = 0;
	if (pHeap != NULL) {
		pHeap->HeapArray[pHeap->currentLength+1] = node;
		pHeap->currentLength++;
		idx = pHeap->currentLength - 1;
		while (idx > 1) {
			if (pHeap->HeapArray[idx / 2].key > pHeap->HeapArray[idx].key) {
				tmp = pHeap->HeapArray[idx / 2];
				pHeap->HeapArray[idx / 2] = pHeap->HeapArray[idx];
				pHeap->HeapArray[idx] = tmp;
			}
			idx /= 2;
		}
	}
}
HeapNode* DeleteHeap(Heap* pHeap) {
	HeapNode* pReturn = NULL;

	HeapNode tmp = {0};
	int idx = 0, CmpIdx = 0;
	if (pHeap != NULL) {
		pReturn = (HeapNode*)malloc(sizeof(HeapNode));
		if (pReturn != NULL) {
			*pReturn = pHeap->HeapArray[1];
		}
		pHeap->HeapArray[1] = pHeap->HeapArray[pHeap->currentLength - 1];
		pHeap->HeapArray[pHeap->currentLength - 1] = tmp;
		pHeap->currentLength--;
		idx = 1;
		while (idx <= pHeap->currentLength && idx <= pHeap->currentLength / 2) {
			if (pHeap->HeapArray[(idx * 2) + 1].key < pHeap->HeapArray[(idx * 2)].key) {
				CmpIdx = (idx * 2) + 1;
			}
			else {
				CmpIdx = (idx * 2);
			}
			if (pHeap->HeapArray[CmpIdx].key < pHeap->HeapArray[idx].key) {
				tmp = pHeap->HeapArray[idx];
				pHeap->HeapArray[idx] = pHeap->HeapArray[CmpIdx];
				pHeap->HeapArray[CmpIdx] = tmp;
			}
			idx = CmpIdx;
		}
	}

	return pReturn;
}