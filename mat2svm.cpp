/***************************************************************************
*
* Copyright (c) 2017, Inc. All Rights Reserved
*
**************************************************************************/
/**
* @file dfile_lib.cpp
* @author liuxufeng (liuxufeng@baidu.com)
* @date 2017/05/27 21:01:11
* @version 1.0.0-alpha 
* @brief
*      提供基于文件类的数据处理，例如svm格式转换，或者按列分析等
**/

#include <iostream>
#include <fstream>
#include <vector>

int split_str(std::string src, std::string seps, std::vector<std::string>& dest);

int mat2svm(std::string filename, std::string outfile="",
            const bool header=false,
            std::string sep="\t",
            std::string out_sep="\t",
            std::string filter="0"){
    // ignore header if header exists
    std::ifstream fin(filename);
    if (fin.fail()){
        std::cout << "Fail to open file: " << filename << std::endl;
        return -1;
    }

    if (fin.fail()){
        std::cout << "Fail to create output file: " << outfile << std::endl;
    }

    if (outfile == ""){
        outfile = filename;
        outfile.append(".svm");
        std::cout << "WARN: svm outfile is not set, and use default: " << outfile << std::endl;
    }

    std::ofstream fout(outfile);

    std::string line;
    std::vector<std::string> items;
    int col_num = 0;
    float * data;

    int total_size = 0;
    while(!fin.eof()){
        items.clear();
        std::getline(fin, line);
//        std::cout << line << std::endl;
        split_str(line, sep, items);
        col_num = items.size();

        fout << items[0];
        for(int i=1; i<col_num; i++){
            fout << out_sep;
            fout << i << ":" << items[i];
        }
        fout << std::endl;
        total_size += 1;
    }
    fin.close();
    fout.close();

    std::cout << "total lines: " << total_size << std::endl;
    return 0;
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

int main(int argc, char * argv []){
    if (argc < 2){
        std::cout << "usage: ./mat2svm mat_file svm_file" << std::endl;
        return -1;
    }
    std::string filename = argv[1];
    std::string outfile;
    if(argc == 2){
        outfile = "";
    }else{
        outfile = argv[2];
    }

    std::string filename = "";
    std::string outfile = "";
    std::string sep = "\t";
    std::string sep_out = "\t";

    int idx = 1;
    std::string key;
    std::string val;
    while (idx < argc){
        key = argv[idx];
        if (key[0] == '-' && idx < argc + 1 && argv[idx+1][0] != '-'){
            key = lstrip_str(key, '-');
            val = argv[++idx];
        }
        switch(key[0]) {
            case 'i':
                filename = val;
                break;
            case 'o':
                outfile = val;
                break;
            case 's':
                sep = val;
            case 'd':
                sep_out = val;
        }




        }

        idx ++;
    }

    std::cout << "input: " << filename.c_str() << std::endl;
    std::cout << "output: " << outfile.c_str() << std::endl;
    int ret = mat2svm(filename, outfile);

    return 0;
}


