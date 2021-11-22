#ifndef SLIB
#define SLIB

#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <deque>

namespace slib{
    bool isDigit(const std::string& word);
    bool isDigit(std::string_view view);
    std::vector<std::string> loadTxt(const std::string& filename);
    std::string removeSpace(const std::string& str);
    bool fullOfSpace(const std::string& str);
    std::deque<std::string> split_string_by_newline(const std::string& str);
}

#endif // SLIB