#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"
#include"PolyList.h"

int main() {
	LinkedList* pListA = NULL;
	LinkedList* pListB = NULL;
	LinkedList* pListC = NULL;

	pListA = createList();
	pListB = createList();

	if (pListA != NULL && pListB != NULL) {
		addLastElement(pListA, 6, 6);
		addLastElement(pListA, 5, 4);
		addLastElement(pListA, 2, 2);
		DisPlayPoly(pListA);

		addLastElement(pListB, 5, 1);
		addLastElement(pListB, 4, 2);
		addLastElement(pListB, 2, 3);
		addLastElement(pListB, 0, 4);
		DisPlayPoly(pListB);

		pListC = addPolyList(pListA, pListB);
		DisPlayPoly(pListC);

		pListC = subPolyList(pListA, pListB);
		DisPlayPoly(pListC);
		if (pListC != NULL) {
			deleteLinkedList(pListC);
		}
		
		deleteLinkedList(pListA);
		deleteLinkedList(pListB);

	}
	return 0;
}