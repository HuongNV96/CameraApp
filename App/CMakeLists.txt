cmake_minimum_required(VERSION 3.16)

project(CameraApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(CameraApp
    main.cpp
)

qt_add_qml_module(CameraApp
    URI App
    VERSION 1.0
    QML_FILES QML/Main.qml QML/LoginForm.qml
)

set_target_properties(CameraApp PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER camera.app.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(CameraApp
    PRIVATE Qt6::Quick EngineCamera
)

install(TARGETS CameraApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})