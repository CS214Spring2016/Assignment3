#include "Record.h"
#include "LinkedList.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Node* createNode(Record *record, Node *next)
{
	Node* node = (Node*)malloc(sizeof(struct Node));
	
	//malloc fail check
	if(node != NULL)
	{
		node->record = record;
		node->next = next;
		return node;
	}
	else
	{
		return NULL;
	}

}

LinkedList* createList(CompareFunction compare);
{
	LinkedList *list = (LinkedList*)malloc(sizeof(struct LinkedList));
	if(list != NULL)
	{
		list->head = NULL;
		list->compareFunction = compare;
		return list;
	}
	else
	{
		return NULL;
	}
}


//insert preserve order
void insertList(LinkedList *list, Record *newRec)
{
	int compVal;
	Node *temp;
	Node *curr;
	Node *prev;

	if(list == NULL)
	{
		return;
	}

	//add temp as head
	if(list->head == NULL)
	{
		temp = createNode(newRec, NULL);
		if(temp != NULL)
		{
			list->head = temp;
			return;
		}
		else
		{
			free(temp);
			return;
		}


	}

	//add temp to head
	if((compVal = list->compareFunction(newRec, list->head->record)) <= 0)
	{
		//item belongs in front of list
		if(compVal < 0)
		{
			temp = createNode(newRec, list->head);
			if(temp != NULL)
			{
				temp->next = list->head;
				list->head = temp;
				return;
			}
			else
			{
				free(temp);
				return;
			}
		}
		//item is duplicate if 0
		else
		{
			list->head->record->freq++;
			return;
		}
	}

	//add temp to where it belongs in list if not at head
	curr = list->head;
	prev = NULL;

	while(curr != NULL)
	{
		compVal = list->compareFunction(newRec,curr->record);
		if(compVal == 0)
		{
			//equivalent
			curr->record->freq++;
			return;
		}
		else if(compVal < 0)
		{
			temp = createNode(newRec, curr);
			if(temp != NULL)
			{
				prev->next = temp;
				return;
			}
			else
			{
				free(temp);
				return;
			}
		}

		prev = curr;
		curr = curr->next;
	}

	//add to end
	temp = createNode(newRec, NULL);
	if(temp != NULL)
	{
		prev->next = temp;
		return;
	}
	else
	{
		free(temp);
		return;
	}

}

















