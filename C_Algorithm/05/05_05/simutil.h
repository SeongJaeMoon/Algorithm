#ifndef _SIM_UTIL_
#define _SIM_UTIL_

// 고객 도착 큐에 고객 추가.
void insertCutomer(int arrivalTime, int processTime, LinkedQueue *pQueue);

// 고객 도착 처리.
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue);

// 서비스 시작 처리.
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue);

// 서비스 종료 처리.
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode,
					  int *pServiceUserCount, int *pTotalWaitTime);

// 고객의 상태를 출력.
void printSimCustomer(int currentTime, SimCustomer customer);

// 대기 열의 상태를 출력.
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);

// 최종 시뮬레이션 결과(통계치) 출력.
void printReport(LinkedQueue *pWaitQueue,
				 int serviceUserCount,
				 int totalWaitTime);

#endif