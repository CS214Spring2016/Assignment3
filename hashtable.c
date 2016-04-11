#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "hashtable.h"
#include "LinkedList.h"
#include "Record.h"

//constructor
HashTable *createTable()
{
	return (HashTable*)malloc(sizeof(struct HashTable));
}

//insert new node into table
void insertTable(HashTable *hashTable, Record *rec)
{
	LinkedList *list;
	int i;

	//hash function will use ascii values, thats why we have 36 slots in the table
	//they will work as array indices, because i know how hash tables
	//letters from 0-26, numbers from 27-36
	int ascZero = 48;
	int ascA = 97;

	if(isalpha(rec->token[0]) == 0)
	{
		i = (int)rec->token[0] - ascA;
	}
	else
	{
		i = (int)rec->token[0] - ascZero + 26;
	}

	list = hashTable->boxes[i];

	if(list == NULL)
	{
		hashTable->boxes[i] = createList(equals);
	}

	insertList(hashTable->boxes[i], rec);
}

HashTablePtr *createTablePtr()
{
	HashTablePtr *ptr = (HashTablePtr*)malloc(sizeof(struct HashTablePtr));

	if(ptr == NULL)
	{
		return NULL;
	}

	ptr->hashTable = createTable();

	if(ptr->hashTable != NULL)
	{
		return ptr;
	}
	else
	{
		free(ptr);
		return NULL;
	}
}

void printToFile(HashTablePtr *ptr, FILE *file)
{
	Record *rec;
	LinkedList *list;
	char *token;
	int count;

	for(int i = 0; i < 36; i++)
	{
		count = 0;
		token = NULL;


		printf("assigning list");
		list = ptr->hashTable->boxes[i];

		printf("about to enter while loop\n");

		if(list->head == NULL)
		{
			printf("list head null\n");
		}
		while(list->head != NULL)
		{
			printf("while loop entered\n");
			if(token == NULL || strcmp(list->head->record->token, token) != 0)
			{
				printf("entered null check for token and strcmp\n");
				count = 1;
				token = list->head->record->token;
				fprintf(file, "<list> %s \n%s %d", token, list->head->record->fileName, list->head->record->freq);
				fprintf(file, "\n</list>\n");
			}
			else
			{
				printf("entered else condition\n");
				if(count < 5)
				{
					fprintf(file, "<list> %s \n%s %d", token, list->head->record->fileName, list->head->record->freq);
					count++;
				}
			}
		}

		printf("apparently list head is null\n");
	}

}

void printToConsole(HashTablePtr *ptr)
{
	LinkedList *list;
	
	for(int i = 0; i < 36; i++)
	{
		list = ptr->hashTable->boxes[i];

		printf("test: %d\n", (int)list->head);
	}

	return;

}




























