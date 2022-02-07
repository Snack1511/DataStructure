#include "BinSearch.h"

int BinSearch(int* iArr, int iValue, int MaxLength) {
	int iReturn = 0;
	int iMid = (MaxLength / 2) - 1;
	while (MaxLength > iMid + 1 && 0 < iMid && iValue != iArr[iMid]) {
		if (iValue > iArr[iMid]) {
			iMid = ((MaxLength + iMid) / 2) + 1;
		}
		else if (iValue < iArr[iMid]) {
			iMid = iMid / 2;
		}
	}
	if (iValue == iArr[iMid]) {
		iReturn = iMid;
	}
	else {
		printf("인덱스 범위 초과\n");
		iReturn = - 1;
	}
	return iReturn;
}