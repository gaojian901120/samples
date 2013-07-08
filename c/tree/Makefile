CC = gcc
all: clean install
install: tree
tree: tree.o
	$(CC) -o tree tree.c
tree.o: tree.c
	$(CC) -c -o tree.o tree.c
clean:  
