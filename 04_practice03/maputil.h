#ifndef _MAP_UTIL_
#define _MAP_UTIL_

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LNKStack *pStack);//�̷��� ��� Ž��
int pushLSMapPosition(LNKStack* pStack, MapPosition data);												//PushȮ��
void showPath(LNKStack* pStack, int mazeArray[HEIGHT][WIDTH]);											// ã����� ǥ��
void printMaze(int mazeArray[HEIGHT][WIDTH]);															//�̷� ��ü ǥ��

#endif