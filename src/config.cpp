#include "config.h"
#include <iostream>
#include <fstream.h>

Config::Config()
{
    _file_name = "";
    _class_name = "";
    _base_class_name = "";
}

Config::~Config()
{

}

bool Config::Read(const std::string& file_path)
{
    ifstream fs(file_path.c_str());
    if (!fs.is_open())
    {
        std::cout << "Reaf file error : " << file_path << std::endl;
        return false;
    }

    char buffer[1024];
    std::string input = "";
    std::string key = "";
    std::string value = "";
    while (!fs.eof())
    {
        fs.getline(buffer, 1024);
        input = buffer;
        if (input == "")
        {
            continue;
        }

        if (!Split(input, key, value))
        {
            std::cout << "Error split string : " << input << std::endl;
        }

        if (key == "file_name")
        {
            _file_name = value;
        }
        else if (key == "class_name")
        {
            _class_name = value;
        }
        else if (key == "base_class_name")
        {
            _base_class_name = value;
        }
        else if (key == "author")
        {
            _author = value;
        }
        else if (key == "date")
        {
            _date = value;
        }
        else if (key == "version")
        {
            _version = value;
        }
        else if (key == "description")
        {
            _description = value;
        }
        else
        {
            std::cout << "Error key name : " << key << std::endl;
        }
    }
    
    fs.close();
    return true;
}

bool Config::Split(const std::string& input, std::string& fst, std::string& snd)
{
    size_t index = input.find(":");
    if (std::string::npos == index)
    {
        return false;
    }

    fst = input.substr(0, index);
    snd = input.substr(index + 1);
    return true;
}

std::string Config::GetFileName()
{
    return _file_name;
}

std::string Config::GetClassName()
{
    return _class_name;
}

std::string Config::GetBaseClassName()
{
    return _base_class_name;
}

std::string Config::GetAuthor()
{
    return _author;
}

std::string Config::GetDate()
{
    return _date;
}

std::string Config::GetVersion()
{
    return _version;
}

std::string Config::GetDescription()
{
    return _description;
}
