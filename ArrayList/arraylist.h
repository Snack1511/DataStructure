#ifndef _ARRAYLIST_
#define _ARRAYLIST_
//********** 1. ��ó��

typedef struct ArrayListNodeType {
	int data;
}ArrayListNode;

typedef struct ArrayListType {
	int maxElementCount; // �ִ� ���� ����
	int currentElementCount; // ���� ������ ����
	ArrayListNode* pElement; // ���� ������ ���� 1���� �迭
}ArrayList;
//*********** 2. ����ü ����

ArrayList* createArrayList(int maxElementCount);
void deleteArrayList(ArrayList* pList);
int isArrayListFull(ArrayList* pList);
int addALElement(ArrayList* pList, int position, ArrayListNode element);
int removeALElement(ArrayList* pList, int position);
ArrayListNode* getALElement(ArrayList* pList, int position);
void displayArrayList(ArrayList* pList);
void clearArrayList(ArrayList* pList);
int getArrayListLength(ArrayList* pList);
#endif // _ARRAYLIST_!
//*********** 3. C�Լ� ����κ�

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_!
//*********** 4. ��Ÿ ����� ����