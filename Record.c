#include "Record.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//create
Record *createRecord(char *fName, char *token, int frequency)
{
	Record *record = (Record *)calloc(1,sizeof(struct Record_));

	if(record == NULL)
	{
		return NULL;
	}

	record->fileName = fName;
	record->token = token;
	record->freq = frequency;

	return record;

}

//compare to avoid duplicates
int equals(Record *rec1, Record *rec2)
{
	int testVal;
	Record *record1 = (Record *)rec1;
	Record *record2 = (Record *)rec2;

	testVal = strcmp(record1->token, record2->token);

	if(testVal == 0)
	{
		testVal = strcmp(record1->fileName, record2->fileName);
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
		free(rec->fileName);
		free(rec);
	}
}