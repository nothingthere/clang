/**************************************************************
 * Hash.c
 * Author: Claudio <3261958605@qq.com>
 * Created: 2017-07-22 09:31:51
 * Commentary:
 ***************************************************************/
#include "Hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Hashtable *hashInit(size_t size) {
  Hashtable *tmp = NULL;
  size_t i;

  if (size <= 0)
    size = 1;

  tmp = (Hashtable *)malloc(sizeof(Hashtable));

  tmp->size = size;
  tmp->nodes = (Hashnode **)malloc(size * sizeof(Hashnode *));

  for (i = 0; i < size; i++) {
    (tmp->nodes)[i] = NULL;
  }

  return tmp;
}

size_t hashHash(Hashtable *table, char *key) {
  size_t hashval;

  for (hashval = 0; '\0' != *key; key++)
    hashval = *key + 31 * hashval;

  return hashval % table->size;
}

Hashnode *hashGet(Hashtable *table, char *key) {

  size_t hashval = hashHash(table, key);
  Hashnode *node;
  for (node = (table->nodes)[hashval]; node != NULL; node = node->next)
    if (strcmp(key, node->key) == 0)
      return node;

  return NULL;
}

char *hashLookup(Hashtable *table, char *key) {
  Hashnode *node = hashGet(table, key);
  if (node)
    return node->value;
  else
    return NULL;
}

Hashtable *hashInstall(Hashtable *table, char *key, char *value) {
  Hashnode **nodes = table->nodes;
  Hashnode *node;
  size_t hashval;
  if (NULL == (node = hashGet(table, key))) {
    node = (Hashnode *)malloc(sizeof(Hashnode));
    hashval = hashHash(table, key);
    node->key = strdup(key);
    node->next = nodes[hashval];
    nodes[hashval] = node;
  } else
    free(node->value);

  node->value = strdup(value);

  return table;
}

/*
   从链表中删除元素的方法：
   https://www.cs.bu.edu/teaching/c/linked-list/delete/
   分为：删除第一个元素，和其他位置元素2种情况
*/

int hashUninstall(Hashtable *table, char *key) {
  Hashnode **nodes = table->nodes;
  size_t hashval = hashHash(table, key);
  Hashnode *node;
  Hashnode *prev_node = NULL;

  for (node = nodes[hashval]; node != NULL;
       prev_node = node, node = node->next) {

    if (strcmp(key, node->key) == 0) {

      if (NULL == prev_node) {
        nodes[hashval] = node->next;
      } else
        prev_node->next = node->next;

      free(node->key);
      free(node->value);
      free(node);
      return 1;
    }
  }
  return 0;
}

size_t hashLen(Hashtable *table) {
  size_t n, i;
  n = i = 0;
  Hashnode **nodes = table->nodes;
  Hashnode *node;
  while (i < table->size) {
    node = nodes[i++];
    while (node) {
      n++;
      node = node->next;
    }
  }
  return n;
}

void hashMap(Hashtable *table, void (*fn)(void *key, void *value)) {
  size_t i = 0;
  Hashnode **nodes = table->nodes;
  Hashnode *node;

  while (i < table->size) {
    node = nodes[i++];
    while (node) {
      fn(node->key, node->value);
      node = node->next;
    }
  }
}

Strings hashKeys(Hashtable *table) {
  Strings strings = stringsInit();
  size_t i = 0;
  Hashnode **nodes = table->nodes;
  Hashnode *node;

  while (i < table->size) {
    node = nodes[i++];
    while (node) {
      strings = stringsAppend(strings, node->key);
      node = node->next;
    }
  }

  return strings;
}

Strings hashValues(Hashtable *table) {
  Strings strings = stringsInit();
  size_t i = 0;
  Hashnode **nodes = table->nodes;
  Hashnode *node;

  while (i < table->size) {
    node = nodes[i++];
    while (node) {
      strings = stringsAppend(strings, node->value);
      node = node->next;
    }
  }

  return strings;
}

void hashPrint(Hashtable *table) {
  size_t i = 0;
  Hashnode **nodes = table->nodes;
  Hashnode *node;

  printf("{");
  while (i < table->size) {
    for (node = nodes[i]; node != NULL; node = node->next)
      printf("\"%s\": \"%s\", ", node->key, node->value);
    i++;
  }
  printf("\b\b}\n");
}

void hashClear(Hashtable *table) {
  size_t i = 0;
  Hashnode **nodes = table->nodes;
  Hashnode *node, *tmp;

  while (i < table->size) {
    node = nodes[i];
    while (NULL != node) {
      tmp = node;
      free(node->key);
      free(node->value);
      node = node->next;
      free(tmp);
    }
    i++;
  }

  free(nodes);
  free(table);
}
