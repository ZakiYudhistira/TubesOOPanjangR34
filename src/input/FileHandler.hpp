#ifndef __FILE_HANDLER__
#define __FILE_HANDLER__

#include <fstream>
#include <iostream>
#include <filesystem>

#include "InputHandler.hpp"
#include "GameConfig/GameConfig.hpp"
#include "Exception/Exception.hpp"

class FileHandler: public InputHandler {
    private:

    public:
        FileHandler();

        void readFile(std::string, GameConfig&);
};
#endif