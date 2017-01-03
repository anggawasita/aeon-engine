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

#include <aeon/scene/orthographic_camera.h>
#include <glm/gtc/matrix_transform.hpp>

namespace aeon
{
namespace scene
{

orthographic_camera::orthographic_camera(scene_manager *scene_manager, const float left, const float right,
                                         const float bottom, const float top)
    : camera(scene_manager)
{
    projection_matrix_ = glm::ortho(left, right, bottom, top);
}

orthographic_camera::orthographic_camera(scene_manager *scene_manager, const float left, const float right,
                                         const float bottom, const float top, const float near, const float far)
    : camera(scene_manager)
{
    projection_matrix_ = glm::ortho(left, right, bottom, top, near, far);
}

orthographic_camera::orthographic_camera(scene_manager *scene_manager, const int left, const int right,
                                         const int bottom, const int top)
    : camera(scene_manager)
{
    projection_matrix_ = glm::ortho(static_cast<float>(left), static_cast<float>(right), static_cast<float>(bottom),
                                    static_cast<float>(top));
}

orthographic_camera::orthographic_camera(scene_manager *scene_manager, const int left, const int right,
                                         const int bottom, const int top, const float near, const float far)
    : camera(scene_manager)
{
    projection_matrix_ = glm::ortho(static_cast<float>(left), static_cast<float>(right), static_cast<float>(bottom),
                                    static_cast<float>(top), near, far);
}

} // namespace scene
} // namespace aeon
