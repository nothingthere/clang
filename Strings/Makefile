test.out:Strings.o test.c
	gcc Strings.o test.c -o test.out
	valgrind --leak-check=full ./test.out

Strings.o:Strings.c
	gcc -c Strings.c
