#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"MyDLList.h"

int main() {
	DoubleLinkedList* pDLL;
	DLNode Node;

	pDLL = createDLList();
	Node.Data = 1;
	addDLElements(pDLL, 0, Node);
	Node.Data = 3;
	addDLElements(pDLL, 1, Node);
	Node.Data = 5;
	addDLElements(pDLL, 2, Node);
	displayDLList(pDLL);

	removeDLElements(pDLL, 1);
	displayDLList(pDLL);
	removeDLElements(pDLL, 0);
	displayDLList(pDLL);
	removeDLElements(pDLL, 2);
	deleteDLList(pDLL);
}