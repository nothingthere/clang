/**************************************************************
 * Generic.h
 * Author: Claudio <3261958605@qq.com>
 * Created: 2017-07-23 14:22:10
 * Commentary: 利用_Generic宏处理不同类型
 * 参考地址：http://www.robertgamble.net/2012/01/c11-generic-selections.html
 ***************************************************************/
#ifndef GENERIC_H
#define GENERIC_H

enum _typename { INT, FLOAT, DOUBLE, STRING };
#define typeof(x) _Generic((x), int : INT, float : FLOAT, double : DOUBLE,     \
                            char * : STRING)

#define printf_dec_format(x)                                                   \
  _Generic((x), int : "%d", float : "%f", double : "%f", char * : "%s")

#define print(x) printf(printf_dec_format(x), x)
#define println(x) printf(printf_dec_format(x), x), printf("\n")

#endif
