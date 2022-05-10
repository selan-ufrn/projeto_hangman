#ifndef _HANGMAN_GM_H_
#define _HANGMAN_GM_H_

#include <string>     // std::string
#include <array>
#include <unordered_map>

#include "hangman_common.h"
#include "hm_word.h"
#include "player.h"
#include "dice.h"

/*!
 * This class represents the Game Controller which keeps track of player,
 * scores, and match total values, as well as determining when a match ends.
 */
class GameController{
    private:
        //=== Structs
        //!< The game states.
        enum class game_state_e : short {
            STARTING=0,          //!< Beginning the game.
            WELCOME,             //!< Opening messasges.
            QUITTING,            //!< User might want to quit (before game finishes), need to confirm.
            ENDING,              //!< Closing the game (final message).
        };

        //!< The menu options.
        enum class menu_e : short {
            PLAY=1,              //!< Begin new game.
            RULES,               //!< Show rules of the game.
            SCORE,               //!< Show top scores.
            EXIT,                //!< Exit the game.
            UNDEFINED,           //!< No option chosen.
        };

        //!< The match status.
        enum class match_e: short {
            ON=1,        //!< Match still open and running.
            PLAYER_WON,  //!< Match ended and player WON.
            PLAYER_LOST, //!< Match ended and player LOST.
            UNDEFINED,   //!< Undefined match status.
        };

        //=== Data members
        game_state_e m_game_state;   //!< Current game state.
        menu_e m_menu_option;        //!< Current menu option.
        std::string m_system_msg;    //!< Current system message displayed to user.
        bool m_asked_to_quit;        //!< Flag that indicates whether the user wants to end an ongoing game.
        bool m_match_ended;          //!< Flag that indicates whether the current match has ended or not.
        bool m_reveal_word;          //!< Flag that is active when user looses and we need to show the answer.

        //=== Game related members
        Player m_curr_player;       //!< Reference to the current player.
        char m_ch_guess=0;           //!< Latest player guessed letter.
        HangmanWord m_secret_word;   //!< Keeps track of the masked word, wrong guesses, etc.
        size_t m_max_mistakes;       //!< Max number of mistakes allowed in a match.
        std::string m_user_name;     //!< Stores the user name provided in the Welcome state.

    public:
        //=== Public interface
        GameController()=default;
        GameController(const GameController&) = delete;
        GameController(GameController&&) = delete;
        GameController& operator=(const GameController&) = delete;
        GameController& operator=(GameController&&) = delete;
        ~GameController() = default;

        //=== Common methods for the Game Loop design pattern.
        GameState initialize(int argc, char* argv[]);
        /// Renders the game to the user.
        void render(void) const;
        /// Update the game based on the current game state.
        void update(void);
        /// Process user input events, depending on the current game state.
        void process_events(void);
        /// Returns true when the user wants to quit the game.
        bool game_over(void) const;

    private:
        // === These read_xxx() methods are called in process_events()
        /// Reads the user command inside the action screen.
        std::string read_user_command( void ) const;
        /// Read the user name at the beginning of the game.
        std::string read_user_name(void);
        /// Reads the user confirmation, Yes/No.
        bool read_user_confirmation() const;
        /// Reads a simple enter from the user. (aka a pause)
        void read_enter_to_proceed(void) const;
        /// Reads user guess letter.
        char read_user_guess(void);
        /// Reads user menu choice.
        menu_e read_menu_option(void);

        // === These display_xxx() methods are called in render()
        /// Show the welcome mesage.
        void display_welcome(void) const;
        /// Show the main menu.
        void display_main_menu(void) const;
        /// Show main play screen (w/ the hagman)
        void display_play_screen(void) const;
        /// Show screen confirming user quitting a challenge.
        void display_quitting(void) const;
        /// Show the game rules.
        void display_rules(void) const;
        /// Show farewell message displayed at the end of the game.
        void display_endgame(void) const;
        /// Show the top (5?) score board.
        void display_scoreboard(void) const;

        // === These show_xxx() methods display common elements to every screen.
        /* All screens may have up to 4 components:
         *  (1) title,                  -> must have
         *  (2) main content,           -> must have
         *  (3) a system message,       -> optional
         *  (4) an interaction message. -> optional
         */
        /// Show screen title.
        void show_screen_title(const std::string&) const;
        /// Show system message to player.
        void show_system_msg(const std::string&) const;
        /// Show interactive message to player.
        void show_interaction_msg(const std::string&) const;

        /// Evaluates the match situation, whether it's over or if it still on.
        match_e match_status() const;
        /// Show the gallows with the hangman, whose body displayed depends on the # of mistakes made (argument).
        void display_gallows(short) const;
        /// Return the current score based on correct/wrong guesses.
        long match_score(void) const;
        /// Reset a new match.
        void reset_match(void);
};
#endif
