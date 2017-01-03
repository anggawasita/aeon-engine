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

#include <aeon/scene/render_queue.h>
#include <algorithm>
#include <cassert>

namespace aeon
{
namespace scene
{

void render_queue::add_render_object(const glm::mat4 &matrix, const std::shared_ptr<scene_object> &object,
                                     const int group)
{
    assert(group < render_layer::max);

    objects_.push_back(render_queue_object{matrix, object, group});
}

void render_queue::clear_render_objects()
{
    objects_.clear();
}

void render_queue::sort()
{
    std::sort(objects_.begin(), objects_.end(),
              [](const render_queue_object &a, const render_queue_object &b) { return a.group < b.group; });
}

} // namespace scene
} // namespace aeon
