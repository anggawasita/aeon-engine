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

#include <gfx/gl/gfx_gl_texture_manager.h>
#include <gfx/gl/gfx_gl_texture.h>
#include <resources/image.h>
#include <GL/glew.h>

namespace aeon
{
namespace gfx
{
namespace gl
{

texture_ptr texture_manager::__load_texture(resources::image_ptr image)
{
    texture_gl_ptr t = std::make_shared<gl::texture>(image);

    GLuint handle = 0;
    glGenTextures(1, &handle);
    glBindTexture(GL_TEXTURE_2D, handle);

    GLint pixelformat = __image_pixelformat_to_gl(image->get_pixelformat());
    GLsizei width = image->get_width();
    GLsizei height = image->get_height();
    glTexImage2D(GL_TEXTURE_2D, 0, pixelformat, width, height, 0, pixelformat, GL_UNSIGNED_BYTE,
                 image->get_data().data());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    t->handle_ = handle;
    t->size_ = glm::vec2(width, height);

    return t;
}

GLint texture_manager::__image_pixelformat_to_gl(resources::image::pixel_format format)
{
    switch (format)
    {
    case resources::image::pixel_format::rgb:
        return GL_RGB;
    case resources::image::pixel_format::rgba:
        return GL_RGBA;
    default:
        // TODO: Error condition?
        return GL_RGBA;
    }
}

} // namespace gl
} // namespace gfx
} // namespace aeon
