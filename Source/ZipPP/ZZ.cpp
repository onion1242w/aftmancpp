#include "ZZ.hpp"

int ZipP::UnZip(std::string ZipFilePath, std::string TarFolderPath) {
    mz_zip_archive zARCH;
    memset(&zARCH, 0, sizeof(zARCH));

    if (!mz_zip_reader_init_file(&zARCH, ZipFilePath.c_str(), 0)) {
        std::cout << "Failed to open zip file.\n";
        return -1;
    }

    int NumF = (int)mz_zip_reader_get_num_files(&zARCH);

    mz_zip_archive_file_stat FStat;

    for (int i = 0; i < NumF; i++) {
        if (!mz_zip_reader_file_stat(&zARCH, i, &FStat)) {
            std::cout << "Failed to get file stat.\n";
            return -1;
        }

        if (mz_zip_reader_is_file_a_directory(&zARCH, i)) {
            std::filesystem::path dir(TarFolderPath + FStat.m_filename);
            std::filesystem::create_directories(dir.parent_path());
            continue;
        }

        std::filesystem::path file_out(FStat.m_filename);

        std::cout << file_out << std::endl;

        if (!mz_zip_reader_extract_to_file(&zARCH, i, file_out.filename().string().c_str(), 0)) {
            mz_zip_reader_end(&zARCH);
            return -1;
        }
    }
    
    if (!mz_zip_reader_end(&zARCH)) {
        return -1;
    }

    return 1;
}