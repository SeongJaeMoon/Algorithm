#ifndef _STATIC_HASHING_CHAIN_
#define _STATIC_HASHING_CHAIN_

typedef struct HashTableType {
	int bucketSize;
	int currentElementCount;
	struct LinkedListType **ppElement;
} HashTable;

HashTable* createHashTable(int bucketSize);
int addSHT(HashTable* pHashTable, HashElement element);
int deleteElementHT(HashTable* pHashTable, char* key);
int hashFunction(char *pKey, int bucketSize);
unsigned int stringToInt(char *pKey);
HashElement* searchHT(HashTable* pHashTable, char* key);
LinkedList* searchBucket(HashTable* pHashTable, char* key);
HashElement* searchSlot(LinkedList* pList, char* key, int* pPostion);
void deleteHashTable(HashTable *pHashTable);
void displayHashTable(HashTable *pHashTable);

#endif

#ifndef _COMMON_HASHING_DEF_
#define _COMMON_HASHING_DEF_

#define TRUE		1
#define FALSE		0

#endif