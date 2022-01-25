#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 20
void ShellSort(int* Arr, int length);
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
	ShellSort(arr, MAX);
	PrintArr(arr, MAX);
	return 0;
}

void ShellSort(int* Arr, int length) {
	

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
