#include "moveFile.h"

bool moveFile(const std::string& oldPath, const std::string& newPath, bool overwrite){
    if(overwrite){
        std::ifstream f(oldPath.c_str());
        if(f.good()){
            f.close();
            std::remove(newPath.c_str());
            if(std::rename(oldPath.c_str(), newPath.c_str()) < 0) {
                std::cout << strerror(errno) << '\n';
                return false;
            }
        }
        else{
            std::cout << "File does not exist\n";
        }
    }
    else{
        if(std::rename(oldPath.c_str(), newPath.c_str()) < 0) {
            std::cout << strerror(errno) << '\n';
            return false;
        }
    }
    return true;
}