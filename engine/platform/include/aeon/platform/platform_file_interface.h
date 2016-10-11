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

#include <aeon/platform/platform_file_open_mode.h>
#include <aeon/platform/platform_exception.h>
#include <aeon/common/buffer.h>
#include <memory>
#include <string>

namespace aeon
{
namespace platform
{

DEFINE_EXCEPTION_OBJECT(platform_file_exception, platform_exception, "File I/O error.");
DEFINE_EXCEPTION_OBJECT(platform_file_open_exception, platform_file_exception, "Error while opening file.");
DEFINE_EXCEPTION_OBJECT(platform_file_read_exception, platform_file_exception, "Error while reading file.");
DEFINE_EXCEPTION_OBJECT(platform_file_write_exception, platform_file_exception, "Error while writing to file.");

class platform_file_interface
{
    friend class platform_filesystem_interface;

public:
    enum class seek_direction
    {
        begin,
        current,
        end,
    };

    virtual ~platform_file_interface() = default;

    virtual void read(common::buffer_u8 &buffer) = 0;
    virtual void read(common::buffer_u8 &buffer, int size) = 0;

    virtual void write(common::buffer_u8 &buffer) = 0;
    virtual void write(common::buffer_u8 &buffer, int size) = 0;

    virtual void seek_read(seek_direction direction, int offset) = 0;
    virtual void seek_write(seek_direction direction, int offset) = 0;

    virtual int get_size() = 0;

    const std::string &get_path() const
    {
        return path_;
    }

protected:
    explicit platform_file_interface(const std::string &path, int openmode)
        : openmode_(openmode)
        , path_(path)
    {
    }

private:
    int openmode_;
    std::string path_;
};

using platform_file_interface_ptr = std::shared_ptr<platform_file_interface>;

} // namespace platform
} // namespace aeon