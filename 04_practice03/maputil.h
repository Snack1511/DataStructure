#ifndef _MAP_UTIL_
#define _MAP_UTIL_

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, Stack *pStack);//�̷��� ��� Ž��
int pushLSMapPosition(Stack* pStack, MapPosition data);												//PushȮ��
void showPath(Stack* pStack, int mazeArray[HEIGHT][WIDTH]);											// ã����� ǥ��
void printMaze(int mazeArray[HEIGHT][WIDTH]);															//�̷� ��ü ǥ��

#endif