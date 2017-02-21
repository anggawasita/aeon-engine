/*
 * Copyright (c) 2012-2017 Robin Degen
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

#include <aeon/resources/wrappers/shader_resource_wrapper.h>
#include <aeon/resources/resource_manager.h>
#include <aeon/resources/codecs/shader_codec.h>

namespace aeon
{
namespace resources
{

shader_resource_wrapper::shader_resource_wrapper(resource_manager &parent, const std::string &path,
                                                 const std::weak_ptr<resource_provider> &provider)
    : resource_wrapper(parent, path, provider)
{
    if (get_type() != resource_type::shader)
        throw resource_type_exception();
}

auto shader_resource_wrapper::open() -> std::shared_ptr<shader>
{
    auto &codec = __get_parent().get_codec_manager().get_shader_codec();
    return codec.decode(__get_parent(), std::dynamic_pointer_cast<shader_resource_wrapper>(shared_from_this()));
}

} // namespace resources
} // namespace aeon
