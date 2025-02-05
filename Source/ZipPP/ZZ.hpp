#pragma once

#include <iostream>
#include <fstream>
#include <miniz/miniz.h>
#include <filesystem>

namespace ZipP {
    int UnZip(std::string ZipFilePath, std::string TarFolderPath);
}