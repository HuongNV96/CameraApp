cmake_minimum_required(VERSION 3.16)

project(CameraApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

file(GLOB ENGINE_SRCS
     "SRCS/*.c"
     "SRCS/*.cpp"
)

qt_add_library(EngineCamera ${ENGINE_SRCS})
target_include_directories(EngineCamera PUBLIC SRCS)

