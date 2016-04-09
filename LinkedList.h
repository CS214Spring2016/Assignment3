#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "Record.h"
#include <string.h>
#include <stdlib.h>

typedef int (*CompareFunction)(Record *, Record *);

struct Node
{
	Record *record;
	struct Node *next;
};
typedef struct Node Node;

//create list with record
Node* createNode(Record *record, Node *);

struct LinkedList_
{
	CompareFunction compareFunction;
	Node *head;
};
typedef struct LinkedList_ LinkedList;

LinkedList *createList(CompareFunction compare);

//preserve order insert
void insert(LinkedList *list, Record *newRec);


// //honestly who knows if we'll need this
// void delete(Record *rec);
