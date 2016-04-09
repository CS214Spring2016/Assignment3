#include "Record.h"
#include <stdio.h>

//hashtable to store the information
//uses linked list of nodes wich have records

struct HashTable
{
	//one box for each letter and digit
	//hash function will be based on ascii value
	LinkedList *boxes[36];
};
typedef struct HashTable HashTable;

//pointer to sorted list of list of nodes of records
//listception
//can we go any deeper
//lets not find out
struct HashTablePtr
{
	HashTable *hashTable;
};
typedef struct HashTablePtr HashTablePtr;

//make new hashtable and pointer
HashTable *createTable();
HashTablePtr *createTablePtr();

//insert into list
//using token and filename
void insert(HashTable *, Record *rec);

//print file as text for now, no formatting yet
//maybe lol
int printToFile(HashTablePtr *, FILE *);

//free
void destroyTable(HashTablePtr *);

