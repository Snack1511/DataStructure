#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "UsedDataStructure.h"
#define MAX 20

void HeapSort(int* Arr);
void Swap(int* pTarget_A, int* pTarget_B);
void PrintArr(int* Arr, int length);
int main() {
	srand((unsigned)time(NULL));
	int arr[MAX] = { 113, 13, 21, 44, 17, 2, 82, 80, 65, 87, 72, 21, 58, 55, 79, 60, 71, 12, 79, 14 };
	for (int i = 0; i < 1; ++i) {
		printf("%dÈ¸Â÷ ===============\n", i);
		for (int i = 0; i < MAX; ++i) {
			//arr[i] = (i + rand()) % (MAX * 6);
		}
		
		PrintArr(arr, MAX);
		HeapSort(arr);
		PrintArr(arr, MAX);
	}
	return 0;
}

void HeapSort(int* pArr) {
	Heap* pTmpHeap = CreateHeap();
	HeapNode Heapnode = {0};
	for (int i = 0; i < MAX; ++i) {
		Heapnode.key = pArr[i];
		InsertHeapNode(pTmpHeap, Heapnode);
	}
	DisplayHeap(pTmpHeap);
	int ArrIdx = 0;
	while (IsHeapEmpty(pTmpHeap) == FALSE) {
		pArr[ArrIdx] = DeleteHeapNode(pTmpHeap)->key;
		DisplayHeap(pTmpHeap);
		++ArrIdx;
	}
	DeleteHeap(pTmpHeap);
}
void Swap(int* pTarget_A, int* pTarget_B) {
	int tmp = 0;
	tmp = *pTarget_A;
	*pTarget_A = *pTarget_B;
	*pTarget_B = tmp;
}

void PrintArr(int* Arr, int length) {
	for (int i = 0; i < length; ++i) {
		printf("%2d ", Arr[i]);
		if ((i + 1) % 10 == 0) {
			printf("\n");
		}
	}
	printf("\n\n");

}
