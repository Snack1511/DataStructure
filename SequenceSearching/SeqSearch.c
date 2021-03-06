#include"SeqSearch.h"

int InOrderedSeqSearch(int Arr[], int MaxLength, int idx) {
	int ret = 0;
	for (ret = 0; ret < MaxLength; ++ret) {
		if (Arr[ret] == idx) {
			break;
		}
	}
	if (ret >= MaxLength) {
		printf("인덱스 범위 초과\n");
		ret = -1;
	}
	return ret;
}
int OrderedSeqSearch(int Arr[], int MaxLength, int idx) {
	if (idx > Arr[MaxLength - 1]) {
		printf("인덱스 범위 초과\n");
		return -1;
	}

	int ret = 0, EndSearchIdx = MaxLength/2;
	if (idx >= Arr[EndSearchIdx]) {
		ret = MaxLength / 2;
		EndSearchIdx = MaxLength;
	}
	else {
		ret = 0;
	}


	while (ret < EndSearchIdx) {
		if (Arr[ret] >= idx) {
			if (Arr[ret] == idx) {
				break;

			}
			else {
				printf("인덱스 범위 초과\n");
				return -1;
			}
		}
		++ret;
	}
	return ret;
}