#ifndef FILE_HANDLER
#define FILE_HANDLER

#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
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

#include "Player/Player.hpp"
#include "Player/Walikota.hpp"
#include "Player/Peternak.hpp"
#include "Player/Petani.hpp"

#include "Matrix/Matrix.hpp"

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

        void readFile(std::string fn, vector<Player*>& vp, AnimalConfig& ac, PlantConfig& pc, ProductConfig& prod, RecipeConfig& rc, GameConfig& gc);
};
#endif