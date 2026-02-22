cmake_minimum_required (VERSION 3.31)

include($ENV{ARIEO_BUILD_ENV_PACKAGES_OUTPUT_DIR}/cmake/build_environment.cmake)

ARIEO_PACKAGE(
    Arieo-Module-ModelLoader
    CATEGORY 02_engine
    DEPENDS
        https://github.com/BigElderK/Arieo-Core.git@main
        https://github.com/BigElderK/Arieo-Interface-FileLoader.git@main
)

ARIEO_ENGINE_PROJECT(
    arieo_model_loader_module
    PROJECT_TYPE module

    DEPENDENCIES
        ARIEO_PACKAGES
            Arieo-Core
            Arieo-Interface-FileLoader
        THIRDPARTY_PACKAGES
            tinyobjloader
        PRIVATE_LIBS
            Arieo-Interface-FileLoader::arieo_file_loader_interface
            Arieo-Core::arieo_core
            tinyobjloader::tinyobjloader

    SOURCES
        CXX_SOURCES
            ${CMAKE_CURRENT_LIST_DIR}/private/src/*.cpp
            ${CMAKE_CURRENT_LIST_DIR}/private/src/*/*.cpp
)
