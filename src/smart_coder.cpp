#include "smart_coder.h"

SmartCoder::SmartCoder()
{

}

SmartCoder::~SmartCoder()
{

}

bool SmartCoder::ReadConf(const std::string& file_path)
{
    return _config.Read(file_path);
}

bool SmartCoder::WriteRes(const std::string& file_path)
{
    if (_head_writer.good())
    {
        _head_writer.close();
    }
    std::string input_path = file_path + _config.GetFileName();
    input_path += ".h";
    _head_writer.open(input_path.c_str(), std::ios::out);
    if (!_head_writer.good())
    {
        //std::cout << "open the input file failed : " << input_path << std::endl;
        //return false;
    }
    WriteHeadFile();
    _head_writer.close();
    
    if (_cpp_writer.good())
    {
        _cpp_writer.close();
    }

    std::string output_path = file_path + _config.GetFileName();
    output_path += ".cpp";
    _cpp_writer.open(output_path.c_str(), std::ios::out);
    if (!_cpp_writer.good())
    {
        //std::cout << "open the input file failed : " << output_path << std::endl;
        //return false;
    }
    WriteCppFile();
    _cpp_writer.close();

    return true;
}

void SmartCoder::WriteHeadFile()
{
    WriteNote();
    WritePres();
}

void SmartCoder::WriteNote()
{
    _head_writer << "/****************************************" << std::endl;
    _head_writer << " * Author: " << _config.GetAuthor() << std::endl;
    _head_writer << " * Date: " << _config.GetDate() << std::endl;
    _head_writer << " * Version: " << _config.GetVersion() << std::endl;
    _head_writer << " * Description: " << _config.GetDescription() << std::endl;
    _head_writer << "****************************************/" << std::endl;
}

void SmartCoder::WriteClass()
{
    if (_config.GetBaseClassName() == "")
    {
        _head_writer << "class " << _config.GetClassName() << std::endl;
    }
    else
    {
        _head_writer << "class " << _config.GetClassName() << " : public" << _config.GetBaseClassName() << std::endl;
    }

    _head_writer << "{" << std::endl;
    _head_writer << "    public:" << std::endl;
    _head_writer << "        " << _config.GetClassName() << "();"<< std::endl;
    _head_writer << "        virtual ~" << _config.GetClassName() << "();"<< std::endl;
    _head_writer << "};" << std::endl;
}

void SmartCoder::WritePres()
{
    _head_writer << "#ifndef _def_" << _config.GetFileName() << "_h_" << std::endl;
    _head_writer << "#define _def_" << _config.GetFileName() << "_h_" << std::endl;
    _head_writer << std::endl;
    _head_writer << std::endl;
    WriteClass(); 
    _head_writer << std::endl;
    _head_writer << "#endif" << std::endl;
}

void SmartCoder::WriteCppFile()
{
    _cpp_writer << "#include \"" << _config.GetFileName() << ".h\"" << std::endl;
    _cpp_writer << std::endl;
    _cpp_writer << std::endl;
    Constructor();
    _cpp_writer << std::endl;
    Destructor();
    _cpp_writer << std::endl;
}

void SmartCoder::Destructor()
{
    _cpp_writer << _config.GetClassName() << "::~" << _config.GetClassName() << "()"<< std::endl;
    _cpp_writer << "{" << std::endl;
    _cpp_writer << std::endl;
    _cpp_writer << "}" << std::endl;
}

void SmartCoder::Constructor()
{
    _cpp_writer << _config.GetClassName() << "::" << _config.GetClassName() << "()"<< std::endl;
    _cpp_writer << "{" << std::endl;
    _cpp_writer << std::endl;
    _cpp_writer << "}" << std::endl;
}

bool SmartCoder::Run(const std::string& conf_file, const std::string& res_file)
{
    if (!ReadConf(conf_file))
    {
        return false;
    }

    return WriteRes(res_file);
}
