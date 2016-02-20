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

#include <gfx/gl/gfx_gl_buffer_manager.h>
#include <gfx/gl/gfx_gl_buffer.h>

namespace aeon
{
namespace gfx
{
namespace gl
{

gfx::buffer_ptr buffer_manager::__create_buffer(buffer_type type)
{
    return std::make_shared<gl::buffer>(type);
}

} // namespace gl
} // namespace gfx
} // namespace aeon