//record object, will be placed in linked list
//holds the file name, a token from the string in a file & frequency of times seen
//
struct Record
{
	char *fileName;
	char *token;
	int freq;
};
typedef struct Record Record;

//create
Record *createRecord(char *, char *, int);

//free
void freeRecord(Record *);

//equals to avoid collision in hashmap and duplicates
int equals(Record *, Record *);