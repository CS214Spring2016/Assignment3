/*
 * indexer.c
 *
 *  Created on: Apr 2, 2016
 *      Author: Michael Shafran
 *      Author: Pat Barrett
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
	printf(argv[2]);
	int *whatisthis = opendir(argv[2]);
	printf(strerror(errno));

	/*1. figure out if it is a file or not
	 * if file
	 * 		Call file handler
	 * if directory
	 * 		call directory handler
	 * if other
	 * 		fail
	 *
	 */




	return 1;
}

//DT_REG .. regular file
//DT_DIR .. directory


void directoryHandler(char * name){

	/* dirdes = opendir(name)
	 * dirent readdir(dirdes - gives first entry in directory
	 * test dirent for null - nothing in file
	 * get type
	 * 		file- call filehandler
	 * 		directory recuse directoryhandler
	 *
	 */

}

void fileHandler(char * name){

	/*read file
	 * 		tokenize WORDS
	 * 		put words in index by filename
	 *
	 */

}
