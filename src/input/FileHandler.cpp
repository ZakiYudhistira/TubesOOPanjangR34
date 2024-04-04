#include "FileHandler.hpp"

FileHandler::FileHandler(){
    
}

/*
 * debugging function - ga perlu tahu
 *
*/
void check_active_dir(){
    namespace fs = std::filesystem;
    std::string path = "./";
    for (const auto & entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;
}

void FileHandler::readFile(std::string file_name, GameConfig& gc){
    std::cout << file_name << '\n';

    std::ifstream my_file(file_name);
    std::string my_string;

    if(!my_file){
        // if file does not exist
        ExceptionFileNotFound e;
        throw e;
    }

    while(std::getline(my_file, my_string)){
        std::cout << my_string << '\n';
    }
    
    // TODO: mulai string parsing
    gc.field_col = 0;
}