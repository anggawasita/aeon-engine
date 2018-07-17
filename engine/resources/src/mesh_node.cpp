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

#include <aeon/resources/mesh_node.h>

namespace aeon
{
namespace resources
{

mesh_node::mesh_node(const std::string &name, const math::mat4 &matrix, const std::vector<submesh *> &submeshes)
    : matrix_(matrix)
    , name_(name)
    , submeshes_(submeshes)
{
}

auto mesh_node::create_child(const std::string &name, const math::mat4 &matrix, const std::vector<submesh *> &submeshes)
    -> mesh_node &
{
    auto mesh = std::make_unique<mesh_node>(name, matrix, submeshes);
    const auto mesh_ptr = mesh.get();

    children_.emplace_back(std::move(mesh));

    return *mesh_ptr;
}

} // namespace resources
} // namespace aeon
