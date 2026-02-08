#pragma once
#include "interface/file_loader/model_loader.h"
#include <fstream>
namespace Arieo
{
    class ModelLoader
        : public Interface::FileLoader::IModelLoader
    {
    public:
        Interface::FileLoader::ModelBuffer loadObj(void* buffer, size_t size) override;
    };
}