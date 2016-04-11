CC = gcc
CCFLAGS = -Wall -g

all: index

index: indexer.o LinkedList.o Record.o hashtable.o
	$(CC) $(CCFLAGS) -o index indexer.o LinkedList.o Record.o hashtable.o

indexer.o: indexer.c Record.h LinkedList.h hashtable.h
	$(CC) $(CCFLAGS) -c indexer.c

LinkedList.o: LinkedList.c LinkedList.h Record.h
	$(CC) $(CCFLAGS) -c LinkedList.c

Record.o: Record.c Record.h
	$(CC) $(CCFLAGS) -c Record.c

hashtable.o: hashtable.c hashtable.h Record.h LinkedList.h
	$(CC) $(CCFLAGS) -c hashtable.c

clean:
	@rm -f index
	@rm -rf *.dSYM
	@rm -f *.o