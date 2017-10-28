all: random.c
	gcc -o file_randgen random.c
clean:
	rm *~
run: all
	./file_randgen
