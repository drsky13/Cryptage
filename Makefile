programme: fonction.o test.o
	gcc -o programme fonction.o test.o
fonction.o: fonction.c
	gcc -c -o fonction.o fonction.c
test.o: fonction.h test.c
	gcc -c -o test.o test.c
