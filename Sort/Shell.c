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
	
	for (int demp = length; demp > 0; demp = demp / 2) {
		printf("Demp : %d ===================================\n", demp);
		for (int i = 1; i <= demp && demp < length; ++i) {
			printf("[%d] ------------- \n", i);
			for (int j = length - i; j >= demp; j = j - demp) {
				if (Arr[j - demp] > Arr[j]) {
					Swap(Arr + j, Arr + (j - demp));
					PrintArr(Arr, length);
					j = length - i;
				}
			}
		}
	}
}//π∫∞°...π∫∞° ¿ÃªÛ«‘...
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
