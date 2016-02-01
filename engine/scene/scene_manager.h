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

#include <vector>
#include <scene/scene_node.h>
#include <scene/viewport.h>
#include <scene/render_queue.h>
#include <gfx/gfx_device.h>

namespace aeon
{
namespace scene
{

class scene_manager
{
public:
    explicit scene_manager(gfx::device &device);
    virtual ~scene_manager() = default;

    scene_node_ptr create_child_scene_node();

    void detach_child_scene_node(scene_node_ptr node);

    void attach_viewport(viewport_ptr vp);

    void detach_viewport(viewport_ptr vp);

    void remove_all_viewports();

    virtual void prepare_render_queue() = 0;

protected:
    scene_node_ptr root_node_;
    render_queue queue_;
    std::vector<viewport_ptr> viewports_;
    gfx::device &device_;
};

} // namespace scene
} // namespace aeon
