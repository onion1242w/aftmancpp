#include "ZZ.hpp"

Result<ZZ> ZZ::init(std::string ZipFilePath) noexcept {
    ZZ Cur;

    if (!mz_zip_reader_init_file(&Cur.zARCH, ZipFilePath.c_str(), 0)) {
        return std::unexpected("Failed to open zip.");
    }

    Cur.NumF = (int)mz_zip_reader_get_num_files(&Cur.zARCH);

    return Cur;
}

Result<bool> ZZ::Unzip() {
    for (int i = 0; i < this->NumF; i++) {
        if (!mz_zip_reader_file_stat(&this->zARCH, i, &this->FStat)) {
            return std::unexpected("Cant read file stat.");
        }

        std::filesystem::path file_out(FStat.m_filename);

        if (!mz_zip_reader_extract_to_file(&this->zARCH, i, file_out.filename().string().c_str(), 0)) {
            mz_zip_reader_end(&this->zARCH);
            return std::unexpected("Cant extract to file.");
        }
    }

    mz_zip_reader_end(&this->zARCH);

    return true;
}