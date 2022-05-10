#ifndef HM_WORD_H
#define HM_WORD_H
/*!
 * Hangman Word class
 * @file hm_word.h
 *
 * This class represents a Hangman Word, being responsible
 * for receiving a word, a (optional) list of letter tha
 * must be revealed, and creating the corresponding masked 
 * string for display.
 *
 * This class also receives guesses, and keeps track of how
 * many of theses guesses were correct or wrong, so that at
 * the end we may retrieve this information for score
 * (performance) calculation.
 *
 * \author Selan
 * \date April 20th, 2022
 */

#include <string>
#include <vector>

class HangmanWord{
    //=== Data members or attributes.
    private:
        std::string m_secret_word;  //!< The secret word to guess.
        std::string m_masked_word;  //!< The secret word with closed letters masked.
        std::string m_open_letters; //!< List of letter to show at the start.
        long m_n_correct_guesses;   //!< # of correct guesses made by the player.
        char m_mask_char;           //!< Char used as mask to hide letters in the secret word.
        std::vector<char> m_wrong_guesses; //!< List of wrong guesses made.

    //=== Public interface
    public:
        /// Default Ctro. Assumes input strings are all lower case.
        /*!
         * @param secret The secret word.
         * @param show List of letters in the secret word to show to player.
         * @param mask Char to use as mask.
         */
        HangmanWord(const std::string& secret="", const std::string& show="", char mask='_');
        /// Default Ctro.
        ~HangmanWord() = default;
        /// Initialize the object providing a (new) word, show letters and mask char.
        void initialize(const std::string& sw, const std::string& ol="", char mch='_');
        /// Return a the secret word with the unguessed letters masked.
        std::string masked_str(void) const;
        /// Receives a guess letter from the player and return true if that guess is correct, false otherwise.
        bool guess(char g);
        /// Return the number of **wrong** guesses so far in the match.
        size_t wrong_guesses(void) const;
        /// Return the number of **correct** guesses so far in the match.
        size_t correct_guesses(void) const;
        /// Return the list of wrong guesses.
        std::vector<char> wrong_guesses_list(void) const;
        /// Return the number of masked lettes in the secret word.
        short n_masked_ch(void) const;
        /// Return the mask char we've chosen.
        char mask_char(void) const;
        /// Returns the secret word.
        std::string operator()(void) const;
        /// Reset the object to its original state and mask the secret word.
        void reset(void);
};

#endif
