#include "parseArgs.h"



void parse(int argc, char* argv[]){
    bool preLoaded = false;
    Data& database = dataGet();
    Auditor& auditor = getAuditor();

    bool overwrite = false;
    bool keep = false;
    char path[MAX_PATH];
    GetModuleFileNameA(NULL, path, MAX_PATH);
    std::cout << strlen(path);
    std::cout << path << '\n';
    long nameLen = strlen(argv[0] + 2);
    // if (path != NULL){
    //     const unsigned int length = strlen(path);
    //     path[length-nameLen] = '\0';
    // }
    
    for(long i = strlen(path); i >= 0; --i){
        if(path[i] == '\\' || path[i] == '/') break;
        else{
            if (path != NULL){
                path[i] = '\0';
            }
        }
    }
    
    try{
        std::cout << path << '\n';
        auditor.openDatabase(std::string(path).append("paths.txt"));
    }
    catch(const char* e){
        std::cout << e << '\n';
    }

    std::string destination{};

    int j = 0;
    //Check for overwrite flags
    for(long i = 1; i < argc; ++i){
        if(strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "-overwrite") == 0)
            overwrite = true;
        if(strcmp(argv[i], "-k") == 0 || strcmp(argv[i], "-keep") == 0)
            keep = true;
    }

    //Set default setting if none given
    if((!overwrite) && (!keep))
        keep = true;
    
    //Error if both keep and overwrite
    assert((!(overwrite && keep)));
    

    for(long i = 1; i < argc; ++i){
        //Pauser
        if(j > 0){
            j = j - 1;
            continue;
        }
        std::cout << argv[i] << '\n';
        if(strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "-des") == 0 || strcmp(argv[i], "-destination") == 0){
            //Check if argument actually exists
            assert(argv[i + 1] != NULL);
            //Check if digit

            //Pause parsing for 2 arguments
            j = j + 1;
            //Replace line's content with given string
            Item* destIndex; 
            auditor.openItem(argv[i + 1]);
            auditor.getItem(argv[i + 1], destIndex);
            std::deque<std::string>* path;
            destIndex->getContents(path);
            destination = path->at(0);
        }
        else if(strcmp(argv[i], "-n") == 0){
            //Check if argument actually exists
            assert(argv[i + 2] != NULL);
            //Check if digit
            assert(slib::isDigit(std::string(argv[i + 1])));
            std::cout << "Putting \"" << argv[i + 2] << "\" on line " << argv[i + 1] << "\n";
            //Pause parsing for 2 arguments
            j = j + 2;
            int x = atoi(argv[i + 1]);
            assert(x > 0);
            //Replace line's content with given string
            database.saveAlgo(x, std::string(argv[i+2]));
        }
        else if(strcmp(argv[i], "-addpath") == 0){
            assert(argv[i + 2] != NULL);
            Item temp{argv[i + 1]};
            j = j + 2;
            std::deque<std::string>* content;
            if(temp.getContents(content)){
                content->emplace_back(std::string(argv[i + 2]));
            }
            auditor.addItem(temp);
        }
        else if(strcmp(argv[i], "-delpath") == 0){
            assert(argv[i + 1] != NULL);
            auditor.delItem(std::string(argv[i + 1]));
        }
        else if(!destination.empty()){
            std::deque<char> fileName;
            std::string file(argv[i]);
            for(long k = file.size(); k >= 0; --k){
                if(file[k] == '\\' || file[k] == '/') break;
                else{
                    fileName.emplace_front(file[k]);
                    //argv[i][k] = '\0';
                }
            }

            for(auto& k : fileName){
                std::cout << k;
            }
            moveFile(argv[i], std::string(destination) + (std::string(fileName.begin(), fileName.end())), overwrite);
        }
    }
}


