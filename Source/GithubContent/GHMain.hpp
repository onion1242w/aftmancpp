#pragma once

#include <cpr/cpr.h>
#include <fstream>
#include <iostream>
#include <filesystem>

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
