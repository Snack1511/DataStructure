#include <stdio.h>
#include <stdlib.h>
#include "BinSearchTree.h"

void displayBinSearchTreeInternal(TreeNode* pTreeNode, int level, char type)
{
	int i = 0;
	for (i = 0; i < level; i++) {
		printf("    ");
	}

	if (pTreeNode != NULL) {
		printf("-[%i,%c]%i-%c\n", level, type,
			pTreeNode->key, pTreeNode->data);

		displayBinSearchTreeInternal(pTreeNode->pLeft, level + 1, 'L');
		displayBinSearchTreeInternal(pTreeNode->pRight, level + 1, 'R');
	}
	else {
		printf("NULL\n");
	}
}

int main(int argc, char* argv[])
{
	Tree* pTree = NULL;
	TreeNode* pSearchNode = NULL;
	int key = 0;

	TreeNode e1 = { 30, 'A' };
	TreeNode e2 = { 20, 'B' };
	TreeNode e3 = { 40, 'C' };
	TreeNode e4 = { 10, 'D' };
	TreeNode e5 = { 24, 'E' };
	TreeNode e6 = { 34, 'F' };
	TreeNode e7 = { 46, 'G' };
	TreeNode e8 = { 6, 'H' };
	TreeNode e9 = { 14, 'I' };
	TreeNode e10 = { 22, 'I' };

	pTree = CreateTree();
	if (pTree != NULL)
	{
		InsertNode(pTree, e1);
		InsertNode(pTree, e2);
		InsertNode(pTree, e3);
		InsertNode(pTree, e4);
		InsertNode(pTree, e5);
		InsertNode(pTree, e6);
		InsertNode(pTree, e7);
		InsertNode(pTree, e8);
		InsertNode(pTree, e9);
		InsertNode(pTree, e10);
		displayBinSearchTreeInternal(pTree->pRoot, 0, 'R');

		
		key = 14;
		pSearchNode = SearchTree(pTree, key);
		if (pSearchNode != NULL) {
			printf("검색: 키-[%d], 결과-[%c]\n", key, pSearchNode->data);
		}
		else {
			printf("검색: 키-[%d],발견하지 못하였습니다\n", key);
		}
		
		key = 30;
		printf("자료 제거: 키-[%d]\n", key);
		DeleteNode(pTree, key);
		displayBinSearchTreeInternal(pTree->pRoot, 0, 'R');
		
		pSearchNode = SearchTree(pTree, key);
		if (pSearchNode != NULL) {
			printf("검색: 키-[%d], 결과-[%c]\n", key, pSearchNode->data);
		}
		else {
			printf("검색: 키-[%d],발견하지 못하였습니다\n", key);
		}


		DeleteTree(pTree);
		
	}

	return 0;
}
