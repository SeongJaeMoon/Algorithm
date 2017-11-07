#include <stdio.h>
#include <stdlib.h>
#include "hashingdef.h"
#include "hashinglinkedlist.h"
#include "statichashing.h"

int main(int argc, char *argv[])
{
	HashTable *pHashTable = NULL;
	HashElement element1 = {"january", 1};
	HashElement element2 = {"february", 2};
	HashElement element3 = {"march", 3};
	HashElement element4 = {"april", 4};
	HashElement element5 = {"may", 5};
	HashElement element6 = {"june", 6};
	HashElement element7 = {"july", 7};
	HashElement element8 = {"august", 8};
	HashElement element9 = {"september", 9};
	HashElement element10 = {"october", 10};
	HashElement element11 = {"november", 11};
	HashElement element12 = {"december", 12};
	HashElement *pElement = NULL;
	HashElement *pElement2 = NULL;

	// 해시 테이블 생성
	pHashTable = createHashTable(13);
	if (pHashTable != NULL)
	{
		addSHT(pHashTable, element1);
		addSHT(pHashTable, element2);
		addSHT(pHashTable, element3);
		addSHT(pHashTable, element4);
		addSHT(pHashTable, element5);
		addSHT(pHashTable, element6);
		addSHT(pHashTable, element7);
		addSHT(pHashTable, element8);
		addSHT(pHashTable, element9);
		addSHT(pHashTable, element10);
		addSHT(pHashTable, element11);
		addSHT(pHashTable, element12);

		printf("해시 테이블 내용:\n");
		displayHashTable(pHashTable);

		pElement = searchHT(pHashTable, "april");
		if (pElement != NULL) {
			printf("검색키-%s, 검색 결과-%d\n", pElement->key, pElement->value);

			deleteElementHT(pHashTable, "april");
			printf("검색키[%s]로 자료 삭제\n", "april");

			printf("해시 테이블 내용:\n");
			displayHashTable(pHashTable);

			pElement2 = searchHT(pHashTable, "june");
			if (pElement2 != NULL) {
				printf("검색키-%s, 검색 결과-%d\n", pElement2->key, pElement2->value);
			}
		}
		else {
			printf("Not found\n");
		}

		deleteHashTable(pHashTable);
	}

	return 0;
}
