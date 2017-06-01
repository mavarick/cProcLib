/***************************************************************************
*
* Copyright (c) 2017 Baidu.com, Inc. All Rights Reserved
* B142877
*
**************************************************************************/
/**
* @file test_time.cpp
* @author liuxufeng (liuxufeng@baidu.com)
* @date 2017/06/01 14:15:40
* @version 1.0.0-alpha 
* @brief
*      make a desription
 *
 *
**/

#include <iostream>
#include "time_lib.h"


//#ifndef _TM_DEFINED
//struct tm {
//    int tm_sec;     /* seconds after the minute - [0,59] */
//    int tm_min;     /* minutes after the hour - [0,59] */
//    int tm_hour;    /* hours since midnight - [0,23] */
//    int tm_mday;    /* day of the month - [1,31] */
//    int tm_mon;     /* months since January - [0,11] */
//    int tm_year;    /* years since 1900 */
//    int tm_wday;    /* days since Sunday - [0,6] */
//    int tm_yday;    /* days since January 1 - [0,365] */
//    int tm_isdst;   /* daylight savings time flag */
//};
//#define _TM_DEFINED
//#endif


using namespace std;

int main(int argc, char * argv []){
    string timeStr = "2017-05-27 19:50:02";
    cout << "timestr: " << timeStr << endl;

    struct tm _tm;
    strptime(timeStr.data(), "%Y-%m-%d %H:%M:%S", &_tm);
    cout << _tm.tm_year + 1900 << endl;

    time_t t_ = mktime(&_tm);
    cout << t_ << endl;
    cout << localtime(&t_) << endl;

    string format = "%Y-%m-%d %H:%M:%S";
    time_t t1 = str2ts(timeStr, format);
    cout << "str2ts: " << t1 << endl;

    string t2 = ts2str(t1, format);
    cout << "ts2str: " << t2 << endl;

    string t3 = ts2str(t1, "%Y-%m-%d");
    cout << "ts2str: " << t3 << endl;

    return 0;
}
