/***************************************************************************
*
* Copyright (c) 2017 Baidu.com, Inc. All Rights Reserved
* B142877
*
**************************************************************************/
/**
* @file char_lib.cpp
* @author liuxufeng (liuxufeng@baidu.com)
* @date 2017/05/27 19:42:18
* @version 1.0.0-alpha 
* @brief
*      make a desription
**/

#include <iostream>
#include <vector>

//using namespace std;

namespace char_lib {

    std::string rstrip_str(std::string ori_str, const char ch){
        int idx = ori_str.length() - 1;
        for(;idx >= 0 ; idx--){
            if(ori_str[idx] != ch){
                break;
            }
        }
        return ori_str.substr(0, idx + 1);
    }

    std::string lstrip_str(std::string ori_str, char ch){
        int size = ori_str.size();
        int idx = 0;
        for(; idx < size; idx++){
            if (ori_str[idx] != ch){
                break;
            }
        }
        return ori_str.substr(idx, size + 1);
    }

    std::string strip_str(std::string ori_str, char ch){
        return lstrip_str(rstrip_str(ori_str, ch), ch);
    }

    std::string replace_str(std::string ori_str, const std::string sub,
                              const std::string rep, bool replace_all=true){
        // replace substring of `ori_str` from `sub` to `rep`
        std::string new_string = ori_str;
        std::string::size_type pos = 0;
        std::string::size_type sub_size = sub.size();
        std::string::size_type rep_size = rep.size();
        while((pos = new_string.find(sub, pos)) != std::string::npos){
            new_string.replace(pos, sub_size, rep);
            pos += rep_size;
            if(!replace_all){
                break;
            }
        }
        return new_string;
    }

    int split_str(std::string src, std::string seps, std::vector<std::string>& dest){
        // 用多个字符来分割字符串，填入分割后的字符串的vector向量，返回vector向量的长度
        std::string::size_type pos;
        src += seps;
        int size = src.size();
        for(int i = 0; i < size; i++){
            pos = src.find(seps, i);
            if (pos < size){
                std::string s = src.substr(i, pos - i);
                dest.push_back(s);
                i = pos + seps.size() - 1;
            }
        }
        return dest.size();
    }

    int edit_dist(const char * A, const char * B) {
        // 计算字符的编辑距离
        int dis[256];
        int m = strlen(A);
        int n = strlen(B);
        for (int i = 0; i <= n; ++i) {
            dis[i] = i;
        }
        int cost = 0;
        for (int i = 1; i <= m; ++i)
        {
            int y = i - 1;
            for (int j = 1; j <= n; ++j)
            {
                int x = y;
                y = dis[j];
                int z = j > 1 ? dis[j-1] : i;
                cost = (A[i-1] == B[j-1]) ? 0 : 1;
                int tmp = x + cost < y + 1 ? x + cost : y + 1;
                dis[j] = tmp < z + 1 ? tmp : z + 1;
            }
        }
        return dis[n];
    }

//使用字符串编辑距离计算字符串相似度
    float string_edit_sim(const char * string1, const char * string2) {
        int dist = edit_dist(string1, string2);
        int len1 = strlen(string1);
        int len2 = strlen(string2);
        int len_max = len1 > len2 ? len1 : len2;
        if (len_max > 0) {
            return float(len_max - dist) / len_max;
        }
        else {
            return 1.0f;
        }
    }

}




