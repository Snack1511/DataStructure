#ifndef _NORMALLISTSTACK_
#define _NORMALLISTSTACK_

typedef struct NormalLinkedListNodeType LinkedListNode;
typedef struct NormalLinkedListType LinkedList;
struct NormalLinkedListNodeType {
	int data;
	LinkedListNode* pLink;
};
struct NormalLinkedListType {
	int currentLength;
	LinkedListNode phead;
};

LinkedList* createList();
int addListElement(LinkedList* pList, int position, LinkedListNode node);
int removeElement(LinkedList* pList, int position);
LinkedListNode* GetElement(LinkedList* pList, int position);
LinkedListNode* GetLastElement(LinkedList* pList);
//------- 리스트정의 -------------

int PushStack(LinkedList* pList, LinkedListNode node);
LinkedListNode* PopStack(LinkedList* pList);

//------ 스택정의 ---------------

#endif // !_NORMALLISTSTACK_
#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_!