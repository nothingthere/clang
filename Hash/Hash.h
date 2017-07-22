/**************************************************************
 * Hash.h
 * Author: Claudio <3261958605@qq.com>
 * Created: 2017-07-22 09:31:41
 * Commentary:
 ***************************************************************/
#ifndef HASH_H
#define HASH_H

#include "Strings.h"
#include <stddef.h>

typedef struct hashnode {
  struct hashnode *next;
  char *key;
  char *value;
} Hashnode;

typedef struct {
  size_t size;
  Hashnode **nodes;
} Hashtable;

Hashtable *hashInit(size_t size);
size_t hashHash(Hashtable *table, char *key);

Hashnode *hashGet(Hashtable *table, char *key);
char *hashLookup(Hashtable *table, char *key);
Hashtable *hashInstall(Hashtable *table, char *key, char *value);
int hashUninstall(Hashtable *table, char *key);

size_t hashLen(Hashtable *table);
void hashMap(Hashtable *table, void (*fn)(void *key, void *value));

Strings hashKeys(Hashtable *table);
Strings hashValues(Hashtable *table);

void hashPrint(Hashtable *table);
void hashClear(Hashtable *table);

#endif
