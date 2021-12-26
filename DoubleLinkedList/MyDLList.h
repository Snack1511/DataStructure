#pragma once
#ifndef _MYDOUBLELINKED_
#define _MYDOUBLELINKED_
typedef struct DoubleLinkedNodeType DLNode;
typedef struct DoubleLinkedListType DoubleLinkedList;
struct DoubleLinkedNodeType {
	int Data;
	DLNode* pLLink;
	DLNode* pRLink;
};
struct DoubleLinkedListType {
	int currentElementLength;
	DLNode Header;
};
DoubleLinkedList* createDLList();
void deleteDLList(DoubleLinkedList* pList);
int addDLElements(DoubleLinkedList* pList, int position, DLNode pValue);
int removeDLElements(DoubleLinkedList* pList, int position);
void clearDLList(DoubleLinkedList* pList);
int getDLListLength(DoubleLinkedList* pList);
DLNode getDLNode(DoubleLinkedList* pList, int position);
void displayDLList(DoubleLinkedList* pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_!