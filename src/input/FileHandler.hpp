#ifndef __FILE_HANDLER__
#define __FILE_HANDLER__

#include <fstream>
#include <iostream>
#include <filesystem>
#include <sstream>

#include "InputHandler.hpp"
#include "GameConfig/GameConfig.hpp"
#include "Exception/Exception.hpp"

class FileHandler: public InputHandler {
    private:

    public:
        FileHandler();

        /*
        * Function to read file
        * @param fn filename 
        * @param gc GameConfig object
        */
        void readFile(std::string fn, GameConfig& gc);
};
#endif