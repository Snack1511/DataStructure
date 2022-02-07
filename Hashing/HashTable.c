#include<string.h>
#include "HashTable.h"
// �ؽ����̺� ���� -> �迭, ���Ḯ��Ʈ
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

// �ؽ����̺� �ڷ� �߰�
void InsertHashElement(HashTable* pHashTable, int iValue, int iKey) {
	int iIndex = SetHashIndex(pHashTable, iValue);
	if (1 == ReleaseCollision(pHashTable, &iIndex)) {
		pHashTable->pArrHashTable[iIndex] = iKey;
	}
	else {
		printf("���̺� ����� ����\n");
	}
}

// �ؽ����̺� �ڷ� �˻�
int GetHashIndex(HashTable* pHashTable, int iValue);

// �ؽ����̺� �ڷ� ����
void DeleteHashElement(HashTable* pHashTable, int key);