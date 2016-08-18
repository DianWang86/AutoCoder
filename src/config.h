/********************************************************
 * Author: wangdian
 * Time: 2016-07-18
 * Version: 0.1
 * Description: 
 * *****************************************************/

#ifndef _DEF_CONFIG_H_
#define _DEF_CONFIG_H_
#include <string>

class Config
{
    public:
        Config();
        ~Config();

    public:
        bool Read(const std::string& file_path);

    public:
        std::string GetFileName();
        std::string GetClassName();
        std::string GetBaseClassName();
        std::string GetAuthor();
        std::string GetDate();
        std::string GetVersion();
        std::string GetDescription();

    private:
        bool Split(const std::string& input, std::string& fst, std::string& snd);
    
    private:
        std::string _file_name;
        std::string _class_name;
        std::string _base_class_name;
        std::string _author;
        std::string _date;
        std::string _version;
        std::string _description;
};

#endif
