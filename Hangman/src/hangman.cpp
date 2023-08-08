#include "hangman.h"
#include "helper_functions.h"
#include <cctype>
#include <string>

Hangman::Hangman (const std::string a) : answer{ to_upper (a) } {}

Hangman::Hangman ()
    : answer{ to_upper (random_word ("helvetismen_ascii.txt")) }
{
}

void
Hangman::handle_guess (const char guess)
{
  if (guessed_letters.find (guess) != std::string::npos)
    {

      std::cout << "You have already tried the letter " << guess
                << ". Pick a different letter." << std::endl;
    }
  else
    {
      guessed_letters += guess;
      if (answer.find (guess) != std::string::npos)
        {
          std::cout << "The letter " << guess << " is in the word!";
        }
      else
        {
          ++failed_tries;
          std::cout << "Sadly, the letter " << guess << " is not in the word!"
                    << std::endl;
          std::cout << gallows.at (failed_tries) << std::endl;
        }
    }
}

void
Hangman::update_state ()
{
  state = "";
  for (const char c : answer)
    {
      if (guessed_letters.find (c) != std::string::npos)
        {
          state += c;
        }
      else
        {
          state += "_";
        }
    }
  std::cout << "\n" << state << std::endl;
}

void
Hangman::play ()
{
  update_state ();
  std::cout << "Let's play a friendly game of hangman!" << std::endl;
  char guess;
  std::cout << gallows.at (failed_tries) << std::endl;

  while (!solved && failed_tries < gallows.size () - 1)
    {
      std::cout << "What is your guess: " << std::endl;
      std::cin >> guess;
      guess = std::toupper (guess);
      handle_guess (guess);
      update_state ();
      solved = (state == answer);
    }

  if (solved)
    {
      std::cout << "You found the answer!" << std::endl;
    }
  else
    {
      std::cout << "Sorry! The correct answer would have been: " << answer
                << std::endl;
    }
}
