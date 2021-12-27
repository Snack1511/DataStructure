#include <stdio.h>
#include <stdlib.h>
#include "MyCircularlist_headernode.h"

int main(int argc, char* argv[])
{
	int i = 0;
	int arrayCount = 0;
	CircleList* pList = NULL;
	CircleNode* pValue = NULL;
	CircleNode node;

	//배열리스트 생성
	pList = createCList();
	if (pList != NULL)
	{
		node.Data = 1;
		addCLElements(pList, 0, node);
		displayCircularList(pList);

		node.Data = 3;
		addCLElements(pList, 1, node);
		displayCircularList(pList);

		node.Data = 5;
		addCLElements(pList, 2, node);
		displayCircularList(pList);

		removeCLElements(pList, 0);
		displayCircularList(pList);

		removeCLElements(pList, 1);
		displayCircularList(pList);
		removeCLElements(pList, 0);
		displayCircularList(pList);

		deleteCList(pList);
	}
	else {
		printf("pList is NULL");
	}

	return 0;
}
