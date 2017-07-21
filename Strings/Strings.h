/**************************************************************
 * Strings.h
 * Author: Claudio <3261958605@qq.com>
 * Created: 2017-07-21 13:41:43
 * Commentary: Strings.c头文件
 ***************************************************************/
typedef char *String;
typedef char **Strings;

#include <stddef.h>

Strings stringsInit(void);
size_t stringsLen(Strings strings);
void stringsClear(Strings strings);

Strings stringsInsert(Strings strings, int i, String str);
Strings stringsAppend(Strings strings, String str);
Strings stringsAppendLeft(Strings strings, String str);

Strings stringsRemove(Strings strings, int i);
Strings stringsPop(Strings strings);
Strings stringsPopLeft(Strings strings);

Strings stringsExtend(Strings dest, Strings src);
Strings stringsCopy(Strings strings);

int stringsFind(Strings strings, String str);
String stringsGet(Strings Strings, int i);

String stringsJoin(Strings Strings, String str);

void stringsPrint(Strings strings);
