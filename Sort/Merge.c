#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 20

int tmpArr[MAX] = {0};

void MergeSort(int* Arr, int length, int StartIdx);
void Swap(int* pTarget_A, int* pTarget_B);
void PrintArr(int* Arr, int length);
int main() {
	srand((unsigned)time(NULL));
	int arr[MAX]; //= { 10, 70, 23, 60, 20, 40, 30, 50 };
	int* ptest = NULL;
	for (int i = 0; i < MAX; ++i) {
		arr[i] = (i + rand()) % MAX;
	}
	PrintArr(arr, MAX);
	MergeSort(arr, MAX, 0);
	PrintArr(arr, MAX);
	return 0;
}

void MergeSort(int* Arr, int length, int StartIdx) {
	int mid = (length+StartIdx) / 2;
	int i = StartIdx, j = mid;
	int k = StartIdx;
	if (mid > StartIdx && length > mid) {
		MergeSort(Arr, mid, StartIdx);
		MergeSort(Arr, length, mid);
	}//분할

	while (length > j && mid > i) {
		if (Arr[i] < Arr[j]) {
			tmpArr[k] = Arr[i];
			++k;
			++i;
		}
		else {
			tmpArr[k] = Arr[j];
			++k;
			++j;
		}
	}

	while (mid > i) {
		tmpArr[k] = Arr[i];
		++k;
		++i;
	}
	while (length > j) {
		tmpArr[k] = Arr[j];
		++k;
		++j;
	}
	// 정복
	
	for (int i = StartIdx; i < length; ++i) {
		Arr[i] = tmpArr[i];
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
