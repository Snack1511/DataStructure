#ifndef _QUEUEUTIL_
#define _QUEUEUTIL_
Queue* InitClients();
void Process(int EndTime, int OfficerNum);
void ClientArrive(Queue* pClients, Queue* pDelayQueue, int Time);
void ServiceStart(Queue* pDelayQueue, Queue** pServiceQueue, int OfficerNum);
void ServiceEnd(Queue* pDelayQueue, Queue** pServiceQueue, int TotalTime, int OfficerNum);
void DisplayDelayCount(Queue* pQueue);
void PrintClient(QueueNode node);
void SumDelayTime(Queue* pDelayQueue, float* pSum);
void PrintResult(Queue* pClients, Queue* pDelay, Queue** pService, int Time, int Officer, float AvgDelayTime);
#endif