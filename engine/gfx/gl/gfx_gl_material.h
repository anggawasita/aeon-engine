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

#include <GL/glew.h>
#include <gfx/gfx_material.h>

namespace aeon
{
namespace gfx
{
namespace gl
{

class material : public gfx::material
{
    friend class material_manager;

    void bind() override;

public:
    material() = default;
    ~material() = default;
};

using material_gl_ptr = std::shared_ptr<material>;

} // namespace gl
} // namespace gfx
} // namespace aeon