#include <iostream>

#include "parseArgs.h"
//#include "database.h"
//#include "moveFile.h"

#include <string>
#include <iostream>




int main(int argc, char* argv[]){
    //Parse command line arguments
    parse(argc, argv);
    std::cout << "Program ended\n";
    return 0;
}