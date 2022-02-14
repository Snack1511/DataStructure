#include<stdio.h>
#include"AVL.h"

int main() {
	Tree* pTree = NULL;
	pTree = CreateBSTree();

	InsertElement(pTree, 1, 'A');
	InsertElement(pTree, 10, 'B');
	InsertElement(pTree, 20, 'C');
	InsertElement(pTree, 30, 'D');
	InsertElement(pTree, 35, 'E');
	InsertElement(pTree, 40, 'F');
	InsertElement(pTree, 45, 'G');
	InsertElement(pTree, 50, 'H');
	InsertElement(pTree, 60, 'I');

	DisplayTree(pTree->pRoot, 0, 'R');

	printf("%d\n", GetHeight(pTree->pRoot));
}