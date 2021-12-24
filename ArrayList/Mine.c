#include<stdio.h>
#include<stdlib.h>

#define MAX_INDEX 32
typedef struct ArrayList {
	int elements[MAX_INDEX];
	int LastNum;//1~MAX_INDEX
}AList;

AList createList();
void deleteList(AList*);
int isFull(AList);//false : 0, true : 1
int addElement(AList*, int, int);// // success : 1, Full : 0, Index Exception : -1
int removeElement(AList*, int);// success : 1, Index Exception : -1
void clearList(AList*);
int getListLength(AList);
int getElement(AList, int);

void displayList(AList);
int main() {
	AList alist;
	AList* alist_ptr = &alist;
	*alist_ptr = createList();
	addElement(alist_ptr, 0, 10);
	addElement(alist_ptr, 1, 20);
	addElement(alist_ptr, 2, 30);
	displayList(alist);
	removeElement(alist_ptr, 1);
	displayList(alist);
	removeElement(alist_ptr, 0);
	displayList(alist);

	addElement(alist_ptr, 0, 10);
	addElement(alist_ptr, 1, 20);
	addElement(alist_ptr, 2, 30);
	addElement(alist_ptr, 0, 10);
	addElement(alist_ptr, 1, 20);
	addElement(alist_ptr, 2, 30);
	displayList(alist);
	
	printf("List Length : %d \n", getListLength(alist));
	printf("List element[3] : %d \n", getElement(alist, 3));
	
	removeElement(alist_ptr, 0);
	displayList(alist);
	removeElement(alist_ptr, 0);
	displayList(alist);
	removeElement(alist_ptr, 2);
	displayList(alist);

	clearList(alist_ptr);
	addElement(alist_ptr, 0, 10);
	addElement(alist_ptr, 1, 20);
	addElement(alist_ptr, 2, 30);
	displayList(alist);
	return 0;
}

AList createList() {
	AList alst = { {NULL, }, 0};
	return alst;
}
void deleteList(AList* alistptr) {
	for (int i = alistptr->LastNum - 1; i >= 0; i--) {
		alistptr->elements[i] = NULL;
	}
	alistptr->LastNum = 0;
}
int isFull(AList alist) {
	if (alist.LastNum == MAX_INDEX) {
		return 1;
	}
	else {
		return 0;
	}
}
int addElement(AList* alistptr, int idx, int value) {
	if (isFull((*alistptr))) {
		return 0;
	}
	else if (alistptr->LastNum < idx) {
		return -1;
	}
	else {
		for (int i = alistptr->LastNum - 1; i >= idx; i--) {
			alistptr->elements[i + 1] = alistptr->elements[i];
		}
		alistptr->elements[idx] = value;
		alistptr->LastNum++;
		return 1;
	}
}

int removeElement(AList* alistptr, int idx) {
	if (alistptr->LastNum <= idx) {
		return -1;
	}
	else {
		for (int i = idx; i < alistptr->LastNum - 1; i++) {
			alistptr->elements[i] = alistptr->elements[i + 1];
		}
		alistptr->elements[alistptr->LastNum - 1] = NULL;
		alistptr->LastNum--;
		return 1;
	}
}
void clearList(AList* alistptr) {
	for (int i = 0; i < MAX_INDEX; i++) {
		alistptr->elements[i] = NULL;
	}
}
int getListLength(AList alist) {
	return alist.LastNum;
}
int getElement(AList alist, int idx) {
	return alist.elements[idx];
}

void displayList(AList alst) {
	for (int i = 0; i < alst.LastNum; i++) {
		if (alst.elements[i] != NULL) {
			printf("%d   ", alst.elements[i]);
		}
		else {
			break;
		}
	}
	printf("\n");
}