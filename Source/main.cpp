#include "GithubContent/GHFinder.hpp"
#include "GithubContent/GHInstaller.hpp"

#include "JsonF/JSFileGet.hpp"

#include "ZipPP/ZZ.hpp"

#include <cpr/cpr.h>
#include <CLI/CLI.hpp>
#include <fstream>
#include <print>

int main(int argc, char* argv[]) {
    //std::cout << std::filesystem::current_path();
    //ZipP::UnZip("aftman-0.3.0-windows-x86_64(1).zip", "");

    CLI::App CApp{"Copy of aftman lol"};
    argv = CApp.ensure_utf8(argv);

    std::string ToRemove;
    std::string ToInstall;

    auto InstallAll = CApp.add_subcommand("InstallAll", "Install every package on dirjs.json");
    auto Remove = CApp.add_subcommand("Remove", "Remove Package");
    auto Install = CApp.add_subcommand("Install", "Install Package.");

    Remove->add_option("PCKG", ToRemove, "Package to remove.")
          ->required();

    Remove->callback([&]() {

    });

    InstallAll->callback([&]() {
        nlohmann::json Packages = JSGET::GetCurrentApps(); // Tools
        for (const auto &i : Packages.items()) {
            auto *K = &i.key(); // Tool
            auto *V = &i.value(); // Version

        };
        
    });

    Install->add_option("PCKG", ToInstall, "Package to install.")
           ->required();
    
    Install->callback([&]() {

    });

    CLI11_PARSE(CApp, argc, argv);

    if (argc == 1) {
        std::print("{}", CApp.help());
    }

    return 1;
}
