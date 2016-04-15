#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "hashtable.h"
#include "LinkedList.h"
#include "Record.h"

//constructor
HashTable *createTable()
{
	return (HashTable*)calloc(1000,sizeof(struct HashTable));
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

	i = isalpha(rec->token[0]) == 0 ? (int)rec->token[0] - ascZero + 26 : ((int)rec->token[0] - ascA);
	//printf("trying to insert %s at location %d\n", rec->token, i);
	


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

//void printToFile(HashTablePtr *ptr, FILE *file)
//{
//	//Record *rec;
//	LinkedList *list;
//	char *token;
//	int count;
//
//	for(int i = 0; i < 36; i++)
//	{
//		count = 0;
//		token = NULL;
//
//
//		printf("assigning list");
//		list = ptr->hashTable->boxes[i];
//
//		printf("about to enter while loop\n");
//
//		if(list == NULL)
//		{
//			printf("list head null\n");
//			break;
//		}
//		while(list != NULL)
//		{
//			printf("while loop entered\n");
//			if(token == NULL || strcmp(list->head->record->token, token) != 0)
//			{
//				printf("entered null check for token and strcmp\n");
//				count = 1;
//				token = list->head->record->token;
//				fprintf(file, "<list> %s \n%s %d", token, list->head->record->fileName, list->head->record->freq);
//				fprintf(file, "\n</list>\n");
//			}
//			else
//			{
//				printf("entered else condition\n");
//				if(count < 5)
//				{
//					fprintf(file, "<list> %s \n%s %d", token, list->head->record->fileName, list->head->record->freq);
//					count++;
//				}
//			}
//		}
//
//		printf("apparently list head is null\n");
//	}
//
//}

void printToConsole(HashTablePtr *ptr, FILE * f)
{
	LinkedList *list;
	fprintf(f, "{\"list\":[");
	char * lastword;
	char * word;
	char * path;
	int freq;
	lastword = "zntzqkrjtdcglsb";
	for(int i = 0; i < 36; i++)
	{
		list = ptr->hashTable->boxes[i];
		if(((Node*)(list) == NULL))
		{
			//printf("head null at value: %d\n", i);
		}
		else
		{
			while(list->head != NULL)
			{
				word = list->head->record->token;
				path = list->head->record->fileName;
				freq = list->head->record->freq;
				if(!strcmp(word, lastword)){
					fprintf(f,"{%s:%d}",path,freq);
				}
				else{
					fprintf(f,"{%s:[\n{%s:%d}",word,path,freq);
				}
				printf("token: %s, filename: %s, frequency: %d hashtable index: %d\n", list->head->record->token, list->head->record->fileName, list->head->record->freq, i);
				//fprintf(f,"token: %s, filename: %s, frequency: %d hashtable index: %d\n", list->head->record->token, list->head->record->fileName, list->head->record->freq, i);
				list->head = list->head->next;

			}
		}
	}
	fprintf(f, "]}");

	return;

}




























