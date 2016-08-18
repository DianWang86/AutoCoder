/********************************************************
 * Author: wangdian
 * Time: 2016-07-18
 * Version: 0.1
 * Description: 
 * *****************************************************/

#include <iostream>
#include <string>
#include "smart_coder.h"

int main(int argc, char** argv)
{
    if (3 != argc)
    {
        std::cout << "Error argc" << argc << std::endl;
        return 0;
    }

    std::string conf_path = argv[1];
    std::string file_path = argv[2];
    SmartCoder coder;
    if (!coder.Run(conf_path, file_path))
    {
        std::cout << "Failed!" << std::endl;
    }
    
    return 1;
}
