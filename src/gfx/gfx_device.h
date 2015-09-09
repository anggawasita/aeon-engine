/*
 * ROBIN DEGEN; CONFIDENTIAL
 *
 * 2012 - 2015 Robin Degen
 * All Rights Reserved.
 *
 * NOTICE:  All information contained herein is, and remains the property of
 * Robin Degen and its suppliers, if any. The intellectual and technical
 *  concepts contained herein are proprietary to Robin Degen and its suppliers
 * and may be covered by U.S. and Foreign Patents, patents in process, and are
 * protected by trade secret or copyright law. Dissemination of this
 * information or reproduction of this material is strictly forbidden unless
 * prior written permission is obtained from Robin Degen.
 */

#pragma once

#include <memory>

namespace aeon
{
namespace gfx
{

class shader_manager;
class texture_manager;

class device
{
public:
    device();
    ~device();

protected:
    std::shared_ptr<texture_manager> texture_manager_;
    std::shared_ptr<shader_manager> shader_manager_;
};

} // namespace gfx
} // namespace aeon