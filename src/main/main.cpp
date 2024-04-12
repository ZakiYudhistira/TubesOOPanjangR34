#include <iostream>
#include <algorithm>
#include <string>

#include "pcolor/pcolor.hpp"

#include "Exception/Exception.hpp"

#include "input/InputHandler.hpp"
#include "input/FileHandler.hpp"

#include "Config/GameConfig.hpp"
#include "Config/AnimalConfig.hpp"
#include "Config/PlantConfig.hpp"
#include "Config/ProductConfig.hpp"
#include "Config/RecipeConfig.hpp"

#include "Player/Player.hpp"
#include "Player/Petani/Petani.hpp"
#include "Player/Peternak/Peternak.hpp"
#include "Player/Walikota/Walikota.hpp"

#include "Matrix2/Matrix2.hpp"
#include "Matrix/Matrix.hpp"
#include "Matrix/Farm.hpp"
#include "Matrix/Field.hpp"

#include "Toko/Toko.hpp"

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

    FileHandler file_scan;
public:
    Main()
    {
        // input
        try
        {
            file_scan.readFile("test/input/misc.txt", game_config);
            file_scan.readFile("test/input/animal.txt", animal_config);
            file_scan.readFile("test/input/plant.txt", plant_config);
            file_scan.readFile("test/input/product.txt", product_config);
            file_scan.readFile("test/input/recipe.txt", recipe_config);

            // initiate TOKO
            toko_cina = *(new Toko(animal_config, plant_config, product_config, recipe_config));
        }
        catch (const Exception &e)
        {
            cout << e.what() << '\n';
        }
    }

    void insertPlayer(Player *new_player)
    {
        this->player_list.push_back(new_player);
        std::sort(this->player_list.begin(), this->player_list.end(), [](Player *lhs, Player *rhs)
                  { return lhs->getName() < rhs->getName(); });
    }

    void main()
    {
        /* TESTING READING ALL CONFIG GILES */
        std::cout << game_config;
        std::cout << animal_config;
        std::cout << plant_config;
        std::cout << product_config;
        std::cout << recipe_config;


        /*INITIALIZATION (jika new game)*/
        this->gameMode();

        if(this->isMuat){
            // testing kalau MUAT
            try {
                file_scan.readFile("test/data/state.txt", player_list, animal_config, plant_config, product_config, recipe_config, game_config, toko_cina);
            
                for(int i=0; i<(int)player_list.size(); i++){
                    std::cout << *player_list[i] << std::endl;
                }
            } 
            catch (const Exception &e)
            {
                std::cout << e.what() << '\n';
            }

            /* TESTING SIMPAN */
            file_scan.writeFile("folder1/folder2/folder3/hasil-simpan.txt", player_list, animal_config, plant_config, product_config, recipe_config, game_config, toko_cina);
        } else {
            int inventory_row = game_config.getInventoryRow();
            int inventory_col = game_config.getInventoryCol();
            int field_row = game_config.getFieldRow();
            int field_col = game_config.getFieldCol();
            int pen_row = game_config.getPenRow();
            int pen_col = game_config.getPenCol();

            string walikota, petani, peternak;
            std::cout << "Input nama walikota : ";
            getline(std::cin, walikota);
            Player *ptr_walikota = new Walikota(walikota, 40, 50, inventory_row, inventory_col);
            insertPlayer(ptr_walikota);
            std::cout << "Input nama petani : ";
            getline(std::cin, petani);
            Player *ptr_petani = new Petani(petani, 40, 50, inventory_row, inventory_col, field_row, field_col);
            insertPlayer(ptr_petani);
            std::cout << "Input nama peternak : ";
            getline(std::cin, peternak);
            Player *ptr_peternak = new Peternak(peternak, 40, 50, inventory_row, inventory_col, pen_row, pen_col);
            insertPlayer(ptr_peternak);

            for (int i = 0; i < (int)player_list.size(); i++){
                std::cout << player_list[i]->getName() << "\n";
                player_list[i]->printInventory();
            }
        }

        /* TESTING TOKO CINA - (-1000) artinya unlimited*/
        std::cout << toko_cina;

        int current_player_idx = 0;
        while(true){
            player_list[current_player_idx]->currentTurn();
            current_player_idx++;
            if(current_player_idx == (int)player_list.size()){
                current_player_idx = 0;
            }
        }
    }

    void gameMode(){
        string input_c;
        while(input_c != "Y" && input_c != "N"){
            std::cout << "Apakah anda ingin memuat atau tidak? (Y / N)\n> ";
            getline(std::cin, input_c);

            if(input_c == "Y"){
                this->isMuat = true;
            }  else if(input_c == "N"){
                this->isMuat = false;
            } else {
                std::cout << "Invalid Input Type\n";
            }
        }
    }
};

int main()
{
    Main m;

    m.main();

    return 0;
}
