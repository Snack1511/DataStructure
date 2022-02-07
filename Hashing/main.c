#include<stdio.h>
#include<time.h>
#include"HashTable.h"
#define MAXSIZE 10

void Swap(int* pA, int* pB) {
	int tmp = *pA;
	*pA = *pB;
	*pB = tmp;
}

void QuickSort(int* Arr, int left, int right) {
	int pivot = left;
	int rightidx = right, leftidx = pivot + 1;
	int tmp = 0;
	if (left < right) {
		while (rightidx > leftidx) {

			if (Arr[leftidx] > Arr[rightidx]) {
				tmp = Arr[rightidx];
				Arr[rightidx] = Arr[leftidx];
				Arr[leftidx] = tmp;
			}
			else {
				if (Arr[pivot] > Arr[leftidx]) {
					leftidx++;
				}
				if (Arr[pivot] <= Arr[rightidx]) {
					rightidx--;
				}
			}
		}
		if (Arr[rightidx] < Arr[pivot]) {
			tmp = Arr[rightidx];
			Arr[rightidx] = Arr[pivot];
			Arr[pivot] = tmp;
		}


		QuickSort(Arr, left, rightidx - 1);
		QuickSort(Arr, rightidx, right);
	}
}

int main() {
	srand((unsigned)time(NULL));

	int Arr[MAXSIZE];
	HashTable* pArrHashTable = CreateHashTable(MAXSIZE);

	for (int i = 0; MAXSIZE > i; ++i) {
		Arr[i] = i + (rand() % MAXSIZE + i) ;
	}
	for (int i = 0; i < MAXSIZE; ++i) {
		Swap(Arr+i, Arr + rand() % MAXSIZE);
	}
	for (int i = 0; i < MAXSIZE; ++i) {
		InsertHashElement(pArrHashTable, Arr[i], i);
	}
	int iTargetIdx = 0;
	//QuickSort(Arr, 0, MAXSIZE - 1);
	for (int i = 0; MAXSIZE > i; ++i) {
		printf("%d   ", Arr[i]);
	}
	printf("\n\n");
	int iSearchValue = 0;
	printf("Ž���� �� �Է� : ");
	scanf_s("%d", &iSearchValue);
	iTargetIdx = GetHashIndex(pArrHashTable, Arr, iSearchValue);
	printf("[%d]  %d\n", iTargetIdx, Arr[iTargetIdx]);

	DeleteHashTable(pArrHashTable);

	return 0;
}