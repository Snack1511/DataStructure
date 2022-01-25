#include<stdio.h>
int BubbleSort(int* Arr, int length);
void PrintArr(int* Arr, int length);
int main() {

	int arr[8] = { 70, 40, 30, 10, 23, 60, 20, 50 };//32
	int* ptest = NULL;

	int SortSuccess = 0;
	SortSuccess = BubbleSort(arr, 8);//32
	PrintArr(arr, 8);
	return 0;
}

int BubbleSort(int* Arr, int length) {
	int ret = 0;
	int tmp = 0;
	for (int i = length - 1; i >= 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (Arr[j] > Arr[j + 1]) {
				tmp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = tmp;
			}
		}
		PrintArr(Arr, length);
	}
}

void PrintArr(int* Arr, int length) {
	for (int i = 0; i < length; ++i) {
		printf("%d      ", Arr[i]);
	}
	printf("\n");
}