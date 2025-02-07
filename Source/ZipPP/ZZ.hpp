#pragma once

#include <iostream>
#include <expected>
#include <fstream>
#include <miniz/miniz.h>
#include <filesystem>

template<typename T>
using Result = std::expected<T, std::string_view>;

class ZZ {
private:
    mz_zip_archive zARCH{};
    mz_zip_archive_file_stat FStat;

    int NumF;
public:
    static Result<ZZ> init(std::string ZipFilePath) noexcept;
    Result<bool> Unzip();
};

