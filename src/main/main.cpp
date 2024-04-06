#include <iostream>
#include "pcolor/pcolor.hpp"
#include "input/InputHandler.hpp"
#include "input/FileHandler.hpp"
#include "Config/GameConfig.hpp"
#include "Config/AnimalConfig.hpp"
#include "Config/PlantConfig.hpp"
#include "Config/ProductConfig.hpp"
#include "Config/RecipeConfig.hpp"

class Main{
    private:
        GameConfig game_config;
        AnimalConfig animal_config;
        PlantConfig plant_config;
        ProductConfig product_config;
        RecipeConfig recipe_config;

    public:
        Main(){
            // input
            FileHandler file_scan;
            try {
                file_scan.readFile("../../test/Input/misc.txt", game_config);
                file_scan.readFile("../../test/Input/animal.txt", animal_config);
                file_scan.readFile("../../test/Input/plant.txt", plant_config);
                file_scan.readFile("../../test/Input/product.txt", product_config);
                file_scan.readFile("../../test/Input/recipe.txt", recipe_config);
            }
            catch (const Exception& e){
                cout << e.what() << '\n';
            }
        }

        void main(){
            /*MULAI PERMAINAN*/
            std::cout << game_config;
            std::cout << animal_config;
            std::cout << plant_config;
            std::cout << product_config;
            std::cout << recipe_config;
        }
};

int main(){
    Main m;

    m.main();

    return 0;
}

