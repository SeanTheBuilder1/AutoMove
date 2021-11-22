#ifndef SEARCHER
#define SEARCHER

#include <vector>
#include <string>
#include <tuple>

#include "database.h"
#include "auditor.h"

std::vector<std::string> searchItem(const std::string& keyword);
std::vector<std::string> searchItemPreload(const std::string& keyword);
std::tuple<long, long> getDatabaseIndex(Item& item);

#endif //SEARCHER