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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char **argv)
{	
	printf("this is me testing handling things in files and directories");

	FILE *invIndFile;
	char* givenIndName = argv[1];
	char* givenPath = argv[2];

	if(argc != 3)
	{
		printf("Invalid num of arguments. plz no.");
		return 0;
	}
}

//DT_REG .. regular file
//DT_DIR .. directory


int validDirectory(char *directory)
{
	DIR* dir = opendir(directory);
	if(dir == NULL)
	{
		return 0;
	}
	closedir(dir);
	return 1;
}

int validFile(char *filename)
{
	FILE *file = fopen(filename, "r");
	if(file == NULL)
	{
		return 0;
	}
	fclose(file);
	return 1;
}

void toLowercase(char *str)
{
	for(int i = 0; i<strlen(str); i++)
	{
		str[i] = tolower(str[i]);
	}
}

void loopDirectory(char *directory)
{
	DIR *parent;
	struct dirent 
}
