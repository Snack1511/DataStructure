#include<stdio.h>
#include<time.h>
#include"BinSearch.h"
#define MAXSIZE 10

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
	for (int i = 0; MAXSIZE > i; ++i) {
		Arr[i] = rand() % MAXSIZE;
	}
	int iTargetIdx = 0;
	QuickSort(Arr, 0, MAXSIZE - 1);
	for (int i = 0; MAXSIZE > i; ++i) {
		printf("%d   ", Arr[i]);
	}
	printf("\n\n");
	iTargetIdx = BinSearch(Arr, 5, MAXSIZE);
	printf("[%d]  %d\n", iTargetIdx, Arr[iTargetIdx]);


	return 0;
}