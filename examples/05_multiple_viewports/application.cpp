/*
 * Copyright (c) 2012-2017 Robin Degen
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include "application.h"
#include <aeon/scene/sprite.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

application::application()
    : aeon::desktop_application<aeon::scene::basic_scene_manager>(WINDOW_WIDTH, WINDOW_HEIGHT,
                                                                  "Example 5 - Multiple Viewports")
{
    // Init resources
    get_resource_manager()->mount(std::make_shared<aeon::resources::filesystem_provider>("."), "/");

    // Set up the scene. Because we are splitting the scene vertically, the camera only has half the window to
    // render to. This is why we divide the width by 2. If this is not done, the aspect ratio will look really strange.
    camera_ =
        std::make_shared<aeon::scene::orthographic_camera>(get_scene_manager(), 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, 0);

    // Create the left viewport
    aeon::common::types::rectangle<float> viewport_rect_left(0.0f, 0.0f, 0.5f, 1.0f);
    window_->create_viewport(camera_, viewport_rect_left, "viewport1", 0);

    // Create the right viewport
    aeon::common::types::rectangle<float> viewport_rect_right(0.5f, 0.0f, 0.5f, 1.0f);
    window_->create_viewport(camera_, viewport_rect_right, "viewport2", 0);
}

void application::main()
{
    // Load resources
    auto ships_material = get_asset_manager().load_material("/resources/materials/ships.amf");

    // A sprite batch requires an atlas, we can either load one from an atlas file, or just generate one if
    // all the sprites have the same size and are properly aligned within the file.
    auto atlas = get_asset_manager().create_atlas(ships_material, glm::vec2(64, 64));

    // Set up scene
    auto &root_node = scene_manager_.get_root_scene_node();

    // Put the ship in the center of the screen by translating the root node
    root_node.translate(200, 300);

    // Get a region from the atlas for the sprite to render. Here we grab the 10th sprite in the texture,
    // which is counted left to right, top to bottom.
    auto region = atlas->get_region_by_index(10);

    // Create a sprite. The last parameter is the z-order; used to determine which sprite should be rendered on top
    auto ship_sprite = scene_manager_.create_scene_object<aeon::scene::sprite>(atlas, region, 0);

    // Attach the sprite to the scene
    root_node.attach_scene_object(ship_sprite);

    // Start the render loop
    platform_.run();
}
