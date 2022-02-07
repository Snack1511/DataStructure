#include<string.h>
#include "HashTable.h"
// 해시테이블 생성 -> 배열, 연결리스트
HashTable* CreateHashTable(int MaxLength) {
	HashTable* pReturn = (HashTable*)malloc(sizeof(HashTable));

	int iMemsize = sizeof(int) * (MaxLength + 1);
	pReturn->MaxLength = (MaxLength + 1);
	pReturn->pArrHashTable = (int*)malloc(iMemsize);

	memset(pReturn->pArrHashTable, 0, iMemsize);

	for (int i = 0; i < pReturn->MaxLength; ++i) {
		pReturn->pArrHashTable[i] = -1;
	}

	return pReturn;
}

int SetHashIndex(HashTable* pHashTable, int iValue) {
	int iReturn = 0;
	int MaxLength = pHashTable->MaxLength;
	while (iValue > 0) {
		iReturn += (iValue % MaxLength);
		iValue /= MaxLength;
	}
	iReturn %= MaxLength;
	
	return iReturn;
}
int ReleaseCollision(HashTable* pHashTable, int iIndex) {
	int iReturn = 0;
	int iDest = 0;
	int iCnt = 0;
	while (-1 != pHashTable->pArrHashTable[iIndex] && pHashTable->MaxLength > iCnt) {
		iDest = DoubleHashingDest(iIndex, pHashTable->MaxLength);
		iIndex = (iIndex + iDest) % pHashTable->MaxLength;
		++iCnt;
	}
	iReturn = iIndex;
	return iReturn;
}
int DoubleHashingDest(int iIndex, int iTableSize) {
	int iReturn = 0;

	iReturn = iTableSize - (iIndex % iTableSize);
	return iReturn;
}

// 해시테이블 자료 추가
void InsertHashElement(HashTable* pHashTable, int iValue, int iKey) {
	int iIndex = SetHashIndex(pHashTable, iValue);

	iIndex = ReleaseCollision(pHashTable, iIndex);

	pHashTable->pArrHashTable[iIndex] = iKey;
}

// 해시테이블 자료 검색
int GetHashIndex(HashTable* pHashTable, int* pArr, int iValue) {
	int Index = SetHashIndex(pHashTable, iValue);
	int iCnt = 0;
	int iDest = 0;
	while (iValue != pArr[pHashTable->pArrHashTable[Index]] && pHashTable->MaxLength > iCnt) {
		iDest = DoubleHashingDest(Index, pHashTable->MaxLength);
		Index = (Index + iDest) % pHashTable->MaxLength;
		++iCnt;
	}

	if (pHashTable->MaxLength <= iCnt) {
		printf("인덱스 범위 초과 \n");
		Index = -1;
	}

	return pHashTable->pArrHashTable[Index];
}

// 해시테이블 자료 삭제
void DeleteHashElement(HashTable* pHashTable, int key);

void DeleteHashTable(HashTable* pHashTable) {

	free(pHashTable->pArrHashTable);

	free(pHashTable);
}