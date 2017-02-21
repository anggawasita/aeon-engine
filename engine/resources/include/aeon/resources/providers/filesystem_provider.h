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

#pragma once

#include <aeon/resources/providers/resource_provider.h>
#include <aeon/resources/resource_encoding.h>
#include <aeon/resources/exceptions.h>
#include <aeon/common/logger.h>
#include <vector>
#include <string>

namespace aeon
{
namespace resources
{

DEFINE_EXCEPTION_OBJECT(filesystem_provider_exception, resource_provider_exception, "Filesystem Provider exception.");
DEFINE_EXCEPTION_OBJECT(filesystem_provider_list_exception, filesystem_provider_exception,
                        "Filesystem Provider list exception. Can not list given path.");
DEFINE_EXCEPTION_OBJECT(
    filesystem_provider_read_exception, filesystem_provider_exception,
    "Filesystem Provider read exception. Can not read given path. Path does not exist or is unreadable.");
DEFINE_EXCEPTION_OBJECT(
    filesystem_provider_type_exception, filesystem_provider_exception,
    "Filesystem Provider type exception. Can not figure out the type of the resource. File has no extension.");

class filesystem_provider : public resource_provider
{
public:
    explicit filesystem_provider(const std::string &base_path);
    virtual ~filesystem_provider();

private:
    auto exists(const std::string &path) const -> bool override;
    auto list(const std::string &path) const -> std::vector<resource_node> override;
    void read(const std::string &path, std::vector<std::uint8_t> &buffer) override;
    auto get_encoding(const std::string &path) const -> resource_encoding override;

    logger::logger logger_;

    std::string base_path_;
};

} // namespace resources
} // namespace aeon
