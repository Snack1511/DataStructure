#pragma once
/*
리스트 생성
리스트 삭제
노드추가
노드제거
리스트 초기화
리스트길이반환
노드 반환
리스트 전체출력
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