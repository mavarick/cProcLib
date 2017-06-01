/***************************************************************************
*
* Copyright (c) 2017 Baidu.com, Inc. All Rights Reserved
* B142877
*
**************************************************************************/
/**
* @file time_lib.h.h
* @author liuxufeng (liuxufeng@baidu.com)
* @date 2017/06/01 14:14:27
* @version 1.0.0-alpha 
* @brief
*      make a desription
**/

#include <ctime>
#include <string>

#ifndef CPROCLIB_TIME_LIB_H_H
#define CPROCLIB_TIME_LIB_H_H

using namespace std;

time_t StringToDatetime(string str);
string DatetimeToString(time_t time);

time_t str2ts(string str, const string format);
string ts2str(time_t tm_, const string format);

#endif //CPROCLIB_TIME_LIB_H_H
