cmake_minimum_required (VERSION 3.31)
    arieo_engine_project(
        arieo_model_loader_module
        ALIAS arieo::modules::model_loader
        PROJECT_TYPE module
        SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/private/src/*.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/private/src/*/*.cpp
        INTERFACES
            arieo::interface::file_loader
        PACKAGES
            tinyobjloader
        LIBS
            arieo::base
            arieo::core
            tinyobjloader::tinyobjloader
    )