#include<stdio.h>
int QuickSort(int* Arr, int start, int end);
void PrintArr(int* Arr, int length);
int main() {

	int arr[8] = { 70, 40, 30, 10, 23, 60, 20, 50 };//32
	int* ptest = NULL;

	int SortSuccess = 0;
	SortSuccess = QuickSort(arr, 0, 8);//32
	PrintArr(arr, 8);
	return 0;
}

int QuickSort(int* Arr, int left, int right) {
	int pivot = left;
	for (int i = left; i < right; ++i) {
		if (Arr[pivot] < Arr[i]) {

		}
	}

}

void PrintArr(int* Arr, int length) {
	for (int i = 0; i < length; ++i) {
		printf("%d      ", Arr[i]);
	}
	printf("\n");
}