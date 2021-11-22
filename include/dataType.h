#ifndef DATATYPE
#define DATATYPE

#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <functional>

#include "database.h"



class Item{
private:
    std::deque<std::string> contents;
    std::string index;
public:
    Item(std::string i):index(i){};
    Item(Item&& item):contents(std::move(item.contents)), index(std::move(item.index)){};
    Item(Item& item):contents((item.contents)), index((item.index)){};
    Item& operator=(Item&& item) noexcept{
        contents = std::move(item.contents);
        index = std::move(item.index);
        return *this;
    }
    bool readItem(std::string index);
    bool getContents(std::deque<std::string>*& data);
    void editItem(long index, const std::string& replacement);
    void sort();
    void sort(std::function<bool(std::string, std::string)>);
    void sort(std::deque<std::string>::iterator x, std::deque<std::string>::iterator y);
    void sort(std::deque<std::string>::iterator x, std::deque<std::string>::iterator y, std::function<bool(std::string, std::string)> func);
    std::string getIndex() const;
};

bool operator>(const Item& x, const Item& y);
bool operator<(const Item& x, const Item& y);
bool operator==(const Item& x, const Item& y);
bool operator>=(const Item& x, const Item& y);
bool operator<=(const Item& x, const Item& y);
bool operator!=(const Item& x, const Item& y);



#endif //DATATYPE