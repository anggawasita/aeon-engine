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

#include <common/has_z_order.h>
#include <scene/scene_object.h>
#include <gfx/gfx_material.h>
#include <glm/vec2.hpp>
#include <memory>

namespace aeon
{
namespace scene
{

class sprite_batch;
using sprite_batch_ptr = std::shared_ptr<sprite_batch>;

class sprite : public scene_object, public common::has_z_order
{
public:
    explicit sprite(scene_manager *scene_manager, sprite_batch_ptr batch, gfx::material_ptr texture, int zorder);
    explicit sprite(scene_manager *scene_manager, sprite_batch_ptr batch, gfx::material_ptr texture, glm::vec2 size, int zorder);

    virtual ~sprite();

    void set_default_size();

    void set_size(glm::vec2 size);
    void set_size(float width, float height);

    glm::vec2 get_size() const;

    void set_material(gfx::material_ptr texture);
    gfx::material_ptr get_material() const;

protected:
    glm::vec2 size_;
    gfx::material_ptr material_;
    sprite_batch_ptr batch_;
};

using sprite_ptr = std::shared_ptr<sprite>;

} // namespace scene
} // namespace aeon
