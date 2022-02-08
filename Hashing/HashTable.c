#include<string.h>
#include "HashTable.h"
// �ؽ����̺� ���� -> �迭, ���Ḯ��Ʈ
HashTable* CreateHashTable(int MaxLength) {
	HashTable* pReturn = (HashTable*)malloc(sizeof(HashTable));

	int iMemsize = sizeof(int) * (MaxLength);
	pReturn->MaxLength = (MaxLength);
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
	int iIndexReturn = (iValue * iValue) + iValue;
	while (iIndexReturn > 0) {
		iReturn += (iIndexReturn % 23);
		iIndexReturn /= 23;
	}
	iReturn %= MaxLength;
	
	return iReturn;
}
int ReleaseCollision(HashTable* pHashTable, int iIndex) {
	int iReturn = 0;
	int iDest = 0;
	int iCnt = 0;
	iReturn = iIndex;
	while (-1 != pHashTable->pArrHashTable[iReturn]) {
		iReturn += 1;
		//iReturn = (((iReturn* pHashTable->MaxLength) + (iDest* pHashTable->MaxLength))) % pHashTable->MaxLength;
		iDest = DoubleHashingDest(iIndex, pHashTable->MaxLength);
		iReturn %= pHashTable->MaxLength;
	}
	return iReturn;
}
int DoubleHashingDest(int iIndex, int iTableSize) {
	int iReturn = 0;

	iReturn = iTableSize - (iIndex % iTableSize);
	return iReturn;
}

// �ؽ����̺� �ڷ� �߰�
void InsertHashElement(HashTable* pHashTable, int iValue) {
	int iIndex = SetHashIndex(pHashTable, iValue);

	iIndex = ReleaseCollision(pHashTable, iIndex);

	pHashTable->pArrHashTable[iIndex] = iValue;
}

// �ؽ����̺� �ڷ� �˻�
int GetHashValue(HashTable* pHashTable, int iValue, int* getretIndex) {
	int Index = SetHashIndex(pHashTable, iValue);
	int iCnt = 0;
	int iDest = 0;
	while (iValue != pHashTable->pArrHashTable[Index] && pHashTable->MaxLength > iCnt) {
		iDest = DoubleHashingDest(Index, pHashTable->MaxLength);
		Index = (Index + iDest) % pHashTable->MaxLength;
		++iCnt;
	}

	if (pHashTable->MaxLength <= iCnt) {
		printf("�ε��� ���� �ʰ� \n");
		Index = -1;
	}
	*getretIndex = Index;
	return pHashTable->pArrHashTable[Index];
}

// �ؽ����̺� �ڷ� ����
void DeleteHashElement(HashTable* pHashTable, int key);

void DeleteHashTable(HashTable* pHashTable) {

	free(pHashTable->pArrHashTable);

	free(pHashTable);
}