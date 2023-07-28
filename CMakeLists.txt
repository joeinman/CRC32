cmake_minimum_required(VERSION 3.27.0)

project(CRC32 VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

# Add An Option To Build The Examples
option(BUILD_EXAMPLES "Build The Examples" ON)

add_library(CRC32 STATIC)

target_sources(CRC32 PRIVATE
    "src/CRC32.cpp"
)

target_include_directories(CRC32 PUBLIC
    "include"
)

# Build Examples If Enabled
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
