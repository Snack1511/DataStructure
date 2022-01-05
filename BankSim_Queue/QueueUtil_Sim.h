#ifndef _QUEUEUTIL_
#define _QUEUEUTIL_
Queue* InitClients();
void Process(int EndTime);
void ClientArrive(Queue* pClients, Queue* pDelayQueue, int Time);
void ServiceStart(Queue* pDelayQueue, Queue* pServiceQueue);
void ServiceEnd(Queue* pDelayQueue, Queue* pServiceQueue, int TotalTime);
void DisplayDelayCount(Queue* pQueue);
void PrintClient(QueueNode node);
void PrintResult(Queue* pClients, Queue* pDelay, Queue* pService, int Time);
#endif