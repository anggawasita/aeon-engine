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

#include <scene/scene_manager.h>

namespace aeon
{
namespace scene
{

class basic_scene_manager : public scene_manager
{
public:
    explicit basic_scene_manager(gfx::device &device);
    virtual ~basic_scene_manager();

private:
    void __prepare_render_queue(camera *cam) override;

};

} // namespace scene
} // namespace aeon
