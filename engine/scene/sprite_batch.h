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

#include <scene/scene_object.h>
#include <gfx/gfx_buffer.h>
#include <common/buffer.h>
#include <vector>
#include <memory>

namespace aeon
{
namespace scene
{

struct sprite_vertex
{
    float x, y;
    float u, v;
    float r, g, b, a;
};

class sprite;
class sprite_batch : public scene_object
{
    friend class sprite;

public:
    static const std::uint16_t default_sprites_per_buffer = 512;
    static const int vertices_per_sprite = 4;
    static const std::uint16_t indices_per_sprite = 6;

    sprite_batch(scene_manager *scene_manager, std::uint16_t sprites_per_buffer = default_sprites_per_buffer);
    virtual ~sprite_batch() = default;

private:
    void __add_sprite(sprite *spr);
    void __remove_sprite(sprite *spr);

    void __create_and_setup_vertex_buffer();
    void __create_and_setup_index_buffer();
    void __sort_by_zorder();

    void __fill_and_upload_sprite_data_buffer();

    virtual void render(float dt) override;

    /*!
     * Determines how many sprites are stored to the vertex buffer per render.
     * if more sprites are added to the sprite batch, multiple render calls will
     * be made.
     */
    std::uint16_t sprites_per_buffer_;

    std::vector<sprite *> sprites_;
    common::buffer_u8 sprite_vertex_data_;

    gfx::buffer_ptr vertex_buffer_;
    gfx::buffer_ptr index_buffer_;
};

using sprite_batch_ptr = std::shared_ptr<sprite_batch>;

} // namespace scene
} // namespace aeon
