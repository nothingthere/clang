/**************************************************************
 * Array.h
 * Author: Claudio <3261958605@qq.com>
 * Created: 2017-07-22 17:03:39
 * Commentary:
 ***************************************************************/
#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

typedef union {
  int ival;
  float fval;
  double dval;
  char *sval;
} Elem;

typedef struct {
  char type;
  Elem **elems;
} Array;

typedef Array *ArrayPtr;

ArrayPtr arrayInit(char type);
size_t arrayLen(ArrayPtr aptr);
void arrayClear(ArrayPtr aptr);
void arrayClearItem(Elem *elem, char type);

ArrayPtr arrayInsert(ArrayPtr aptr, int i, Elem elem);
ArrayPtr arrayAppend(ArrayPtr aptr, Elem elem);
ArrayPtr arrayAppendLeft(ArrayPtr aptr, Elem elem);

ArrayPtr arrayRemove(ArrayPtr aptr, int i);
ArrayPtr arrayPop(ArrayPtr aptr);
ArrayPtr arrayPopLeft(ArrayPtr aptr);

ArrayPtr arrayExtend(ArrayPtr dest, ArrayPtr src, char type);
ArrayPtr arrayCopy(ArrayPtr aptr, char type);
/* ArrayPtr arrayShallowCopy(ArrayPtr aptr, char type); */
/* void arrayShallowClear(ArrayPtr aptr); */

int arrayFind(ArrayPtr aptr, Elem elem);

Elem *arrayGet(ArrayPtr aptr, int i);

/* FIXME:  */
void arrayMap(ArrayPtr aptr, void (*fn)(Elem));

void arrayPrint(ArrayPtr aptr);

#endif
