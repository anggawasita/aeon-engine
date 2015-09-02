/*
 * ROBIN DEGEN; CONFIDENTIAL
 *
 * 2012 - 2015 Robin Degen
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

#include "stdafx.h"

namespace aeon
{

rpg_game::rpg_game() :
    gamestate_game_(std::make_shared<game_state_game>())
{

}

rpg_game::~rpg_game()
{

}

bool rpg_game::on_initialize()
{
    console::debug("RPGGame::on_initialize()");

    return true;
}

void rpg_game::on_run()
{
    console::debug("RPGGame::on_run()");

    set_gamestate(gamestate_game_);
}

void rpg_game::on_stop()
{
    console::debug("RPGGame::on_stop()");
}

void rpg_game::on_cleanup()
{
    console::debug("RPGGame::on_cleanup()");
}

} // namespace aeon
