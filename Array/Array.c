/*************************************************************
 * Array.c
 * Author: Claudio <3261958605@qq.com>
 * Created: 2017-07-21 22:12:47
 * Commentary:
 ***************************************************************/

#include <stddef.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

typedef void **Array;
typedef void *Item;

Array arrayInit(char type) {
  size_t size;
  void **array;

  switch (type) {
  case 'b':
    size = sizeof(char *);
    break;
  case 'i':
    size = sizeof(int *);
  case 'f':
    size = sizeof(float *);
  default:
    size = 0;
    break;
  }

  array = malloc(size);
  array[0] = NULL;
  return array;
}

size_t arrayLen(Array array) {
  size_t n = 0;
  while (array[n++])
    ;
  return --n;
}

void arrayClear(Array array) {
  int n = arrayLen(array);
  while (--n >= 0)
    free(array[n]);
  free(array);
}

Array arraryInsert(Array array, int i, Item item) {
  Array tmp;
  int n = arrayLen(array);

  if (i >= n)
    i = n;
  if (i < 0)
    i = 0;

  tmp = realloc(array, (n + 2) * sizeof(Item));
  tmp[n + 1] = NULL;

  memmove(&tmp[i + 1], &tmp[i], (n - i + 1) * sizeof(Item));
  /* FIXME:  */
}
