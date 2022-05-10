#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <cstddef>
#include <string>

#include "hangman_common.h"

/// Representing a single player.
class Player {
    private:
        std::string m_name; //!< The player's name
        size_t m_score;     //!< The player's total score.
    public:
        /// Default Ctro.
        Player(std::string n="no_name") : m_name{n}, m_score{0}
        {/*empty*/}
        /// Dtro
        ~Player() = default;
        /// Returns the player's name
        std::string name(void) const;
        ///  Sets player name.
        void name(const std::string&);
        /// Returns the player's log of turn total s/he's won so far in the match.
        size_t score(void) const;
        /// Add a match value to the player's log.
        void add_score(size_t);
};
#endif
