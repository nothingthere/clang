/**************************************************************
 * test.c
 * Author: Claudio <3261958605@qq.com>
 * Created: 2017-07-22 09:31:58
 * Commentary: 测试程序
 ***************************************************************/
#include "Hash.h"
#include <stdio.h>

void print(void *key, void *value) {
  printf("%s -> %s\n", (char *)key, (char *)value);
}

/* void foo(void *key, void *_value) { */
/*   Strings strings = stringsInit(); */

/*   strings = stringsAppend(strings, (char *)key); */
/* } */

int main(void) {
  Hashtable *table = hashInit(2);
  printf("初始化后，哈希表中的键值对个数为：%lu\n", hashLen(table));
  hashInstall(table, "name", "claudio");
  hashInstall(table, "age", "23");
  hashInstall(table, "gender", "male");
  hashPrint(table);
  hashUninstall(table, "age");

  printf("name = %s\n", hashLookup(table, "name"));
  printf("最终键值对个数为：%lu\n", hashLen(table));

  printf("===================\n");
  printf("测试hashMap()函数结果：\n");
  hashMap(table, print);

  printf("===================\n");
  printf("测试于Strings模块一起使用：\n");
  Strings strs = hashKeys(table);
  printf("keys:\n");
  stringsPrint(strs);
  stringsClear(strs);

  strs = hashValues(table);
  printf("values:\n");

  stringsPrint(strs);
  stringsClear(strs);

  hashClear(table);
  return 0;
}
