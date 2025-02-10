#pragma once

#include <cpr/cpr.h>
#include <fstream>
#include <filesystem>
#include <iostream>

enum CBools {
    GHIsFine,
    GHNotFine
};

class GHMain {
private:
    cpr::Session GHSession;

    std::string TarDownUrl;
    std::ofstream TarDownFile;
public:
    GHMain();

    CBools FindFileFromUrl();
};