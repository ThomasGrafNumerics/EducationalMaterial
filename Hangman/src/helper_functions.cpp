#include "helper_functions.h"

std::string
random_word (const std::filesystem::path &p)
{

  assert (std::filesystem::exists (p));
  std::ifstream file{ p };
  std::string line;

  std::vector<std::string> words;

  while (std::getline (file, line))
    {
      words.push_back (line);
    }
  file.close ();

  // use system time to get different seeds for "rand"
  srand ((unsigned)time (NULL));
  std::string word{ words.at (rand () % words.size ()) };
  word.pop_back ();
  return word;
}

std::string
to_upper (const std::string &word)
{
  std::string upper;
  for (const char c : word)
    {
      upper += std::toupper (c);
    }
  return upper;
}
