# Makefile
# Author: Claudio <3261958605@qq.com>
# Created: 2017-07-22 10:02:02
test.out:Hash.o test.c
	gcc Hash.o test.c ../Strings/Strings.o -o test.out
	valgrind --leak-check=full --show-leak-kinds=all ./test.out

Hash.o:Hash.c
	gcc -c Hash.c
