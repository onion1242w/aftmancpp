#include "GithubContent/GHFinder.hpp"
#include "GithubContent/GHInstaller.hpp"

#include "JsonF/JSFileGet.hpp"

#include "ZipPP/ZZ.hpp"

#include <CLI/CLI.hpp>
#include <fstream>

int main(int argc, char* argv[]) {
    //std::cout << std::filesystem::current_path();
    //ZipP::UnZip("aftman-0.3.0-windows-x86_64(1).zip", "");

    CLI::App CApp{"Copy of aftman lol"};
    argv = CApp.ensure_utf8(argv);

    std::string ToRemove;
    std::string ToInstall;

    auto InstallAll = CApp.add_subcommand("InstallAll", "Install every package on dirjs.json");
    auto Remove = CApp.add_subcommand("Remove", "Remove Package");
    auto Install = CApp.add_subcommand("Install", "Install an app.");

    Remove->add_option("PCKG", ToRemove, "Package to remove.")
          ->required();

    Remove->callback([&]() {

    });

    InstallAll->callback([&]() {
        nlohmann::json Packages = JSGET::GetCurrentApps();
        for (const auto &i : Packages.items()) {
            auto *K = &i.key();
            auto *V = &i.value();


        };
        
    });

    Install->add_option("PCKG", ToInstall, "Package to install.")
           ->required();
    
    Install->callback([&]() {

    });

    CLI11_PARSE(CApp, argc, argv);

    if (argc == 1) {
        std::cout << CApp.help() << std::endl;
    }

    return 1;
}
