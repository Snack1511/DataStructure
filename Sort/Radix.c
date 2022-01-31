#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "UsedDataStructure.h"
#define MAX 20

void RadixSort(int* Arr);
void Swap(int* pTarget_A, int* pTarget_B);
void PrintArr(int* Arr, int length);
int main() {
	srand((unsigned)time(NULL));
	int arr[MAX]; //= { 10, 70, 23, 60, 20, 40, 30, 50 };
	int* ptest = NULL;
	for (int i = 0; i < 10; ++i) {
		printf("%dÈ¸Â÷ ===============\n", i);
		for (int i = 0; i < MAX; ++i) {
			arr[i] = (i + rand()) % (MAX * 6);
		}
		PrintArr(arr, MAX);
		RadixSort(arr);
		PrintArr(arr, MAX);
	}
	return 0;
}

void RadixSort(int* pArr) {
	Queue* RadixQueueArr[10] = {NULL};
	QueueNode Node = {0};
	int MaxElement = pArr[0];
	int RadixCount = 0;
	
	int DevideTen = 1;
	for (int i = 1; i < MAX; ++i) {
		if (MaxElement < pArr[i]) {
			MaxElement = pArr[i];
		}
	}
	while (0 < MaxElement) {
		MaxElement /= 10;
		++RadixCount;
	}
	while (RadixCount > 0) {
		DevideTen = 1;
		for (int i = 0; i < 3 - RadixCount; ++i) {
			DevideTen *= 10;
		}
		for (int i = 0; i < MAX; ++i) {
			Node.data = pArr[i];
			if (RadixQueueArr[(Node.data / DevideTen) % 10] == NULL) {
				RadixQueueArr[(Node.data / DevideTen) % 10] = CreateQueue();
			}
			Enqueue(RadixQueueArr[(Node.data/DevideTen) % 10], Node);
		}
		int ArrIdx = 0;
		for (int i = 0; i < 10; ++i) {
			if (RadixQueueArr[i] != NULL) {
				while (IsQueueEmpty(RadixQueueArr[i]) == FALSE) {
					pArr[ArrIdx] = Dequeue(RadixQueueArr[i])->data;
					++ArrIdx;
				}
			}
			
		}
		PrintArr(pArr, MAX);

		--RadixCount;
	}
	for (int i = 0; i < 10; ++i) {
		DeleteQueue(RadixQueueArr[i]);
	}
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
