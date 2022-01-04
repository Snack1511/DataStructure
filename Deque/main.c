#include<stdio.h>
#include<stdlib.h>
#include"linkeddeque.h"

void displayDeque(Deque* pDeque) {

	DequeNode* pNode = NULL;
	int i = 0;
	if (pDeque != NULL) {
		printf("현재 노드개수 : %d\n", pDeque->currentLength);
		pNode = pDeque->pFront;
		while (pNode != NULL) {
			printf("%d %c     ", i, pNode->data);
			i++;
			pNode = pNode->pRLink;
		}
		printf("\n");
	}
}

void displayCharData(DequeNode* pNode) {
	if (pNode != NULL) {
		printf("Dequeue Value - [%c]\n", pNode->data);
	}
	else {
		printf("pNode 메모리 오류:main\n");
	}
}

int InsertFrontChar(Deque* pDeque, char data) {
	DequeNode node = { 0, };
	node.data = data;
	return InsertFront(pDeque, node);
}
int InsertRearChar(Deque* pDeque, char data) {
	DequeNode node = { 0, };
	node.data = data;
	return InsertRear(pDeque, node);
}


int main(int argc, char* argv[]) {
	Deque* pDeque = NULL;
	DequeNode* pNode = NULL;

	pDeque = CreateDeque();

	if (pDeque != NULL) {
		InsertFrontChar(pDeque, 'A');
		InsertFrontChar(pDeque, 'B');
		InsertRearChar(pDeque, 'C');
		InsertRearChar(pDeque, 'D');

		displayDeque(pDeque);

		pNode = DeleteRear(pDeque);
		displayCharData(pNode);
		free(pNode);
		displayDeque(pDeque);

		pNode = DeleteFront(pDeque);
		displayCharData(pNode);
		free(pNode);
		displayDeque(pDeque);

		DeleteDeque(pDeque);
		
	}
	return 0;
}