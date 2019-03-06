cmake_minimum_required(VERSION 3.13)
project(PROI1)

set(CMAKE_CXX_STANDARD 14)

find_package(PkgConfig)
find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(CURL REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0)

link_directories( ${GTKMM_LIBRARY_DIRS} )
include_directories( ${GTKMM_INCLUDE_DIRS} )

link_directories(${CURL_LIBRARY_DIRS})
include_directories(${CURL_INCLUDE_DIRS})
add_executable(PROI1 src/main.cpp src/MainWindow.cpp include/MainWindow.h)

target_link_libraries(PROI1 ${GTKMM_LIBRARIES} ${CURL_LIBRARIES} nlohmann_json::nlohmann_json )