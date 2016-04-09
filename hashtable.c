#include <string.h>
#include <stdlib.h>
#include "hashtable.h"

//constructor
HashTable *createTable()
{
	return (HashTable*)malloc(sizeof(struct HashTable));
}

//insert new node into table
void insert(HashTable *hashTable, char *token, char *filename)