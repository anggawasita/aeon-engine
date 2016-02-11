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

#include <gtest/gtest.h>
#include <scene/render_queue.h>
#include <scene/sprite.h>
#include <scene/sprite_batch.h>
#include <aeon/platform.h>

AEON_IGNORE_VS_WARNING(4189)

using namespace aeon;

TEST(test_render_queue, test_render_queue_create)
{
    ASSERT_NO_THROW(scene::render_queue queue);
}
