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

#include <aeon/data/image.h>

namespace aeon
{
namespace data
{

image::image(std::vector<std::uint8_t> &&buffer, const unsigned int width, const unsigned int height,
             pixel_format pixelformat, const unsigned int mipmap_count)
    : buffer_(std::move(buffer))
    , width_(width)
    , height_(height)
    , pixel_format_(pixelformat)
    , mipmap_count_(mipmap_count)
{
}

auto image::has_data() const -> bool
{
    return buffer_.empty();
}

auto image::get_data() const -> const std::vector<std::uint8_t> &
{
    return buffer_;
}

auto image::get_width() const -> unsigned int
{
    return width_;
}

auto image::get_height() const -> unsigned int
{
    return height_;
}

auto image::get_size() const -> math::vector2<float>
{
    return math::vector2<float>{width_, height_};
}

auto image::get_pixelformat() const -> image::pixel_format
{
    return pixel_format_;
}

auto image::get_mipmap_count() const -> unsigned int
{
    return mipmap_count_;
}

} // namespace data
} // namespace aeon
