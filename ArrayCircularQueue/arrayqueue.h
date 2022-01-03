#ifndef _ARRAYQUEUE_
#define _ARRAYQUEUE_
typedef struct ArrayQueueNodeType QueueNode;
typedef struct ArrayQueueType Queue;

struct ArrayQueueNodeType {
	char data;
};
struct ArrayQueueType {
	int maxLength;				//�ִ� ���� ����
	int currentLength;			//���� ���� ����
	int front;					//����Ʈ�� ��ġ --> ����Ʈ ����� ���� ��ġ
	int rear;					//������ ��ġ
	QueueNode* pElements;		//��������� ���� 1���� �迭 ������
};


Queue* CreateQueue(int maxLength);
int Enqueue(Queue* pQueue, QueueNode element);
QueueNode* Dequeue(Queue* pQueue);
QueueNode* Peek(Queue* pQueue);
void DeleteQueue(Queue* pQueue);
int isFull(Queue* pQueue);
int isEmpty(Queue* pQueue);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif // _COMMON_LIST_DEF_! 