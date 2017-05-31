/***************************************************************************
*
* Copyright (c) 2017 Baidu.com, Inc. All Rights Reserved
* B142877
*
**************************************************************************/
/**
* @file datafile_lib.h
* @author liuxufeng (liuxufeng@baidu.com)
* @date 2017/05/31 13:09:41
* @version 1.0.0-alpha 
* @brief
*      提供基于文件类的数据处理，例如svm格式转换，或者按列分析等
**/

#ifndef CPROCLIB_DATAFILE_LIB_H
#define CPROCLIB_DATAFILE_LIB_H

namespace datafile_lib {
    // translate matrix file to svm file
    int maxtrix2svm(std::string filename, std::string outfile, const bool header=False);

    int svm_scale(std::string svmfile, std::string outfile, std::string para_file){
        throw "use libsvm's svm_scale";
    }

}

#endif //CPROCLIB_DATAFILE_LIB_H
