CC = gcc
objects = tree.o queue.o
tree: $(objects)
	$(CC) -g -o tree $(objects)
tree.o: tree.h
queue.o: queue.h

.PHONY : clean
clean:
	-rm tree $(objects)
