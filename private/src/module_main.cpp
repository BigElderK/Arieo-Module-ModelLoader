#include "base/prerequisites.h"
#include "core/core.h"
#include "model_loader.h"
namespace Arieo
{
    GENERATOR_MODULE_ENTRY_FUN()
    ARIEO_DLLEXPORT void ModuleMain()
    {
        Core::Logger::setDefaultLogger("model_loader");

        static struct DllLoader
        {
            ModelLoader model_loader;
            DllLoader()
            {
                Core::ModuleManager::registerInterface<Interface::FileLoader::IModelLoader>(
                    "model_loader", 
                    &model_loader
                );
            }

            ~DllLoader()
            {
                Core::ModuleManager::unregisterInterface<Interface::FileLoader::IModelLoader>(
                    &model_loader
                );
            }
        } dll_loader;
    }
}