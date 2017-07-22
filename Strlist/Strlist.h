/**************************************************************
 * Strlist.h
 * Author: Claudio <3261958605@qq.com>
 * Created: 2017-07-21 23:48:42
 * Commentary:
 ***************************************************************/
#ifndef STRLIST_H
#define STRLIST_H

#include <stddef.h>

typedef struct strlist {
  char *str;
  struct strlist *next;

} Strlist;

Strlist strlistInit(void);
size_t strlistLen(Strlist *list);

#endif
