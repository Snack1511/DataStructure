#include<stdio.h>
#include<stdlib.h>
#include"BinTree.h"

int main() {
	Tree* pTree = NULL;
	TreeNode* pNodeA = NULL, * pNodeB = NULL, * pNodeC = NULL, 
		* pNodeD = NULL, * pNodeE = NULL, * pNodeF = NULL;
	TreeNode Node = { 0, };

	Node.data = 'A';
	pTree = MakeBinTree(Node);
	if (pTree != NULL) {
		pNodeA = GetRoot(pTree);

		Node.data = 'B';
		pNodeB = InsertLeftChild(pNodeA, Node);

		Node.data = 'C';
		pNodeC = InsertLeftChild(pNodeA, Node);

		Node.data = 'C';
		pNodeC = InsertRightChild(pNodeA, Node);


		if (pNodeB != NULL) {
			Node.data = 'D';
			pNodeD = InsertLeftChild(pNodeB, Node);
		}

		if (pNodeC != NULL) {
			Node.data = 'E';
			pNodeE = InsertLeftChild(pNodeC, Node);

			Node.data = 'F';
			pNodeE = InsertRightChild(pNodeC, Node);
		}
		DeleteTree(pTree);
	}
	return 0;
}