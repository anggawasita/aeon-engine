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

#include <aeon/scene/camera.h>
#include <memory>

namespace aeon
{
namespace scene
{

class perspective_camera : public camera
{
public:
    explicit perspective_camera(scene_manager *scene_manager, const float fov_y, const float aspect_ratio,
                                const float near, const float far, const std::string &name = "");
    explicit perspective_camera(scene_manager *scene_manager, const float fov, const float width, const float height,
                                const float near, const float far, const std::string &name = "");

    virtual ~perspective_camera() = default;
};

} // namespace scene
} // namespace aeon
