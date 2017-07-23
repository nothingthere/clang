/**************************************************************
* Strings.c
* Author: Claudio <3261958605@qq.com>
* Created: 2017-07-21 13:42:09
* Commentary: 动态字符串数组实现
***************************************************************/

#include "Strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *_safe_malloc(size_t size) {
  void *tmp = malloc(size);
  if (!tmp)
    return _safe_malloc(size);
  else
    return tmp;
}

Strings stringsInit(void) {
  Strings strings;
  strings = (Strings)_safe_malloc(sizeof(String));
  strings[0] = NULL;
  return strings;
}

size_t stringsLen(Strings strings) {
  size_t n = 0;
  while (strings[n++])
    ;
  return --n;
}

void stringsClear(Strings strings) {
  int n = stringsLen(strings);
  while (--n >= 0)
    free(strings[n]);

  free(strings);
}

Strings stringsInsert(Strings strings, int i, String str) {
  Strings tmp;
  int n = stringsLen(strings);

  if (i >= n)
    i = n;
  if (i < 0)
    i = 0;

  tmp = (Strings)realloc(strings, (n + 2) * sizeof(String));
  tmp[n + 1] = NULL;

  memmove(&tmp[i + 1], &tmp[i], (n - i + 1) * sizeof(String));
  tmp[i] = strdup(str);

  return tmp;
}

Strings stringsAppend(Strings strings, String str) {
  return stringsInsert(strings, stringsLen(strings), str);
}

Strings stringsAppendLeft(Strings strings, String str) {
  return stringsInsert(strings, 0, str);
}

Strings stringsRemove(Strings strings, int i) {
  int n = stringsLen(strings);
  Strings tmp;

  if (0 == n)
    return NULL;

  if (i >= n)
    i = n - 1;
  if (i < 0)
    i = 0;

  free(strings[i]);
  memmove(&strings[i], &strings[i + 1], (n - i) * sizeof(String));
  tmp = (Strings)realloc(strings, n * sizeof(String));

  return tmp;
}

Strings stringsPop(Strings strings) {
  return stringsRemove(strings, stringsLen(strings) - 1);
}

Strings stringsPopLeft(Strings strings) { return stringsRemove(strings, 0); }

Strings stringsExtend(Strings dest, Strings src) {
  int len = stringsLen(src);
  Strings tmp = dest;
  int i = 0;

  while (i < len)
    tmp = stringsAppend(tmp, src[i++]);

  return tmp;
}

Strings stringsCopy(Strings strings) {
  Strings tmp = stringsInit();

  tmp = stringsExtend(tmp, strings);

  return tmp;
}

int stringsFind(Strings strings, String str) {
  int n = stringsLen(strings);
  int i = -1;

  while (--n >= 0) {
    if (0 == strcmp(str, strings[n])) {
      i = n;
      break;
    }
  }
  return i;
}

String stringsGet(Strings strings, int i) {
  int n = stringsLen(strings);
  if (i < 0 || i >= n)
    return NULL;
  return strings[i];
};

void stringsMap(Strings strings, void (*fn)(String)) {
  int len = stringsLen(strings);
  int n = 0;
  while (n < len)
    (*fn)(strings[n++]);
}

void stringsPrint(Strings strings) {
  size_t len = stringsLen(strings);
  size_t n = 0;

  printf("[");
  while (n < len) {
    printf("\"%s\"", strings[n++]);
    if (n < len)
      printf(", ");
  }

  printf("]\n");
}
