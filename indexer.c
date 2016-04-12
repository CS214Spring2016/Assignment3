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
#include <sys/stat.h>
HashTablePtr *htptr;

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




	//first token
	token = strtok(str,delims);


	while(token != NULL)
	{
		Record *rec = createRecord(filename, token, 1);
		insertTable(htptr->hashTable, rec);
		//printf("it appears as if insert into hash table succeeded\n");
		token = strtok(NULL,delims);
	}

	printf("we got to the print to file place\n");


}


int doFileStuff(char * givenPath){

		FILE *givenFile = fopen(givenPath, "r");
		//HashTablePtr *ptr = (HashTablePtr*)malloc(sizeof(struct HashTablePtr));
		char *buff = (char*)calloc(2000,sizeof(char));

		printf("opening %s:\n", givenPath);

		//in which we open the text file and attempt to tokenize it
		fgets(buff, 2000, (FILE*)givenFile);
		toLowercase(buff);
		stripNonAlpha(buff);

		printf("about to try hash table shit\n");
		tokenizeInsert(givenPath,buff);


	return 1;

}
int doDirectoryStuff(char * directorypath){
	strcat(directorypath,"/");
	char *safetoedit = malloc(strlen(directorypath) + 1);
	strcpy(safetoedit,directorypath);


	DIR* dir;
	struct dirent * drt;

	if ((dir = opendir(directorypath))==NULL){
		printf("Couldnt Open\n");
		return 0;
	}
	do{
		if ((drt = readdir(dir)) != NULL) {
			strcpy(safetoedit,directorypath);

			if(drt->d_type == DT_REG){
				printf("ive found anotha file");
				strcat(safetoedit,drt->d_name);
				printf("%s\n",safetoedit);
				doFileStuff(safetoedit);
			}
			else if(drt->d_type == DT_DIR){
				if( !strcmp(drt->d_name, ".") || !strcmp(drt->d_name, "..") ){

				}
				else{
				printf("ive found anotha directory\n");
				strcat(safetoedit,drt->d_name);
				printf("%s\n",safetoedit);
				doDirectoryStuff(safetoedit);
				}

			}
		}


	}while(drt != NULL);



//	while(dir != NULL)
//	{
//		char * newpath = strcat(directorypath,drt->d_name);
//		printf("%s\n", newpath);
//		if(drt->d_type == DT_REG){
//			printf("ive found anotha file");
//			doFileStuff(newpath);
//		}
//		else if(drt->d_type == DT_DIR){
//			printf("ive found anotha directory");
//			doDirectoryStuff(newpath);
//		}
//		drt = readdir(dir);
//	}
	free(safetoedit);
	closedir(dir);


	return 1;

}

int main(int argc, char **argv)
{	
	//FILE *invIndFile;
	//	FILE *givenFile;
	//	char buff[2000];
	//char* givenIndName = argv[1];
	char* givenPath = argv[2];
	htptr = createTablePtr();

	if(argc != 3)
	{
		printf("Invalid num of arguments. plz no.");
		return 0;
	}

	// invIndFile = fopen(givenIndName, "a+");
	// fclose(invIndFile);
	//TODO file not found and check if file vs directory

	struct stat s;
	if( stat(givenPath,&s) == 0 )
	{
	    if( s.st_mode & S_IFDIR )
	    {
	        printf("Youre a directory, harry.\n");
	        doDirectoryStuff(givenPath);

	    }
	    else if( s.st_mode & S_IFREG )
	    {
	    	printf("Youre a file, harry.\n");
	    	doFileStuff(givenPath);
	    }
	    else
	    {
	    	printf("Something else");
	    }
	}
	else
	{
		printf("error");
	}

	

	printToConsole(htptr);


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


