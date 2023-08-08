#pragma once
#include "helper_functions.h"
#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cstddef>
#include <filesystem>
#include <iostream>
#include <set>
#include <string>
#include <vector>

class Hangman
{
public:
  // "ordinary constructor": create an object
  Hangman (const std::string);

  // default constructor
  Hangman ();

  // explicitly prevent compiler from creating copy constructor
  Hangman (const Hangman &) = delete;

  // explicitly prevent compiler from creating move constructor
  Hangman (Hangman &&) = delete;

  // explicitly prevent compiler from creating copy assignment
  Hangman &operator= (const Hangman &) = delete;

  // explicitly prevent compiler from creating move assignment
  Hangman &operator= (Hangman &&) = delete;

  // explicitly make compiler create default destructor
  ~Hangman () = default;

  void handle_guess (const char);

  void update_state ();

  void play ();

private:
  const std::string answer;
  std::string state = "";
  std::string guessed_letters{ "" };
  bool solved{ false };
  unsigned int failed_tries{ 0 };
  const std::array<std::string, 7> gallows{

    "    +---+\n"
    "    |   |\n"
    "        |\n"
    "        |\n"
    "        |\n"
    "        |\n"
    "   =========\n",
    "    +---+\n"
    "    |   |\n"
    "    O   |\n"
    "        |\n"
    "        |\n"
    "        |\n"
    "   =========\n",
    "    +---+\n"
    "    |   |\n"
    "    O   |\n"
    "    |   |\n"
    "        |\n"
    "        |\n"
    "   =========\n",
    "    +---+\n"
    "    |   |\n"
    "    O   |\n"
    "   /|   |\n"
    "        |\n"
    "        |\n"
    "   =========\n",
    "    +---+\n"

    "    |   |\n"
    "    O   |\n"
    "   /|\\  |\n"
    "        |\n"
    "        |\n"
    "   =========\n",
    "    +---+\n"
    "    |   |\n"
    "    O   |\n"
    "   /|\\  |\n"
    "   /    |\n"
    "        |\n"
    "   =========\n",
    "    +---+\n"
    "    |   |\n"
    "    O   |\n"
    "   /|\\  |\n"
    "   / \\  |\n"
    "        |\n"
    "========="
  };
};
