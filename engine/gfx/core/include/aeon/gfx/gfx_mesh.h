/*
 * Copyright (c) 2012-2018 Robin Degen
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <aeon/gfx/gfx_buffer.h>
#include <aeon/common/exception.h>
#include <aeon/data/mesh.h>
#include <aeon/math/mat4.h>
#include <vector>

namespace aeon::gfx
{

DEFINE_EXCEPTION_OBJECT(gfx_mesh_exception, aeon::common::exception, "Mesh exception.");

class mesh
{
public:
    mesh() = default;
    virtual ~mesh() = default;

    virtual void upload_vertex_buffer(const std::vector<data::vertex_data> &vertex_data,
                                      const gfx::buffer_usage usage) = 0;
    virtual void upload_index_buffer(const std::vector<std::uint32_t> &index_data, const gfx::buffer_usage usage) = 0;

    virtual void render(const math::mat4 &projection, const math::mat4 &view, const math::mat4 &model) = 0;

    /*!
     * Returns true of the material used for this mesh has an alpha channel.
     */
    virtual auto has_alpha() const -> bool = 0;
};

} // namespace aeon::gfx
