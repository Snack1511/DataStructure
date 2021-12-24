#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "arraylist.h"

ArrayList* createArrayList(int maxElementCount) {
	ArrayList* pReturn = NULL;
	int i = 0;

	if (maxElementCount > 0) {								//입력 파라미터 유효성 점검
		pReturn = (ArrayList*)malloc(sizeof(ArrayList));	//메모리할당

		if (pReturn != NULL) {								//메모리 할당 점검
			pReturn->maxElementCount = maxElementCount;
			pReturn->currentElementCount = 0;
			pReturn->pElement = NULL;
		}
		else {
			printf("Error : Memory Allocation Error!\nFunction Name : createArrayList(int)\n");
			return NULL;
		}
	}
	else {
		printf("Error : Number of Elements is over than 0!\nFunction Name : createArrayList(int)\n");
		return NULL;
	}

	pReturn->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode)*maxElementCount);		//원소를 저장하는 배열 메모리 할당 및 점검1

	if (pReturn->pElement == NULL) {														//원소를 저장하는 배열 메모리 할당 및 점검2
		printf("Error : Second Memory Allocation\nFunction Name : createArrayList(int)\n");
		free(pReturn);
		return NULL;
	}

	memset(pReturn->pElement, 0, sizeof(ArrayListNode) * maxElementCount);

	return pReturn;
}
//****************** 1. createArrayList 함수 구현

int addALElement(ArrayList* pList, int position, ArrayListNode element) {
	int ret = FALSE;
	int i = 0;
																				//유효성 검사
	if (pList != NULL) {														//메모리NULL여부
		if (isArrayListFull(pList) != TRUE) {									//배열에 새로운 원소 추가 가능 여부
			if (position >= 0 && position <= pList->currentElementCount) {		//추가하려는 위치의 인덱스
				for (i = pList->currentElementCount - 1; i >= position; i--) {
					pList->pElement[i + 1] = pList->pElement[i];				//기존 원소들을 오른쪽으로 한칸 씩 이동
				}
				pList->pElement[position] = element;							//새로운 원소 값 추가

				pList->currentElementCount++;									
				ret = TRUE;
			}
			else {
				printf("Error : Position Index - [%d] is Out of range!\nFunction Name : addALElement\n", position);
			}
		}
		else {
			printf("Error : Overflow List size - [%d]/[%d]!\nFunction Name : addALElement\n", position, pList->maxElementCount);
		}
	}
	else {
		printf("Error : ListPointer is NULL!\nFunction Name : addALElement\n");
	}
	return ret;
}
//****************** 2. addALElement 함수 구현

int removeALElement(ArrayList* pList, int position) {
	int ret = FALSE;
	int i = 0;
																				//유효성 검사
	if (pList != NULL) {														//메모리 NULL여부
		if (position >= 0 && position < pList->currentElementCount) {			//제거하려는 위치의 인덱스
			for (i = position; i < pList->currentElementCount - 1; i++) {
				pList->pElement[i] = pList->pElement[i + 1];					//기존 원소들 왼쪽으로 한칸 씩 이동
			}

			pList->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("Error : Position Index - [%d] is Out of range!\nFunction Name : removeALElement\n", position);
		}
	}
	else {
		printf("Error : ListPointer is NULL!\nFunction Name : removeALElement\n");
	}
	return ret;
}
//****************** 3. removeALElement 함수 구현

ArrayListNode* getALElement(ArrayList* pList, int position) {
	ArrayListNode* pReturn = NULL;
	if (pList != NULL) {												//NULL 여부
		if (position >= 0 && position < getArrayListLength(pList)) {	//제거하려는 위치의 인덱스
			pReturn = &(pList->pElement[position]);
		}
		else {
			printf("Error : Position Index - [%d] is Out of range!\nFunction Name : getAlElement\n", position);
		}
	}

	return pReturn;
}//리스트 원소 반환

void displayArrayList(ArrayList* pList) {
	int i = 0;
	if (pList != NULL) {
		printf("Maximize Number of Element : %d \n", pList->maxElementCount);
		printf("Current Number of Element : %d \n", pList->currentElementCount);

		for (i = 0; i < pList->currentElementCount; i++) {
			printf("[%d], %d \n", i, getALElement(pList, i)->data);		//현재 저장된 원소의 값을 출력
		}

		i = pList->currentElementCount;
		for (; i < pList->maxElementCount; i++) {
			printf("[%d], Empty \n", i);
		}
	}
	else {
		printf("ArrayList is NULL");
	}
}//리스트 순회 함수
//****************** 4. 리스트 원소 반환과 리스트 순회 함수 구현

int isArrayListFull(ArrayList* pList) {
	int ret = FALSE;

	if (pList != NULL) {
		if (pList->currentElementCount == pList->maxElementCount) {
			ret = TRUE;
		}
	}

	return ret;
}//리스트가 다 찼는지 확인하는 함수

int getArrayListLength(ArrayList* pList) {
	int ret = 0;

	if (pList != NULL) {
		ret = pList->currentElementCount;
	}

	return ret;
}

void deleteArrayList(ArrayList* pList) {
	int i = 0;
	if (pList != NULL) {
		free(pList->pElement);
		free(pList);
	}
}

int addALElementFirst(ArrayList* pList, ArrayListNode element) {
	int position = 0;
	return addALElement(pList, position, element);
}

int addALElementLast(ArrayList* pList, ArrayListNode element) {
	int ret = FALSE;
	int position = 0;
	if (pList != NULL) {
		position = getArrayListLength(pList);
		ret = addALElement(pList, position, element);
	}
	return ret;
}
//****************** 5. 기타 함수 구현

