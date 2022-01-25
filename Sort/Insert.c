#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 20
void InsertSort(int* Arr, int length);
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
	InsertSort(arr, MAX);
	PrintArr(arr, MAX);
	return 0;
}

void InsertSort(int* Arr, int length) {
	for (int i = 1; i < length; ++i) {
		for (int j = i; j >= 1; --j) {
			if (Arr[j] < Arr[j - 1]) {
				Swap(Arr + j, Arr + (j - 1));
				PrintArr(Arr, length);
				
			}
		}
	}
	PrintArr(Arr, length);
}
void Swap(int* pTarget_A, int* pTarget_B) {
	int tmp = 0;
	tmp = *pTarget_A;
	*pTarget_A = *pTarget_B;
	*pTarget_B = tmp;
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
