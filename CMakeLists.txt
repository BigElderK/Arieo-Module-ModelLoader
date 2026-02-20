cmake_minimum_required (VERSION 3.31)

include($ENV{ARIEO_BUILD_ENV_PACKAGES_OUTPUT_DIR}/cmake/build_environment.cmake)
project(ArieoEngine)

arieo_engine_project(
    arieo_model_loader_module
    PROJECT_TYPE module

    DEPENDENCIES
        ARIEO_PACKAGES
            Arieo-Core
            Arieo-Interface-FileLoader
        THIRDPARTY_PACKAGES
            tinyobjloader
        INTERFACES
            Arieo-Interface-FileLoader::arieo_file_loader_interface
        PRIVATE_LIBS
            Arieo-Core::arieo_core
            tinyobjloader::tinyobjloader

    SOURCES
        CXX_SOURCES
            ${CMAKE_CURRENT_LIST_DIR}/private/src/*.cpp
            ${CMAKE_CURRENT_LIST_DIR}/private/src/*/*.cpp
)
