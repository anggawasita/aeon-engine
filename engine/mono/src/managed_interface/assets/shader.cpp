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

#include <managed_interface/assets/shader.h>
#include <managed_interface/mono_object_wrapper.h>
#include <aeon/mono/mono_jit.h>
#include <aeon/mono/mono_string.h>
#include <aeon/mono/mono_jit_manager.h>
#include <memory>

namespace aeon
{
namespace mono
{
namespace managed_interface
{

void shader::register_internal_calls()
{
    mono_jit::add_internal_call("AeonEngineMono.Assets.Shader::.ctor(string)", aeon_mono_auto_wrap(shader::ctor));
}

auto shader::get_shader_from_mono_object(MonoObject *object) -> std::shared_ptr<gfx::shader>
{
    return mono_object_wrapper<std::shared_ptr<gfx::shader>>::get_native_object(object);
}

void shader::ctor(MonoObject *this_ptr, std::string path)
{
    auto &asset_manager = mono_jit_manager::get_application().get_asset_manager();
    auto loaded_shader = asset_manager.load_shader(path);

    mono_object_wrapper<std::shared_ptr<gfx::shader>>::create(this_ptr, loaded_shader);
}

} // namespace managed_interface
} // namespace mono
} // namespace aeon
