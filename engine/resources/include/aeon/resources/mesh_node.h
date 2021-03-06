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

#include <aeon/resources/submesh.h>
#include <aeon/common/container.h>
#include <aeon/math/mat4.h>
#include <string>
#include <vector>
#include <memory>

namespace aeon::resources
{

class mesh_node
{
public:
    explicit mesh_node(const std::string &name, const math::mat4 &matrix, const std::vector<submesh *> &submeshes);
    ~mesh_node() = default;

    mesh_node(const mesh_node &) noexcept = delete;
    auto operator=(const mesh_node &) noexcept -> mesh_node & = delete;

    mesh_node(mesh_node &&) noexcept = default;
    auto operator=(mesh_node &&) noexcept -> mesh_node & = default;

    auto create_child(const std::string &name, const math::mat4 &matrix, const std::vector<submesh *> &submeshes)
        -> mesh_node &;

    const auto &get_name() const
    {
        return name_;
    }

    const auto &get_matrix() const
    {
        return matrix_;
    }

    auto get_children() const
    {
        return common::container::transform<mesh_node *>(children_, [](const auto &c) { return c.get(); });
    }

    const auto &get_submeshes() const
    {
        return submeshes_;
    }

private:
    math::mat4 matrix_;
    std::string name_;
    std::vector<std::unique_ptr<mesh_node>> children_;
    std::vector<submesh *> submeshes_;
};

} // namespace aeon::resources
