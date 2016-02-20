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

#include <gfx/gfx_buffer.h>
#include <common/exception.h>
#include <GL/glew.h>
#include <memory>

namespace aeon
{
namespace gfx
{
namespace gl
{

DEFINE_EXCEPTION_OBJECT(gfx_opengl_buffer_exception, aeon::common::exception, "GL Buffer error");

class buffer : public gfx::buffer
{
public:
    explicit buffer(buffer_type type);
    virtual ~buffer();

    void set_data(int size, const void *data, buffer_usage usage) override;

    void bind() override;

private:
    GLenum __buffer_type_as_gl_enum() const;
    GLenum __buffer_usage_as_gl_enum(buffer_usage usage) const;

    GLuint handle_;
};

using buffer_ptr = std::shared_ptr<buffer>;

} // namespace gl
} // namespace gfx
} // namespace aeon