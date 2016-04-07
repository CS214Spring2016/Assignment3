COMPILER = gcc
CCFLAGS = -Wall -g

all: index

index:
	$(COMPILER) $(CCFLAGS) -o index indexer.c

clean:
	@rm -f index
	@rm -f *.o