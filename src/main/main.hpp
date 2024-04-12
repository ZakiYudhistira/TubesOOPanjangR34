#ifndef MAIN_CLASS
#define MAIN_CLASS

#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <sys/stat.h>
#include <algorithm>
#include <string>

#include "pcolor/pcolor.hpp"

#include "Config/GameConfig.hpp"
#include "Config/AnimalConfig.hpp"
#include "Config/PlantConfig.hpp"
#include "Config/ProductConfig.hpp"
#include "Config/RecipeConfig.hpp"

#include "GameObject/Animal/Herbivore/Herbivore.hpp"
#include "GameObject/Animal/Carnivore/Carnivore.hpp"
#include "GameObject/Animal/Omnivore/Omnivore.hpp"

#include "GameObject/Plant/Plant.hpp"
#include "GameObject/Plant/FruitPlant/FruitPlant.hpp"
#include "GameObject/Plant/MaterialPlant/MaterialPlant.hpp"

#include "GameObject/Product/Product.hpp"
#include "GameObject/Product/FoodProduct/FoodProduct.hpp"
#include "GameObject/Product/MaterialProduct/MaterialProduct.hpp"

#include "GameObject/Building/Building.hpp"

#include "Player/Player.hpp"
#include "Player/Petani/Petani.hpp"
#include "Player/Peternak/Peternak.hpp"
#include "Player/Walikota/Walikota.hpp"

#include "Matrix/Matrix.hpp"
#include "Matrix/Farm.hpp"
#include "Matrix/Field.hpp"

#include "Toko/Toko.hpp"

#include "Exception/Exception.hpp"

namespace fs = std::filesystem;

using namespace std;



class Main
{
private:
    GameConfig game_config;
    AnimalConfig animal_config;
    PlantConfig plant_config;
    ProductConfig product_config;
    RecipeConfig recipe_config;

    Toko toko_cina;

    vector<Player*> player_list;
    int current = 0;

    bool isMuat;

public:
    Main();

    void insertPlayer(Player *new_player);

    void main();

    void gameMode();

    /* FILE HANDLING FUNCTIONS */

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

    void readFile(std::string fn, vector<Player*>& vp, AnimalConfig& ac, PlantConfig& pc, ProductConfig& prod, RecipeConfig& rc, GameConfig& gc, Toko& t);

    void writeFile(std::string fn, vector<Player*>& vp, AnimalConfig& ac, PlantConfig& pc, ProductConfig& prod, RecipeConfig& rc, GameConfig& gc, Toko& t);
};



#endif