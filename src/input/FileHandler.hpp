#ifndef __FILE_HANDLER__
#define __FILE_HANDLER__

#include <fstream>
#include <iostream>
#include <filesystem>
#include <sstream>

#include "InputHandler.hpp"

#include "Config/GameConfig.hpp"
#include "Config/AnimalConfig.hpp"
#include "Config/PlantConfig.hpp"
#include "Config/ProductConfig.hpp"
#include "Config/RecipeConfig.hpp"

#include "Animal/Herbivore.hpp"
#include "Animal/Carnivore.hpp"
#include "Animal/Omnivore.hpp"

#include "Plant/Plant.hpp"
#include "Plant/FruitPlant.hpp"
#include "Plant/MaterialPlant.hpp"

#include "Product/Product.hpp"
#include "Product/FoodProduct.hpp"
#include "Product/MaterialProduct.hpp"

#include "Building/Building.hpp"

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

        void readFile(std::string fn, AnimalConfig& ac);

        void readFile(std::string fn, PlantConfig& pc);

        void readFile(std::string fn, ProductConfig& pc);

        void readFile(std::string fn, RecipeConfig& rc);
};
#endif