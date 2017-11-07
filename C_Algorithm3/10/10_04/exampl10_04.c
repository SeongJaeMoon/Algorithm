#include <stdio.h>
#include <stdlib.h>
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
		addElementSHT(pHashTable, element1);
		addElementSHT(pHashTable, element2);
		addElementSHT(pHashTable, element3);
		addElementSHT(pHashTable, element4);
		addElementSHT(pHashTable, element5);
		addElementSHT(pHashTable, element6);
		addElementSHT(pHashTable, element7);
		addElementSHT(pHashTable, element8);
		addElementSHT(pHashTable, element9);
		addElementSHT(pHashTable, element10);
		addElementSHT(pHashTable, element11);
		addElementSHT(pHashTable, element12);

		printf("해시 테이블 내용:\n");
		displayHashTable(pHashTable);

		pElement = searchHT(pHashTable, "april");
		if (pElement != NULL) {
			printf("검색키-%s, 검색 결과-%d\n", pElement->key, pElement->value);

			deleteElementHT(pHashTable, "april");
			printf("검색키[%s]로 자료 삭제\n", "april");

			//printf("해시 테이블 내용:\n");
			//displayHashTable(pHashTable);

			pElement2 = searchHT(pHashTable, "april");
			if (pElement2 != NULL) {
				printf("검색키-%s, 검색 결과-%d\n", pElement2->key, pElement2->value);
			}

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
