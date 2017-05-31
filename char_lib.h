/***************************************************************************
*
* Copyright (c) 2017 Baidu.com, Inc. All Rights Reserved
* B142877
*
**************************************************************************/
/**
* @file char_lib.h
* @author liuxufeng (liuxufeng@baidu.com)
* @date 2017/05/27 20:09:03
* @version 1.0.0-alpha 
* @brief
*      make a desription
**/

#ifndef CPROCLIB_CHAR_LIB_H
#define CPROCLIB_CHAR_LIB_H

namespace char_lib{
    std::string rstrip_str(std::string ori_str, const char ch);
    std::string lstrip_str(std::string ori_str, char ch);
    std::string strip_str(std::string ori_str, char ch);
    std::string replace_str(std::string ori_str, const std::string sub,
                              const std::string rep, bool replace_all=true);
    int split_str(std::string src, std::string seps, std::vector<std::string>& dest);

    // 计算字符之间的编辑距离
    int edit_dist(const char * A, const char * B);
    // 根据编辑距离计算字符串之间的相似度
    float string_edit_sim(const char * string1, const char * string2);
}


#endif //CPROCLIB_CHAR_LIB_H
