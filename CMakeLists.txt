cmake_minimum_required(VERSION 3.0.0)
project(swiftkeydb VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()
include_directories(include)
add_executable(swiftkeydb src/main.cpp src/List.cpp src/Database.cpp src/DatabaseManager.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
