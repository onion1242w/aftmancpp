#include "JSFileGet.hpp"

#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>

nlohmann::json JSGET::GetCurrentApps() {
    std::ifstream TARF(std::filesystem::current_path().string() + "/" + "dirjs.json");
    nlohmann::json CurJS;

    if (!TARF.is_open()) {
        std::cout << "dirjs.json not found\n";
        return nlohmann::json();
    }

    try {
        TARF >> CurJS;
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
        return nlohmann::json();
    }

    TARF.close();

    if (!CurJS.contains("Tools")) {
        std::cout << "Tools doesnt exist.\n";
        return nlohmann::json();
    }

    return CurJS["Tools"];
}