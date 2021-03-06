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

#include <managed_interface/core/types.h>
#include <aeon/input/input_mouse_buttons.h>
#include <aeon/input/input_keyboard_keys.h>
#include <aeon/platform/platform_window.h>

namespace aeon
{
namespace mono
{
namespace managed_interface
{

class input_manager
{
public:
    static void register_internal_calls();

private:
    static auto get_mouse_cursor_position() -> math::vector2<float>;
    static auto get_mouse_button_state(input::mouse_button button) -> input::mouse_button_state;
    static auto get_key_state(input::keyboard_key key) -> input::keyboard_key_state;
    static auto is_any_key_down() -> bool;
    static auto is_any_mouse_button_down() -> bool;
    static auto get_mouse_button_up(input::mouse_button button) -> bool;
    static auto get_mouse_button_down(input::mouse_button button) -> bool;
    static auto get_key_up(input::keyboard_key key) -> bool;
    static auto get_key_down(input::keyboard_key key) -> bool;
    static void set_cursor_mode(platform::mouse_cursor_mode mode);
    static auto get_cursor_mode() -> platform::mouse_cursor_mode;
};

} // namespace managed_interface
} // namespace mono
} // namespace aeon
