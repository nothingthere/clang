/**************************************************************
 * test.c
 * Author: Claudio <3261958605@qq.com>
 * Created: 2017-07-21 13:42:33
 * Commentary: 测试文件
 ***************************************************************/
#include "Strings.h"
#include <stdio.h>

void print(String str) { printf("%s\n", str); }

int main(void) {
  Strings strings = stringsInit();

  strings = stringsInsert(strings, 0, "hello");

  strings = stringsInsert(strings, 110, "world");

  strings = stringsAppend(strings, "my");
  strings = stringsAppend(strings, "name");
  strings = stringsAppendLeft(strings, "Clang");

  strings = stringsRemove(strings, 0);
  strings = stringsRemove(strings, 1000);
  strings = stringsAppend(strings, "name");

  strings = stringsPop(strings);
  strings = stringsPopLeft(strings);
  strings = stringsAppendLeft(strings, "hello");
  strings = stringsAppend(strings, "name");

  Strings s2 = stringsInit();
  s2 = stringsAppend(s2, "is");
  s2 = stringsAppend(s2, "claudio");
  printf("s2:\n");
  stringsPrint(s2);

  strings = stringsExtend(strings, s2);
  printf("strings:\n");
  stringsPrint(strings);
  s2 = stringsExtend(s2, strings);
  printf("s2:\n");
  stringsPrint(s2);

  printf("========================\n");

  Strings s3 = stringsCopy(s2);
  printf("s3:\n");
  stringsPrint(s3);
  printf("========================\n");
  printf("claudio 在s3的索引为：%d\n", stringsFind(s3, "claudio"));
  printf("Claudio 在s2的索引为：%d\n", stringsFind(s2, "Claudio"));

  printf("s2中第3个元素为：%s\n", stringsGet(s2, 2));
  printf("s2中第-1个元素为：%s\n", stringsGet(s2, -1));
  printf("s2中第100个元素为：%s\n", stringsGet(s2, 100));

  printf("stringsMap(s3, print)结果:\n");
  stringsMap(s3, print);

  stringsClear(strings);
  stringsClear(s2);
  stringsClear(s3);
  return 0;
}
