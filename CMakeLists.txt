cmake_minimum_required (VERSION 3.31)

include($ENV{ARIEO_BUILDENV_PACKAGE_INSTALL_FOLDER}/cmake/build_environment.cmake)
project(ArieoEngine)

    arieo_engine_project(
        arieo_model_loader_module
        PROJECT_TYPE module

        PACKAGES
            Arieo-Interface-FileLoader
            tinyobjloader
            Arieo-Core
        INTERFACES
            Arieo-Interface-FileLoader::arieo_file_loader_interface
        PRIVATE_LIBS
            Arieo-Core::arieo_core
            tinyobjloader::tinyobjloader

        SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/private/src/*.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/private/src/*/*.cpp
    )