cmake_minimum_required(VERSION 3.16)

project(CameraApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

file(GLOB TEMPLATES_MODULE_SRCS
     "SRCS/*.c"
     "SRCS/*.cpp"
     "SRCS/*.h"
     "SRCS/*.hpp"
)

qt_add_library(TemplatesModule STATIC
    ${TEMPLATES_MODULE_SRCS}
)

target_include_directories(TemplatesModule PUBLIC SRCS)

target_link_libraries(TemplatesModule
    PRIVATE Qt6::Quick
)
