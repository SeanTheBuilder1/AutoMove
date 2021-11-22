#ifndef MOVE_FILE
#define MOVE_FILE

#include <cstdio>
#include <cstring>
#include <cerrno>
#include <iostream>
#include <fstream>

bool moveFile(const std::string& oldPath, const std::string& newPath, bool overwrite = false);

#endif //MOVE_FILE