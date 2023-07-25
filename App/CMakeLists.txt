cmake_minimum_required(VERSION 3.16)

project(CameraApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Multimedia)

qt_standard_project_setup()

file(GLOB APP_SRCS
     "SRCS/*.c"
     "SRCS/*.cpp"
     "SRCS/*.h"
     "SRCS/*.hpp"
)

qt_add_executable(CameraApp
    resource.qrc
    ${APP_SRCS}
)

set_target_properties(CameraApp PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER camera.app.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(CameraApp
    PRIVATE Qt6::Quick Qt6::Multimedia EngineCamera ExtraModule TemplatesModule
)

install(TARGETS CameraApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
