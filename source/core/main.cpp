/**
 * @file main.cpp
 *
 * @description
 * This program implements an interactive Pig Dicegame.
 *
 * ===========================================================================
 * @license
 *
 * This file is part of HANGMAN GAME project.
 *
 * HANGMAN GAME is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HANGMAN GAME is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HANGMAN GAME.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) 2014-2022 Selan R. dos Santos, http://www.dimap.ufrn.br/~selan
 * ===========================================================================
 *
 * @author	Selan R dos Santos, <selan.santos@ufrn.br>
 * @date	2022
 *
 * @remark On 2022-03-22 refactoring to proper game-loop architecture
 */


#include <cstdlib> // EXIT_SUCCESS
#include <iostream>

#include "hangman_common.h"
#include "hangman_gm.h"

int main( int argc, char *argv[] )
{
    GameController hg;

    /// Apply std::optional
    auto result = hg.initialize( argc, argv );
    if ( result.value == GameState::value_e::ERROR ){
        std::cerr << result.msg << "\n";
        return EXIT_FAILURE;
    }

    // The Game Loop.
    while( not hg.game_over() ){
        hg.process_events();
        hg.update();
        hg.render();
    }

    return EXIT_SUCCESS;
}
