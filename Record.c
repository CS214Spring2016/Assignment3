#include "Record.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//create
Record *createRecord(char *fName, char *token, int frequency)
{
	Record *record = (Record *)malloc(sizeof(struct Record));

	if(record == NULL)
	{
		return NULL;
	}

	record->filename = fName;
	record->token = token;
	record->freq = frequency;

	return record;

}

//compare to avoid duplicates
int equals(Record *rec1, Record *rec2);
{
	int testVal;
	Record *rec1 = (Record *)rec1;
	Record *rec2 = (Record *)rec2;

	testVal = strcmp(rec1->token, rec2->token);

	if(testVal == 0)
	{
		testVal = strcmp(rec1->filename, rec2->filename);
		return testVal;
	}

	return testVal;
}

//not sure if we need to free
//but why not include it
void freeRecord(Record *rec)
{
	if(rec != NULL)
	{
		free(rec->token);
		free(rec->filename);
		free(rec);
	}
}