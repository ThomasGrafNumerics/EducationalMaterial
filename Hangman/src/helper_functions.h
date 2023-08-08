#pragma once
#include <cassert>
#include <cctype>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

std::string random_word (const std::filesystem::path &p);
std::string to_upper (const std::string &word);
