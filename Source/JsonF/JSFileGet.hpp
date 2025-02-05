#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include <nlohmann/json.hpp>

namespace JSGET {
   nlohmann::json GetCurrentApps(); 
}
