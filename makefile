CC = gcc
CCFLAGS = -Wall -g

all: index

index: indexer.o linkedlist.o Record.o hashtable.o
	$(COMPILER) $(CCFLAGS) -o index indexer.o linkedlist.o Record.o hashtable.o

indexer.o: indexer.c Record.h LinkedList.h hashtable.h
	$(CC) $(CCFLAGS) -c indexer.c

linkedlist.o: LinkedList.c LinkedList.h Record.h
	$(CC) $(CCFLAGS) -c LinkedList.c

# tokenizer.o: tokenizer.c tokenizer.h
# 	$(CC) $(CCFLAGS) -c tokenizer.c

Record.o: Record.c Record.h
	$(CC) $(CCFLAGS) -c Record.c

hashtable.o: hashtable.c hashtable.h Record.h LinkedList.h
	$(CC) $(CCFLAGS) -c hashtable.c

clean:
	@rm -f index
	@rm -f *.o