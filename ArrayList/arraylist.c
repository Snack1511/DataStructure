#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "arraylist.h"

ArrayList* createArrayList(int maxElementCount) {
	ArrayList* pReturn = NULL;
	int i = 0;

	if (maxElementCount > 0) {								//�Է� �Ķ���� ��ȿ�� ����
		pReturn = (ArrayList*)malloc(sizeof(ArrayList));	//�޸��Ҵ�

		if (pReturn != NULL) {								//�޸� �Ҵ� ����
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

	pReturn->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode)*maxElementCount);		//���Ҹ� �����ϴ� �迭 �޸� �Ҵ� �� ����1

	if (pReturn->pElement == NULL) {														//���Ҹ� �����ϴ� �迭 �޸� �Ҵ� �� ����2
		printf("Error : Second Memory Allocation\nFunction Name : createArrayList(int)\n");
		free(pReturn);
		return NULL;
	}

	memset(pReturn->pElement, 0, sizeof(ArrayListNode) * maxElementCount);

	return pReturn;
}
//****************** 1. createArrayList �Լ� ����

int addALElement(ArrayList* pList, int position, ArrayListNode element) {
	int ret = FALSE;
	int i = 0;
																				//��ȿ�� �˻�
	if (pList != NULL) {														//�޸�NULL����
		if (isArrayListFull(pList) != TRUE) {									//�迭�� ���ο� ���� �߰� ���� ����
			if (position >= 0 && position <= pList->currentElementCount) {		//�߰��Ϸ��� ��ġ�� �ε���
				for (i = pList->currentElementCount - 1; i >= position; i--) {
					pList->pElement[i + 1] = pList->pElement[i];				//���� ���ҵ��� ���������� ��ĭ �� �̵�
				}
				pList->pElement[position] = element;							//���ο� ���� �� �߰�

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
//****************** 2. addALElement �Լ� ����

int removeALElement(ArrayList* pList, int position) {
	int ret = FALSE;
	int i = 0;
																				//��ȿ�� �˻�
	if (pList != NULL) {														//�޸� NULL����
		if (position >= 0 && position < pList->currentElementCount) {			//�����Ϸ��� ��ġ�� �ε���
			for (i = position; i < pList->currentElementCount - 1; i++) {
				pList->pElement[i] = pList->pElement[i + 1];					//���� ���ҵ� �������� ��ĭ �� �̵�
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
//****************** 3. removeALElement �Լ� ����

ArrayListNode* getALElement(ArrayList* pList, int position) {
	ArrayListNode* pReturn = NULL;
	if (pList != NULL) {												//NULL ����
		if (position >= 0 && position < getArrayListLength(pList)) {	//�����Ϸ��� ��ġ�� �ε���
			pReturn = &(pList->pElement[position]);
		}
		else {
			printf("Error : Position Index - [%d] is Out of range!\nFunction Name : getAlElement\n", position);
		}
	}

	return pReturn;
}//����Ʈ ���� ��ȯ

void displayArrayList(ArrayList* pList) {
	int i = 0;
	if (pList != NULL) {
		printf("Maximize Number of Element : %d \n", pList->maxElementCount);
		printf("Current Number of Element : %d \n", pList->currentElementCount);

		for (i = 0; i < pList->currentElementCount; i++) {
			printf("[%d], %d \n", i, getALElement(pList, i)->data);		//���� ����� ������ ���� ���
		}

		i = pList->currentElementCount;
		for (; i < pList->maxElementCount; i++) {
			printf("[%d], Empty \n", i);
		}
	}
	else {
		printf("ArrayList is NULL");
	}
}//����Ʈ ��ȸ �Լ�
//****************** 4. ����Ʈ ���� ��ȯ�� ����Ʈ ��ȸ �Լ� ����

int isArrayListFull(ArrayList* pList) {
	int ret = FALSE;

	if (pList != NULL) {
		if (pList->currentElementCount == pList->maxElementCount) {
			ret = TRUE;
		}
	}

	return ret;
}//����Ʈ�� �� á���� Ȯ���ϴ� �Լ�

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
//****************** 5. ��Ÿ �Լ� ����

