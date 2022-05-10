#ifndef _HANGMAN_COMMON_H_
#define _HANGMAN_COMMON_H_

#include <vector>
#include <algorithm>

#include "dice.h"

//<! represent the current game status.
struct GameState
{
    enum class value_e : short  { OK, ERROR };
    value_e value;
    std::string msg;
    // Ctro.
    GameState(value_e v=value_e::OK, std::string m="") : value{v}, msg{m}
    { /* empty */ }
};

#endif
