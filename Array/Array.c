/*************************************************************
 * Array.c
 * Author: Claudio <3261958605@qq.com>
 * Created: 2017-07-21 22:12:47
 * Commentary:
 ***************************************************************/

#include "Array.h"
#include "Constants.h"
#include "Generic.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

ArrayPtr arrayInit(char type) {
  ArrayPtr aptr = (ArrayPtr)malloc(sizeof(Array));
  aptr->type = type;
  aptr->elems = (Elem **)malloc(sizeof(Elem *));
  aptr->elems[0] = NULL;
  return aptr;
}

size_t arrayLen(ArrayPtr aptr) {
  size_t n = 0;
  Elem **elems = aptr->elems;
  while (elems[n++])
    ;
  return --n;
}

void arrayClear(ArrayPtr aptr) {
  Elem *elem;
  char type = aptr->type;
  int n = arrayLen(aptr);
  while (--n >= 0) {
    elem = aptr->elems[n];
    if (STRING == type)
      free(elem->sval);
    free(elem);
  }
  free(aptr->elems);
  free(aptr);
}

ArrayPtr arrayInsert(ArrayPtr aptr, int i, Elem elem) {
  char type = aptr->type;
  Elem **elems;
  Elem *m;
  int n = arrayLen(aptr);

  if (i >= n)
    i = n;
  if (i < 0)
    i = 0;

  elems = (Elem **)realloc(aptr->elems, (n + 2) * sizeof(Elem *));
  elems[n + 1] = NULL;
  memmove(&elems[i + 1], &elems[i], (n - i + 1) * sizeof(Elem *));
  elems[i] = (Elem *)malloc(sizeof(Elem));
  m = elems[i];

  switch (type) {
  case INT:
    m->ival = elem.ival;
    break;
  case FLOAT:
    m->fval = elem.fval;
    break;
  case DOUBLE:
    m->dval = elem.dval;
    break;
  case STRING:
    m->sval = strdup(elem.sval);
    break;
  }

  aptr->elems = elems;
  return aptr;
}

ArrayPtr arrayAppend(ArrayPtr aptr, Elem elem) {
  return arrayInsert(aptr, arrayLen(aptr), elem);
}

ArrayPtr arrayAppendLeft(ArrayPtr aptr, Elem elem) {
  return arrayInsert(aptr, 0, elem);
}

ArrayPtr arrayRemove(ArrayPtr aptr, int i) {
  char type = aptr->type;
  int n = arrayLen(aptr);
  Elem **elems = aptr->elems;
  Elem *elem;

  if (0 == n)
    return NULL;

  if (i >= n)
    i = n - 1;
  if (i < 0)
    i = 0;

  elem = elems[i];

  if (STRING == type)
    free(elem->sval);
  free(elem);

  memmove(&elems[i], &elems[i + 1], (n - i) * sizeof(Elem *));
  elems = (Elem **)realloc(elems, n * sizeof(Elem *));

  aptr->elems = elems;

  return aptr;
}

ArrayPtr arrayPop(ArrayPtr aptr) {
  return arrayRemove(aptr, arrayLen(aptr) - 1);
}

ArrayPtr arrayPopLeft(ArrayPtr aptr) { return arrayRemove(aptr, 0); }

ArrayPtr arrayExtend(ArrayPtr dest, ArrayPtr src, char type) {
  if (!(type == dest->type && type == src->type))
    return dest;

  Elem **src_elems = src->elems;
  ArrayPtr tmp = dest;
  int len = arrayLen(src);
  int i = 0;

  while (i < len)
    tmp = arrayAppend(tmp, *src_elems[i++]);

  return dest;
}

ArrayPtr arrayCopy(ArrayPtr aptr, char type) {
  if (type != aptr->type)
    return NULL;
  ArrayPtr tmp = arrayInit(type);

  tmp = arrayExtend(tmp, aptr, type);
  return tmp;
}

/* ArrayPtr arrayShallowCopy(ArrayPtr aptr, char type) { */
/*   if (type != aptr->type) */
/*     return NULL; */
/*   ArrayPtr tmp = arrayInit(type); */
/*   int len = arrayLen(aptr); */
/*   int i; */

/*   tmp->elems = (Elem **)realloc(tmp->elems, (len + 1) * sizeof(Elem *)); */
/*   for (i = 0; i <= len; i++) */
/*     tmp->elems[i] = aptr->elems[i]; */

/*   return tmp; */
/* } */

/* void arrayShallowClear(ArrayPtr aptr) { */
/*   free(aptr->elems); */
/*   free(aptr); */
/* } */

int arrayFind(ArrayPtr aptr, Elem elem) {
  int n = arrayLen(aptr);
  char type = aptr->type;
  Elem *m;

  while (--n >= 0) {
    m = aptr->elems[n];
    switch (type) {
    case INT:
      if (m->ival == elem.ival)
        return n;
      break;
    case FLOAT:
      if (m->fval == elem.fval)
        return n;
      break;
    case DOUBLE:
      if (m->dval == elem.dval)
        return n;
      break;
    case STRING:
      if (strcmp(m->sval, elem.sval) == 0)
        return n;
      break;
    }
  }
  return NOT_FOUND;
}

Elem *arrayGet(ArrayPtr aptr, int i) {
  int n = arrayLen(aptr);

  if (i < 0 || i >= n)
    return NULL;

  return (aptr->elems)[i];
}

/* FIXME:  */
void arrayMap(ArrayPtr aptr, void (*fn)(Elem));

void arrayPrint(ArrayPtr aptr) {
  char type = aptr->type;
  size_t len = arrayLen(aptr);
  size_t n = 0;
  Elem **elems = aptr->elems;
  Elem *elem;

  printf("[");
  while (n < len) {
    elem = elems[n++];
    switch (type) {
    case INT:
      printf("%d", elem->ival);
      break;
    case FLOAT:
      printf("%f", elem->fval);
      break;
    case DOUBLE:
      printf("%f", elem->dval);
      break;
    case STRING:
      printf("\"%s\"", elem->sval);
      break;
    }

    if (n < len)
      printf(", ");
  }

  printf("]\n");
}
