cmake_minimum_required(VERSION 3.16)

project(CameraApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

add_library(opencv_world3416 STATIC IMPORTED)
set_property(TARGET opencv_world3416 PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/opencv4/libs/opencv_world3416.lib)

add_library(opencv_world3416d STATIC IMPORTED)
set_property(TARGET opencv_world3416d PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/opencv4/libs/opencv_world3416d.lib)

file(GLOB ENGINE_SRCS
    "SRCS/*.c"
    "SRCS/*.cpp"
    "SRCS/*.h"
    "SRCS/*.hpp"
)

qt_add_library(EngineCamera STATIC ${ENGINE_SRCS})

target_link_libraries(EngineCamera PRIVATE
    TemplatesModule
    Qt6::Quick
    opencv_world3416 opencv_world3416d
)
target_include_directories(EngineCamera PUBLIC SRCS ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/opencv4/headers)
