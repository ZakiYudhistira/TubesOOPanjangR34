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

    vector<Player*> player_list;
    Player* current_player;
    int current = 0;

public:
    Main(){
        // input
        FileHandler file_scan;
        try{
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

    int indexOf(vector<string> strings, string name){
        int idx = -1;
        for (int i = 0; i < (int)strings.size(); i++)
        {
            if (strings[i] == name)
            {
                idx = i;
            }
        }
        return idx;
    }

    void insertSorted(vector<string> &strings, string name)
    {
        strings.push_back(name);
        std::sort(strings.begin(), strings.end());
    }

    void insertPlayer(vector<Player> &list_of_player, vector<string> &player_leksikografis, Player new_player)
    {
        /*Memasukan nama player ke dalam player_queue sesuai urutan*/
        insertSorted(player_leksikografis, new_player.getName());
        /*Mencari index urutan dari player secara leksikografis (urutan nama)*/
        int idx = indexOf(player_leksikografis, new_player.getName());
        /*Memasukkan player ke dalam list_of_player sesuai index ururtan leksikografiknya*/
        list_of_player.insert(list_of_player.begin() + idx, new_player);
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
        std::cout << "Input nama petani : ";
        getline(std::cin, petani);
        std::cout << "Input nama peternak : ";
        getline(std::cin, peternak);

        /*Inisialisasi list leksikografis*/
        // vector<string> player_leksikografis;
        // insertSorted(player_leksikografis, walikota);
        // insertSorted(player_leksikografis, petani);
        // insertSorted(player_leksikografis, peternak);
        // for (int i = 0; i < (int)player_leksikografis.size(); i++)
        // {
        //     player_list.push_back(Player(player_leksikografis[i], 40, 50));
        // }

        // for (int i = 0; i < (int)player_leksikografis.size(); i++)
        // {
        //     std::cout << player_leksikografis[i] << "\n";
        // }

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

int main(){
    Main m;

    m.main();

    return 0;
}
