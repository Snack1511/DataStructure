#pragma once
#ifndef _POLYLIST_
#define _POLYLIST_
#include"LinkedList.h"
void addLastElement(LinkedList* pList, int Degree, float Coef);
LinkedList* addPolyList(LinkedList* pListA, LinkedList* pListB);
LinkedList* subPolyList(LinkedList* pListA, LinkedList* pListB);
void DisPlayPoly(LinkedList* pList);

#endif