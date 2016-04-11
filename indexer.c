/*
 * indexer.c
 *
 *  Created on: Apr 2, 2016
 *      Author: Michael Shafran
 *      Author: Pat Barrett
 */
#include "hashtable.h"
#include "Record.h"
#include "LinkedList.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

void toLowercase(char *str)
{
	for(int i = 0; i<strlen(str); i++)
	{
		str[i] = tolower(str[i]);
	}
}

void stripNonAlpha(char *str)
{
	for(int i = 0; i < strlen(str); i++)
	{
		if(isalnum(str[i]) == 0)
		{
			str[i] = ' ';
		}
	}
}

void tokenizeInsert(char *filename, char *str)
{
	const char delims[2] = " ";
	char *token;
	FILE *outputFILE;
	outputFILE = fopen("outputFILE.txt", "a+");

	HashTablePtr *ptr = createTablePtr();


	//first token
	token = strtok(str,delims);


	while(token != NULL)
	{
		Record *rec = createRecord(filename, token, 1);
		insertTable(ptr->hashTable, rec);
		printf("it appears as if insert into hash table succeeded\n");
		token = strtok(NULL,delims);
	}

	printf("we got to the print to file place\n");
	printToConsole(ptr);

}

int main(int argc, char **argv)
{	
	//FILE *invIndFile;
	FILE *givenFile;
	char buff[2000];
	//char* givenIndName = argv[1];
	char* givenPath = argv[2];

	if(argc != 3)
	{
		printf("Invalid num of arguments. plz no.");
		return 0;
	}

	// invIndFile = fopen(givenIndName, "a+");
	// fclose(invIndFile);
	
	givenFile = fopen(givenPath, "r");

	printf("opening %s:\n", givenPath);

	//in which we open the text file and attempt to tokenize it
	fgets(buff, 2000, (FILE*)givenFile);
	toLowercase(buff);
	stripNonAlpha(buff);

	printf("about to try hash table shit\n");
	tokenizeInsert(givenPath,buff);


	//printf("should be all lowercase below:\n%s\n",buff);


}

//DT_REG .. regular file
//DT_DIR .. directory


// int validDirectory(char *directory)
// {
// 	DIR* dir = opendir(directory);
// 	if(dir == NULL)
// 	{
// 		return 0;
// 	}
// 	closedir(dir);
// 	return 1;
// }

// int validFile(char *filename)
// {
// 	FILE *file = fopen(filename, "r");
// 	if(file == NULL)
// 	{
// 		return 0;
// 	}
// 	fclose(file);
// 	return 1;
// }


