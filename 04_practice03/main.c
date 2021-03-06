#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"mapdef.h"
#include"maplinkedstack.h"
#include"maputil.h"

int main(int argc, char* argv[]) {
	Stack* pStack = NULL;
	MapPosition startPos, endPos;

	int mazeArray[HEIGHT][WIDTH] = {
		{0,0,2,2,2,2,2,2},
		{2,0,0,0,0,0,0,2},
		{2,2,2,0,2,2,2,2},
		{2,2,2,0,2,2,2,2},
		{2,0,0,0,0,0,0,2},
		{2,0,2,2,2,2,2,2},
		{2,0,0,0,0,0,0,0},
		{2,2,2,2,2,2,2,0}
	};

	pStack = createLNKStack();//???û???
	if (pStack != NULL) {
		startPos.x = 0;
		startPos.y = 0;
		endPos.x = 7;
		endPos.y = 7;

		printMaze(mazeArray);

		findPath(mazeArray, startPos, endPos, pStack);
		showPath(pStack, mazeArray);
		deleteLNKStack(pStack);
	}
	return 0;
}