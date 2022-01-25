#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 20
void QuickSort(int* Arr, int start, int end);
void PrintArr(int* Arr, int length);
int main() {
	srand((unsigned)time(NULL));
	int arr[MAX]; //= { 10, 70, 23, 60, 20, 40, 30, 50 };
	int* ptest = NULL;
	for (int i = 0; i < MAX; ++i) {
		arr[i] = (i + rand())%MAX;
	}
	PrintArr(arr, MAX);
	QuickSort(arr, 0, MAX-1);
	PrintArr(arr, MAX);
	return 0;
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

		PrintArr(Arr, MAX-1);

		QuickSort(Arr, left, rightidx -1);
		QuickSort(Arr, rightidx, right);
	}
}

void PrintArr(int* Arr, int length) {
	for (int i = 0; i < length; ++i) {
		printf("%d ", Arr[i]);
		if ((i + 1) % 10 == 0) {
			printf("\n");
		}
	}
	printf("\n\n");

}