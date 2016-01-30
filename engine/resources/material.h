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

#include <resources/resource.h>
#include <resources/exceptions.h>
#include <resources/wrappers/material_resource_wrapper.h>
#include <resources/wrappers/image_resource_wrapper.h>
#include <common/buffer.h>
#include <memory>

namespace aeon
{
namespace resources
{

class material : public resource
{
public:
    explicit material(resource_wrapper_ptr wrapper);
    virtual ~material() = default;

    void set_data(image_resource_wrapper_ptr image);

    material_resource_wrapper_ptr get_material_resource_wrapper()
    {
        return std::dynamic_pointer_cast<material_resource_wrapper>(get_resource_wrapper());
    }

    image_resource_wrapper_ptr get_texture_resource()
    {
        return texture_resource_;
    }

private:
    image_resource_wrapper_ptr texture_resource_;
};

using material_ptr = std::shared_ptr<material>;

} // namespace resources
} // namespace aeon
