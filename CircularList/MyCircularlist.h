#pragma once
/*
����Ʈ ����
����Ʈ ����
����߰�
�������
����Ʈ �ʱ�ȭ
����Ʈ���̹�ȯ
��� ��ȯ
����Ʈ ��ü���
*/
#ifndef _CIRCULARLIST_
#define _CIRCULARLIST_
typedef struct CircularListNodeType CircleNode;
typedef struct CircularListType CircleList;
struct CircularListNodeType {
	int Data;
	CircleNode* pLink;
};
struct CircularListType {
	int currentElementLength;
	CircleNode* pHeader;
};
CircleList* createCList();
void deleteCList(CircleList* pList);
int addCLElements(CircleList* pList, int position, CircleNode pValue);
int removeCLElements(CircleList* pList, int position);
void clearCList(CircleList* pList);
int getCListLength(CircleList* pList);
CircleNode* getCLNode(CircleList* pList, int position);
void displayCircularList(CircleList* pList);
#endif
#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_!