#ifndef _HASHTABLE_
#define _HASHTABLE_
/*
	�ٽ�¥����
*/
typedef struct HashTableType HashTable;
struct HashTableType {
	int* pArrHashTable;
	int MaxLength;
};

// �ؽ����̺� ���� -> �迭 - C, ���Ḯ��Ʈ
HashTable* CreateHashTable(int MaxLength);

// �ؽ� �Լ� -> ������, �̵����� - C, �������, �߰�����
int SetHashIndex(HashTable* pHashTable, int iValue);
//�浹 ó�� �Լ� -> ����, ����, ���� - C
int ReleaseCollision(HashTable* pHashTable, int iIndex);
//���� �ؽ��Լ�
int DoubleHashingDest(int iIndex, int iTableSize);

// �ؽ����̺� �ڷ� �߰�
void InsertHashElement(HashTable* pHashTable, int iValue);

// �ؽ����̺� �ڷ� �˻�
int GetHashValue(HashTable* pHashTable, int iValue, int* getretIndex);

// �ؽ����̺� �ڷ� ����
void DeleteHashElement(HashTable* pHashTable, int iValue);

// �ؽ����̺� ����
void DeleteHashTable(HashTable* pHashTable);
#endif