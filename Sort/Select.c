#include<stdio.h>

int BubbleSort(int* Arr, int length);
void PrintArr(int* Arr, int length);
int main() {

	int arr[8] = { 30,10, 23,  60, 20, 70, 40, 50 };//32
	int* ptest = NULL;

	int SortSuccess = 0;
	SortSuccess = BubbleSort(arr, 8);//32
	PrintArr(arr, 8);
	return 0;
}

int BubbleSort(int* Arr, int length) {
	int ret = 0;
	int tmp = 0;
	for (int i = 0; i < length; ++i) {
		for (int j = i; j < length; ++j) {
			if (Arr[i] > Arr[j]) {
				tmp = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = tmp;
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