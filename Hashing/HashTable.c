#include<string.h>
#include "HashTable.h"
// 해시테이블 생성 -> 배열, 연결리스트
HashTable* CreateHashTable(int MaxLength) {
	HashTable* pReturn = (HashTable*)malloc(sizeof(HashTable));

	int iMemsize = sizeof(int) * MaxLength;
	pReturn->MaxLength = MaxLength;
	pReturn->pArrHashTable = (int*)malloc(iMemsize);

	memset(pReturn->pArrHashTable, 0, iMemsize);

	return pReturn;
}

int SetHashIndex(HashTable* pHashTable, int iValue) {
	int iReturn = 0;
	int MaxLength = pHashTable->MaxLength;
	while (iValue > 0) {
		iReturn += (iValue / MaxLength);
		iValue %= MaxLength;
	}
	iReturn %= MaxLength;
	return iReturn;
}
int ReleaseCollision(HashTable* pHashTable, int* pIndex) {
	int iReturn = 0;

	return iReturn;
}

// 해시테이블 자료 추가
void InsertHashElement(HashTable* pHashTable, int iValue, int iKey) {
	int iIndex = SetHashIndex(pHashTable, iValue);
	if (1 == ReleaseCollision(pHashTable, &iIndex)) {
		pHashTable->pArrHashTable[iIndex] = iKey;
	}
	else {
		printf("테이블에 빈공간 없음\n");
	}
}

// 해시테이블 자료 검색
int GetHashIndex(HashTable* pHashTable, int iValue);

// 해시테이블 자료 삭제
void DeleteHashElement(HashTable* pHashTable, int key);