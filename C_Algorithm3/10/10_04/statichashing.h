#ifndef _STATIC_HASHING_
#define _STATIC_HASHING_

#define HASH_KEY_SIZE	30

typedef enum HashElementStatusType { EMPTY = 0, USED, DELETED  } HashElementStatus;

typedef struct HashElementType {
	char key[HASH_KEY_SIZE + 1];
	int value;
	HashElementStatus status;
} HashElement;

typedef struct HashTableType {
	int bucketSize;
	int currentElementCount;
	HashElement *pElement;
} HashTable;

// 해시 테이블의 생성.
HashTable* createHashTable(int bucketSize);

// 자료의 추가.
int addElementSHT(HashTable* pHashTable, HashElement element);

// 자료의 삭제.
int deleteElementHT(HashTable* pHashTable, char* key);

int hashFunction(char *pKey, int bucketSize);

unsigned int stringToInt(char *pKey);

int isEmptyBucket(HashElement* pElement);

int isEmptyOrDeletedBucket(HashElement* pElement);

// 자료의 검색.
HashElement* searchHT(HashTable* pHashTable, char* key);

// 해시 테이블 내용 표시.
void displayHashTable(HashTable *pHashTable);

// 해시 테이블의 현재 자료의 개수.
int getElementCountHT(HashTable *pHashTable);

// 해시 테이블의 삭제.
void deleteHashTable(HashTable *pHashTable);

#endif

#ifndef _COMMON_HASHING_DEF_
#define _COMMON_HASHING_DEF_

#define TRUE		1
#define FALSE		0

#endif