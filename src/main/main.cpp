#include <iostream>
#include <algorithm>
#include <string>

#include "pcolor/pcolor.hpp"

#include "Exception/Exception.hpp"

#include "input/InputHandler.hpp"
#include "input/FileHandler.hpp" //---

#include "Config/GameConfig.hpp"
#include "Config/AnimalConfig.hpp"
#include "Config/PlantConfig.hpp"
#include "Config/ProductConfig.hpp"
#include "Config/RecipeConfig.hpp"

#include "Player/Player.hpp" //---
#include "Player/Petani.hpp"
#include "Player/Peternak.hpp"
#include "Player/Walikota.hpp"

class Main
{
private:
    GameConfig game_config;
    AnimalConfig animal_config;
    PlantConfig plant_config;
    ProductConfig product_config;
    RecipeConfig recipe_config;

    vector<Player *> player_list;
    Player *current_player;
    int current = 0;

public:
    Main()
    {
        // input
        FileHandler file_scan;
        try
        {
            file_scan.readFile("test/input/misc.txt", game_config);
            file_scan.readFile("test/input/animal.txt", animal_config);
            file_scan.readFile("test/input/plant.txt", plant_config);
            file_scan.readFile("test/input/product.txt", product_config);
            file_scan.readFile("test/input/recipe.txt", recipe_config);

            // testing kalau MUAT
            file_scan.readFile("test/data/state.txt", player_list);
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
        /*Mulai Permainan*/
        std::cout << game_config;
        std::cout << animal_config;
        std::cout << plant_config;
        std::cout << product_config;
        std::cout << recipe_config;

        /*Initialiazation (jika new game)*/

        string walikota, petani, peternak;
        std::cout << "Input nama walikota : ";
        getline(std::cin, walikota);
        Player *ptr_walikota = new Player(walikota, 40, 50);
        insertPlayer(ptr_walikota);
        std::cout << "Input nama petani : ";
        getline(std::cin, petani);
        Player *ptr_petani = new Player(petani, 40, 50);
        insertPlayer(ptr_petani);
        std::cout << "Input nama peternak : ";
        getline(std::cin, peternak);
        Player *ptr_peternak = new Player(peternak, 40, 50);
        insertPlayer(ptr_peternak);

        /*Inisialisasi list leksikografis*/
        // vector<string> player_leksikografis;
        // insertSorted(player_leksikografis, walikota);
        // insertSorted(player_leksikografis, petani);
        // insertSorted(player_leksikografis, peternak);
        // for (int i = 0; i < (int)player_leksikografis.size(); i++)
        // {
        //     player_list.push_back(Player(player_leksikografis[i], 40, 50));
        // }

        for (int i = 0; i < (int)player_list.size(); i++)
        {
            std::cout << player_list[i]->getName() << "\n";
        }

        /*Current player*/

        // *current_player = player_list[current];

        /*Alur command current_player*/
        // while (true)
        // {
        //     try
        //     {
        //         /*Alur Command*/
        //     }
        //     catch (const Exception &e)
        //     {
        //         cout << e.what() << '\n';
        //     }
        // }
    }
};

int main()
{
    Main m;

    m.main();

    return 0;
}
