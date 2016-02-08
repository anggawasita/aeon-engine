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
#include <resources/resource_manager.h>
#include <platform/platform_window.h>

namespace aeon
{

template<typename platform_interface_t, typename device_t, typename scene_manager_t>
class base_application
{
public:
    base_application(int width, int height, const std::string &window_title)
        : resource_manager_(platform_, device_)
        , scene_manager_(device_)
        , window_(nullptr)
    {
        // Init the platform and window
        platform_.initialize();
        window_ = platform_.create_window(width, height, window_title);

        // Init opengl
        device_.initialize();
    }

    virtual ~base_application() = default;

    platform::platform_window_ptr get_main_window() const
    {
        return window_;
    }

    scene_manager_t *get_scene_manager()
    {
        return &scene_manager_;
    }

protected:
    platform_interface_t platform_;
    device_t device_;

    resources::resource_manager resource_manager_;
    scene_manager_t scene_manager_;

    platform::platform_window_ptr window_;
};

} // namespace aeon