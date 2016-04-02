COMPILER = gcc
CCFLAGS = -Wall -g

all: indexer

indexer:
	$(COMPILER) $(CCFLAGS) -o indexer indexer.c

clean:
	@rm -f indexer
	@rm -f *.o