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
#include <aeon/scene/render_layer.h>
#include <glm/mat4x4.hpp>

namespace aeon
{
namespace scene
{

enum class scene_object_type
{
    spatial, // This object is merely added for spatial information (camera's etc.)
    sprite,  // 2D object
    mesh     // 3D object
};

class scene_node;
class scene_manager;
class scene_object
{
    friend class scene_node;

public:
    explicit scene_object(const int queue_group, const scene_object_type type, scene_manager *scene_manager)
        : queue_group_(queue_group)
        , type_(type)
        , scene_manager_(scene_manager)
        , scene_node_(nullptr)
    {
    }

    virtual ~scene_object() = default;

    auto get_type() const
    {
        return type_;
    }

    auto get_queue_group() const
    {
        return queue_group_;
    }

    /*!
     * Called by the render queue when rendering. For some objects rendering
     * doesn't make sense (like camera's). In that case, this function must be
     * used to set up the matrices and/or buffers.
     */
    virtual void render(const glm::mat4x4 & /*projection*/, const glm::mat4x4 & /*view*/, const glm::mat4x4 & /*model*/,
                        const float /*dt*/)
    {
    }

    /*!
     * Get the calculated matrix from the scene node. If this object is not attached
     * to any scene node, an identity matrix will be returned.
     */
    auto get_scene_matrix() const -> glm::mat4;

protected:
    void __set_scene_node(scene_node *node)
    {
        scene_node_ = node;
    }

    int queue_group_;
    scene_object_type type_;
    scene_manager *scene_manager_;
    scene_node *scene_node_;
};

} // namespace scene
} // namespace aeon