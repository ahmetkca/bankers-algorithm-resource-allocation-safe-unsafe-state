all:
	gcc -g -o main main.c banker.c

clean:
	rm -f main
