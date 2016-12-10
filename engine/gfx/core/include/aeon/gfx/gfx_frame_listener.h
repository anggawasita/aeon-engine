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

#include <memory>

namespace aeon
{
namespace gfx
{

class frame_listener
{
public:
    frame_listener() = default;
    virtual ~frame_listener() = default;

    virtual bool on_frame_begin(const float /*dt*/)
    {
        return true;
    }
    virtual bool on_frame_end(const float /*dt*/)
    {
        return true;
    }
};

} // namespace gfx
} // namespace aeon