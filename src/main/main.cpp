#include <iostream>
#include "pcolor/pcolor.hpp"
#include "input/InputHandler.hpp"
#include "input/FileHandler.hpp"
#include "GameConfig/GameConfig.hpp"

class Main{
    private:
        GameConfig game_config;
    
    public:
        Main(){
            // input
            FileHandler file_scan;
            try {
                file_scan.readFile("../../test/Input/misc.txt", game_config);
            }
            catch (const Exception& e){
                cout << e.what() << '\n';
            }
        }

        void main(){
            std::cout << game_config << endl;
        }
};

int main(){
    Main m;

    m.main();
    std::cout << "hello world" << std::endl;

    return 0;
}

