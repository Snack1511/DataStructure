#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTION 4
typedef struct MapPositionType MapPosition;
//offset : x, y
static int DIRECTION_OFFSETS[NUM_DIRECTION][2] = {
	{0, -1},	//�������� �̵�
	{1, 0},		//���������� �̵�
	{0, 1},		//�Ʒ������� �̵�
	{-1, 0}		//�������� �̵�
};
/*
	�̵����� ������ ǥ���ϴ� �迭���� DIRECTION_OFFSET[]�� static���� ������ ������
	���α׷� �󿡼� �����ϰ� 1���� �ν��Ͻ��� �������� �ϱ� ���ؼ��̴�.
*/
enum PosStatus {NOT_VISIT = 0, VISIT = 1, WALL = 2};
struct MapPositionType {
	int x;
	int y;
	int direction;
};
#endif