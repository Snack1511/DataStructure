#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkedListMaxHeap.h"

Heap* CreateHeap(){
	Heap* pReturn = NULL;
	pReturn = (Heap*)malloc(sizeof(Heap));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(Heap));
		//pReturn->Root = (Node*)malloc(sizeof(Node));
		
	}
	else {
		printf("메모리 할당 오류\n");
	}
	return pReturn;
}
void InsertHeapNode(Heap* pHeap, Node node){
	Node tmp;
	int idx = 0, parent = 0;
	Node* pNode = NULL, *pPrev = NULL, *pCompare = NULL, *pTarget = NULL;
	if (pHeap != NULL) {
		pNode = (Node*)malloc(sizeof(Node));
		if (pNode != NULL) {
			*pNode = node;
			pNode->pLink = NULL;
			if (pHeap->Root != NULL) {
				pPrev = pHeap->Root;
				while (pPrev->pLink != NULL) {
					pPrev = pPrev->pLink;
				}
				pPrev->pLink = pNode;

			}
			else {
				pHeap->Root = pNode;
			}
			pHeap->currentLength++;
		}
		idx = pHeap->currentLength-1;
		pTarget = pHeap->Root;
		pCompare = pTarget;
		if (pTarget != NULL && pTarget->pLink != NULL) {
			while (idx > 0) {
				parent = (idx - 1)/ 2;
				for (int i = 0; i < idx && pTarget->pLink != NULL; i = (i+1)) {
					if (parent == i) {
						pCompare = pTarget;
					}
					pTarget = pTarget->pLink;
				}
				if (pCompare->key < pTarget->key) {
					tmp = *pTarget;
					pTarget->data = pCompare->data;
					pTarget->key = pCompare->key;

					pCompare->data = tmp.data;
					pCompare->key = tmp.key;
					pTarget = pHeap->Root;
				}
				idx = (idx - 1) / 2;
				
			}
		}
	}
}
void DeleteHeap(Heap* pHeap){
	Node* pDel = NULL;
	Node* pDeltmp = NULL;
	if (pHeap != NULL) {
		if (pHeap->Root != NULL) {
			pDel = pHeap->Root->pLink;
			pDeltmp = pDel;
			while (pDeltmp->pLink != NULL) {
				pDel = pDeltmp;
				pDeltmp = pDeltmp->pLink;
				pDel->pLink = NULL;
				free(pDel);
			}
			free(pHeap->Root);
		}
		free(pHeap);
	}
}
Node* DeleteHeapNode(Heap* pHeap){
	Node* pReturn = NULL;
	Node* pNode = NULL, *pParent = NULL;
	Node tmp;
	if (pHeap != NULL) {
		pParent = pHeap->Root;
		pReturn = pHeap->Root;
		while (pParent->pLink != NULL && pParent->pLink->pLink != NULL) {
			pParent = pParent->pLink;
		}
		pNode = pParent->pLink;
		tmp = *pNode;
		pNode->data = pReturn->data;
		pNode->key = pReturn->key;

		pReturn->data = tmp.data;
		pReturn->key = tmp.key;

		pParent->pLink = NULL;
		pReturn = pNode;
		

		pHeap->currentLength--;


		int idx = 0, child = 0;
		Node *pTarget = pHeap->Root;
		Node* pMainComparer = NULL;
		Node *pCompare1 = pTarget, * pCompare2 = NULL;
		idx = pHeap->currentLength - 1;
		pTarget = pHeap->Root;
		pCompare1 = pTarget;
		pCompare2 = pTarget;
		if (pTarget != NULL && pTarget->pLink != NULL) {
			while (idx > 0) {
				child = (idx * 2) + 1;
				if (child-1 < pHeap->currentLength - 1) {
					for (int i = 0; i < idx && pTarget->pLink != NULL; i = (i + 1)) {
						if (child == i) {
							pCompare1 = pTarget;
							pCompare2 = pTarget->pLink;
						}
						pTarget = pTarget->pLink;
					}
				}
				if (pCompare1->key < pCompare2->key) {
					pMainComparer = pCompare2;
				}
				else {
					pMainComparer = pCompare1;

				}
				if (pMainComparer->key < pTarget->key) {
					tmp = *pTarget;
					pTarget->data = pMainComparer->data;
					pTarget->key = pMainComparer->key;

					pMainComparer->data = tmp.data;
					pMainComparer->key = tmp.key;
					pTarget = pHeap->Root;

				}
				else {
					idx--;
				}
			}
		}
	}
	return pReturn;
}

