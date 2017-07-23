# Makefile
# Author: Claudio <3261958605@qq.com>
# Created: 2017-07-22 18:32:50
test.out:Array.o  test.c
	gcc Array.o  test.c -o test.out
	valgrind ./test.out

Array.o:Array.c
	gcc -c  Array.c
