/**************************************************************
 * Constants.h
 * Author: Claudio <3261958605@qq.com>
 * Created: 2017-07-24 00:09:55
 * Commentary: 常用常量 模板函数
 ***************************************************************/
#ifndef CONSTANTS_H
#define CONSTANTS_H

#define SUCCESS 1
#define FAIL 0
#define NOT_FOUND -1

#define is_null(x) (NULL == (x))
#define is_zero(x) (0 == (x))
#define is_string_equal(x, y) (is_zero(strcmp((x), (y)))

#endif
