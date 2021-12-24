#include<stdio.h>
#include<stdlib.h>
#include"arraylist.h"
//*************************** 1. 헤더 Include  
int main(int argc, char* argv[]) {
	int i = 0;
	int arrayCount = 0;
	ArrayList* pList = NULL;
	ArrayListNode* pValue = NULL;

	pList = createArrayList(6);
	if (pList != NULL) {
//*************************** 2. 최대원소 개수가 6개인 배열리스트를 생성하고 리스트가 정상적으로 생성되었는지 점검
		ArrayListNode node;

		//리스트 초기화 : 1, 3, 5, 추가
		node.data = 1;
		addALElement(pList, 0, node);

		node.data = 3;
		addALElement(pList, 1, node);

		node.data = 5;
		addALElement(pList, 2, node);
		displayArrayList(pList);

		//첫번째 원소 제거
		removeALElement(pList, 0);
		displayArrayList(pList);

		arrayCount = getArrayListLength(pList);
		for (i = 0; i < arrayCount; i++) {
			pValue = getALElement(pList, i);
			printf("위치[%d]-%d\n", i, pValue->data);
		}

		deleteArrayList(pList);

	}
	return 0;
}