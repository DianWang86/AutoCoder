/********************************************************
 * Author: wangdian
 * Time: 2016-07-18
 * Version: 0.1
 * Description: 
 * *****************************************************/

#ifndef _DEF_SMART_CODER_H_
#define _DEF_SMART_CODER_H_
#include <string>
#include <iostream>
#include <fstream.h>
#include "config.h"

class SmartCoder
{
    public:
        SmartCoder();
        ~SmartCoder();

    public:
        bool Run(const std::string& conf_file, const std::string& file_path);

    private:
        bool ReadConf(const std::string& file_path);
        bool WriteRes(const std::string& file_path);
        void WriteHeadFile();
        void WriteNote();
        void WriteClass();
        void WritePres();
        void WriteCppFile();
        void Constructor();
        void Destructor();

    private:
        ofstream _head_writer;
        ofstream _cpp_writer;
        Config _config;
};

#endif
