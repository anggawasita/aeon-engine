/*
 * ROBIN DEGEN; CONFIDENTIAL
 *
 * 2012 - 2017 Robin Degen
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
#include <aeon/gfx/gfx_monitor.h>
#include <GLFW/glfw3.h>

namespace aeon
{
namespace gfx
{
namespace gl
{

class gfx_gl_monitor : public gfx_monitor
{
public:
    gfx_gl_monitor(GLFWmonitor *monitor, int width, int height, int x, int y, bool primary, const std::string &name);
    virtual ~gfx_gl_monitor() = default;

    void set_gramma(float gamma) override;

    gamma_ramp get_gamma_ramp() override;
    void set_gamma_ramp(gamma_ramp ramp) override;

    video_mode get_video_mode() override;
    video_modes get_video_modes() override;

    GLFWmonitor *get_internal_handle() const
    {
        return monitor_;
    }

private:
    GLFWmonitor *monitor_;
};

} // namespace gl
} // namespace gfx
} // namespace aeon
