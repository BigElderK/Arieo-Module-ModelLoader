#include "base/prerequisites.h"
#include "core/core.h"
#include <memory>
#include <sstream>

#include <tiny_obj_loader.h>
#include "model_loader.h"

namespace Arieo
{
    Interface::FileLoader::ModelBuffer ModelLoader::loadObj(void* buffer, size_t size)
    {
        tinyobj::attrib_t attrib;
        std::vector<tinyobj::shape_t> shapes;
        std::vector<tinyobj::material_t> materials;
        std::string warn, err;

        std::istringstream istream(std::string((const char*)buffer, size));
        bool load_result = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, &istream);
        if(warn.length() > 0)
        {
            Core::Logger::warn(warn);
        }
        if (load_result == false) 
        {
            Core::Logger::error(err);
            return Interface::FileLoader::ModelBuffer{};
        }

        Interface::FileLoader::ModelBuffer model_buffer;
        for (const auto& shape : shapes) 
        {
            for (const auto& index : shape.mesh.indices) 
            {
                model_buffer.m_vertices.emplace_back(
                    Interface::FileLoader::ModelBuffer::Vertex
                    {
                        // Position
                        {
                            attrib.vertices[3 * index.vertex_index + 1],
                            attrib.vertices[3 * index.vertex_index + 2],
                            attrib.vertices[3 * index.vertex_index + 0],
                        },
                        // Color
                        {
                            1.0f, 1.0f, 1.0f
                        },
                        // Tex Coord
                        {
                            attrib.texcoords[2 * index.texcoord_index + 0],
                            1.0f - attrib.texcoords[2 * index.texcoord_index + 1]
                        }
                    }
                );
                model_buffer.m_indices.push_back(model_buffer.m_indices.size());
            }
        }

        return model_buffer;
    }
}