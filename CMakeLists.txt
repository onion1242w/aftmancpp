cmake_minimum_required(VERSION 3.5.0)
project(cman VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE GSOURCES "Source/GithubContent/*.cpp" "Source/GithubContent/*.hpp")
file(GLOB_RECURSE JSOURCES "Source/JsonF/*.cpp" "Source/JsonF/*.hpp")
file(GLOB_RECURSE ZSOURCES "Source/ZipPP/*.cpp" "Source/ZipPP/*.hpp")

add_library( 
    GContent STATIC
    ${GSOURCES}
)

add_library( 
    JsonF STATIC
    ${JSOURCES}
)

add_library( 
    ZipPP STATIC
    ${ZSOURCES}
)

add_executable(cman Source/main.cpp)

find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)
find_package(ZLIB REQUIRED)
find_package(miniz CONFIG REQUIRED)

target_link_libraries(ZipPP PRIVATE nlohmann_json::nlohmann_json miniz::miniz)
target_link_libraries(GContent PRIVATE cpr::cpr nlohmann_json::nlohmann_json)
target_link_libraries(JsonF PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(cman PRIVATE JsonF GContent ZipPP cpr::cpr nlohmann_json::nlohmann_json CLI11::CLI11 miniz::miniz)