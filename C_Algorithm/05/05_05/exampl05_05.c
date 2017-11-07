#include <stdio.h>
#include <stdlib.h>
#include "simdef.h"
#include "simlinkedqueue.h"
#include "simutil.h"

int main(int argc, char *argv[])
{
	int currentTime = 0;
	int endTime = 10;
	int serviceUserCount = 0;
	int totalWaitTime = 0;

	LinkedQueue *pArrivalQueue = NULL, *pWaitQueue = NULL;
	QueueNode* pServiceNode1 = NULL;

	pArrivalQueue = createLinkedQueue();
	pWaitQueue = createLinkedQueue();
	if (pArrivalQueue != NULL && pWaitQueue == NULL) {
		printf("오류, createLinkedQueue()\n");
		return FALSE;
	}

	insertCutomer(0, 3, pArrivalQueue);	// 도착 시각: 0, 서비스 시간: 3
	insertCutomer(2, 2, pArrivalQueue);	// 도착 시각: 2, 서비스 시간: 2
	insertCutomer(4, 1, pArrivalQueue);	// 도착 시각: 4, 서비스 시간: 1
	insertCutomer(6, 1, pArrivalQueue);	// 도착 시각: 6, 서비스 시간: 1
	insertCutomer(8, 3, pArrivalQueue);	// 도착 시각: 8, 서비스 시간: 3

	for(currentTime = 0; currentTime < endTime; currentTime++) {
		processArrival(currentTime, pArrivalQueue, pWaitQueue);

		// 서비스 종료 처리.
		if (pServiceNode1 != NULL) {
			pServiceNode1 = processServiceNodeEnd(currentTime, 
				pServiceNode1, &serviceUserCount, &totalWaitTime);
		}

		// 서비스 시작 처리.
		if (pServiceNode1 == NULL) {
			pServiceNode1 = processServiceNodeStart(currentTime, pWaitQueue);
		}

		// 대기 큐의 상태 출력.
		printWaitQueueStatus(currentTime, pWaitQueue);
	}

	// 최종 시뮬레이션 결과 출력.
	printReport(pWaitQueue, serviceUserCount, totalWaitTime);

	// 메모리 해제.
	if (pServiceNode1 != NULL) {
		free(pServiceNode1);
	}
	deleteLinkedQueue(pArrivalQueue);
	deleteLinkedQueue(pWaitQueue);

	return 0;
}
