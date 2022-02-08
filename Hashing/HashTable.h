#ifndef _HASHTABLE_
#define _HASHTABLE_
/*
	다시짜야함
*/
typedef struct HashTableType HashTable;
struct HashTableType {
	int* pArrHashTable;
	int MaxLength;
};

// 해시테이블 생성 -> 배열 - C, 연결리스트
HashTable* CreateHashTable(int MaxLength);

// 해싱 함수 -> 나머지, 이동접기 - C, 경계접기, 중간제곱
int SetHashIndex(HashTable* pHashTable, int iValue);
//충돌 처리 함수 -> 선형, 제곱, 이중 - C
int ReleaseCollision(HashTable* pHashTable, int iIndex);
//이중 해싱함수
int DoubleHashingDest(int iIndex, int iTableSize);

// 해시테이블 자료 추가
void InsertHashElement(HashTable* pHashTable, int iValue);

// 해시테이블 자료 검색
int GetHashValue(HashTable* pHashTable, int iValue, int* getretIndex);

// 해시테이블 자료 삭제
void DeleteHashElement(HashTable* pHashTable, int iValue);

// 해시테이블 삭제
void DeleteHashTable(HashTable* pHashTable);
#endif