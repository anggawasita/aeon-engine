/*
 * ROBIN DEGEN; CONFIDENTIAL
 *
 * 2012 - 2016 Robin Degen
 * All Rights Reserved.
 *
 * NOTICE:  All information contained herein is, and remains the property of
 * Robin Degen and its suppliers, if any. The intellectual and technical
 * concepts contained herein are proprietary to Robin Degen and its suppliers
 * and may be covered by U.S. and Foreign Patents, patents in process, and are
 * protected by trade secret or copyright law. Dissemination of this
 * information or reproduction of this material is strictly forbidden unless
 * prior written permission is obtained from Robin Degen.
 */

#pragma once

#include <gfx/gfx_material.h>
#include <glm/mat4x4.hpp>
#include <common/exception.h>
#include <memory>

namespace aeon
{
namespace gfx
{

DEFINE_EXCEPTION_OBJECT(gfx_mesh_exception, aeon::common::exception, "Mesh exception.");

class mesh
{
public:
    explicit mesh(material_ptr material);
    virtual ~mesh() = default;

    virtual void upload_index_buffer() = 0;
    virtual void upload_vertex_buffer() = 0;

    virtual void render(const glm::mat4x4 &projection, const glm::mat4x4 &view, const glm::mat4x4 &model) = 0;


};

using mesh_ptr = std::unique_ptr<mesh>;

} // namespace gfx
} // namespace aeon
