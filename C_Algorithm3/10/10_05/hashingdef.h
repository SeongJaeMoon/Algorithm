#ifndef _STATIC_HASHING_DEF_
#define _STATIC_HASHING_DEF_

#define HASH_KEY_SIZE	10
 
typedef struct HashElementType {
	char key[HASH_KEY_SIZE + 1];
	int value;
} HashElement;

#endif
