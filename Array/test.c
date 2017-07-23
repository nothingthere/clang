/**************************************************************
 * test.c
 * Author: Claudio <3261958605@qq.com>
 * Created: 2017-07-22 18:32:01
 * Commentary:
 ***************************************************************/

#include "Array.h"
#include "Constants.h"
#include "Generic.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  ArrayPtr aptr = arrayInit(STRING);
  assert(is_zero(arrayLen(aptr)));

  Elem hello;
  hello.sval = "hello";
  Elem world;
  world.sval = "world";

  printf("insert添加2个元素后：\n");
  arrayInsert(aptr, 0, hello);
  arrayInsert(aptr, 1000, world);

  arrayPrint(aptr);

  printf("remove删除第2个元素后，数组为：\n");
  arrayRemove(aptr, 1);
  arrayPrint(aptr);

  printf("Append再添加回去后：\n");
  arrayAppend(aptr, world);
  arrayPrint(aptr);

  printf("pop元素后：\n");
  arrayPop(aptr);
  arrayPrint(aptr);

  printf("popleft元素后：\n");
  arrayPopLeft(aptr);
  arrayPrint(aptr);

  printf("Append添加回原来两个元素后：\n");
  arrayAppend(aptr, hello);
  arrayAppend(aptr, world);
  arrayPrint(aptr);

  printf("=======================\n");
  Elem name;
  name.sval = "claudio";
  Elem gender;
  gender.sval = "male";
  ArrayPtr aptr2 = arrayInit(STRING);
  arrayAppend(aptr2, name);
  arrayAppend(aptr2, gender);
  printf("创建的第二个数组为：\n");
  arrayPrint(aptr2);

  printf("=======================\n");
  printf("第一个数组Extend第二个数组后：\n");
  arrayExtend(aptr, aptr2, STRING);
  arrayPrint(aptr);
  arrayRemove(aptr2, 100);
  printf("删除第二个数组中的元素后，第一个数组为：\n");
  arrayPrint(aptr);
  printf("第二个素组为：\n");
  arrayPrint(aptr2);

  printf("=======================\n");
  printf("使用copy复制第一个素组得到的第三个数组为：\n");
  ArrayPtr aptr3 = arrayCopy(aptr, STRING);
  arrayPrint(aptr3);
  printf("删除第三个数组中的第一个元素元素后，第一个和第三个素组分别为：\n");
  arrayPopLeft(aptr3);
  arrayPrint(aptr);
  arrayPrint(aptr3);

  /* printf("=======================\n"); */
  /* printf("使用shallowCopy复制第一个素组得到的第4个数组为：\n"); */
  /* ArrayPtr aptr4 = arrayShallowCopy(aptr, STRING); */

  /* arrayPrint(aptr4); */
  /* printf("删除第4个数组中的第一个元素元素后，第一个和第4个素组分别为：\n");
   */
  /* arrayPopLeft(aptr4); */
  /* arrayAppend(aptr4, hello); */
  /* arrayPrint(aptr); */
  /* arrayPrint(aptr4); */

  printf("=======================\n");
  printf("\"hello\" 在第一个数组中的索引为：%d\n", arrayFind(aptr, hello));
  Elem foo;
  foo.sval = "bar";

  printf("\"not-exists\"在第一个数组中的索引为：%d\n", arrayFind(aptr, foo));

  printf("=======================\n");
  printf("获取第一个数组中第1个元素为：\n");

  /* Elem *item = (Elem *)malloc(sizeof(Elem)); */
  Elem *item = arrayGet(aptr, 0);

  assert(is_string_equal(item->sval, hello.sval)));

  assert(is_null(arrayGet(aptr, 1000)));

  arrayClear(aptr);
  arrayClear(aptr2);
  arrayClear(aptr3);

  printf("！！！测试通过！！！\n");
  return 0;
}
