#include "main.hpp"

/* BAGIAN DEFINISI FUNGSI CLASS MAIN */

Main::Main()
{
    // input
    try
    {
        readFile("test/input/misc.txt", game_config);
        readFile("test/input/animal.txt", animal_config);
        readFile("test/input/plant.txt", plant_config);
        readFile("test/input/product.txt", product_config);
        readFile("test/input/recipe.txt", recipe_config);

        // initiate TOKO
        toko_cina = *(new Toko(animal_config, plant_config, product_config, recipe_config));
    }
    catch (const Exception &e)
    {
        cout << e.what() << '\n';
    }
}

void Main::insertPlayer(Player *new_player)
{
    this->player_list.push_back(new_player);
    sort(this->player_list.begin(), this->player_list.end(), [](Player *lhs, Player *rhs)
         { return lhs->getName() < rhs->getName(); });
}

void Main::main()
{
    /* TESTING READING ALL CONFIG GILES */
    cout << game_config;
    cout << animal_config;
    cout << plant_config;
    cout << product_config;
    cout << recipe_config;

    /*INITIALIZATION (jika new game)*/
    this->gameMode();

    if (this->isMuat)
    {
        // testing kalau MUAT
        try
        {
            readFile("test/data/state.txt", player_list, animal_config, plant_config, product_config, recipe_config, game_config, toko_cina);

            for (int i = 0; i < (int)player_list.size(); i++)
            {
                cout << *player_list[i] << endl;
            }
        }
        catch (const Exception &e)
        {
            cout << e.what() << '\n';
        }
    }
    else
    {
        int inventory_row = game_config.getInventoryRow();
        int inventory_col = game_config.getInventoryCol();
        int field_row = game_config.getFieldRow();
        int field_col = game_config.getFieldCol();
        int pen_row = game_config.getPenRow();
        int pen_col = game_config.getPenCol();

        string walikota, petani, peternak;
        cout << "Input nama walikota : ";
        getline(cin, walikota);
        Player *ptr_walikota = new Walikota(walikota, 40, 50, inventory_row, inventory_col);
        insertPlayer(ptr_walikota);
        cout << "Input nama petani : ";
        getline(cin, petani);
        Player *ptr_petani = new Petani(petani, 40, 50, inventory_row, inventory_col, field_row, field_col);
        insertPlayer(ptr_petani);
        cout << "Input nama peternak : ";
        getline(cin, peternak);
        Player *ptr_peternak = new Peternak(peternak, 40, 50, inventory_row, inventory_col, pen_row, pen_col);
        insertPlayer(ptr_peternak);

        for (int i = 0; i < (int)player_list.size(); i++)
        {
            cout << player_list[i]->getName() << "\n";
            player_list[i]->printInventory();
        }
    }

    /* TESTING TOKO CINA - (-1000) artinya unlimited*/
    cout << toko_cina;

    int current_player_idx = 0;
    while (true)
    {
        // print banner giliran pemain saat ini
        player_list[current_player_idx]->printCurrentTurn();

        // nerima perintah
        string command;

        while (command != "NEXT")
        {
            try
            {
                cout << "> ";
                cin >> command;
                if (command == "SIMPAN")
                {
                    /* TESTING SIMPAN */
                    string filepath;
                    cout << "Masukkan filepath : ";
                    cin >> filepath;
                    writeFile(filepath, player_list, animal_config, plant_config, product_config, recipe_config, game_config, toko_cina);
                }
                else
                {
                    player_list[current_player_idx]->currentTurn(command);
                }
            }
            catch (const Exception &e)
            {
                cout << e.what() << endl;
            }
        }

        cout << "Giliran dilanjutkan ke pemain berikutnya.\n";

        current_player_idx += 1 % ((int)player_list.size() - 1);
        // if (current_player_idx == (int)player_list.size())
        // {
        //     current_player_idx = 0;
        // }
    }
}

void Main::gameMode()
{
    string input_c;
    while (input_c != "Y" && input_c != "N")
    {
        cout << "Apakah anda ingin memuat atau tidak? (Y / N)\n> ";
        getline(cin, input_c);

        if (input_c == "Y")
        {
            this->isMuat = true;
        }
        else if (input_c == "N")
        {
            this->isMuat = false;
        }
        else
        {
            cout << "Invalid Input Type\n";
        }
    }
}

/* BAGIAN FILE HANDLING */

/*
 * debugging function - ga perlu tahu
 *
 */
void check_active_dir()
{
    namespace fs = std::filesystem;
    std::string path = "./";
    for (const auto &entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;
}

void Main::readFile(std::string file_name, GameConfig &gc)
{
    std::ifstream my_file(file_name);
    std::string my_string;

    if (!my_file)
    {
        // if file does not exist
        ExceptionFileNotFound e;
        throw e;
    }

    std::string file_content = "";
    while (std::getline(my_file, my_string))
    {
        // string cleeaning
        my_string.erase(my_string.find('\r'));

        file_content.append(my_string);
        file_content.append(" ");
    }

    int weight_to_win;
    int gulden_to_win;
    int inventory_row;
    int inventory_col;
    int pen_row;
    int pen_col;
    int field_row;
    int field_col;

    stringstream s(file_content);

    s >> weight_to_win >> gulden_to_win >> inventory_row >> inventory_col >> pen_row >> pen_col >> field_row >> field_col;

    GameConfig new_gc(weight_to_win, gulden_to_win, inventory_row, inventory_col,
                      pen_row, pen_col, field_row, field_col);

    gc = new_gc;

    // close file stream
    my_file.close();
}

void Main::readFile(std::string file_name, AnimalConfig &ac)
{
    std::ifstream my_file(file_name);
    std::string my_string;

    if (!my_file)
    {
        // if file does not exist
        ExceptionFileNotFound e;
        throw e;
    }

    std::string file_content = "";
    while (std::getline(my_file, my_string))
    {
        // string cleeaning
        my_string.erase(my_string.find('\r'));

        file_content.append(my_string);
        file_content.append(" ");
    }

    stringstream s(file_content);

    int id;
    string code;
    string name;
    string type;
    int weight_to_harvest;
    int price;

    while (s >> id >> code >> name >> type >> weight_to_harvest >> price)
    {
        Animal *temp_animal;
        if (type == "HERBIVORE")
        {
            Herbivore *herbivore = new Herbivore(id, code, name, type, price, weight_to_harvest);
            temp_animal = herbivore;
        }
        else if (type == "CARNIVORE")
        {
            Carnivore *carnivore = new Carnivore(id, code, name, type, price, weight_to_harvest);
            temp_animal = carnivore;
        }
        else if (type == "OMNIVORE")
        {
            Omnivore *omnivore = new Omnivore(id, code, name, type, price, weight_to_harvest);
            temp_animal = omnivore;
        }

        ac.addAnimal(temp_animal);
    }

    // close file stream
    my_file.close();
}

void Main::readFile(std::string file_name, PlantConfig &pc)
{
    std::ifstream my_file(file_name);
    std::string my_string;

    if (!my_file)
    {
        // if file does not exist
        ExceptionFileNotFound e;
        throw e;
    }

    std::string file_content = "";
    while (std::getline(my_file, my_string))
    {
        // string cleeaning
        my_string.erase(my_string.find('\r'));

        file_content.append(my_string);
        file_content.append(" ");
    }

    stringstream s(file_content);

    int id;
    string code;
    string name;
    string type;
    int duration_to_harvest;
    int price;

    while (s >> id >> code >> name >> type >> duration_to_harvest >> price)
    {
        Plant *temp_plant;
        if (type == "MATERIAL_PLANT")
        {
            MaterialPlant *material_plant = new MaterialPlant(id, code, name, type, price, duration_to_harvest);
            temp_plant = material_plant;
        }
        else if (type == "FRUIT_PLANT")
        {
            FruitPlant *fruit_plant = new FruitPlant(id, code, name, type, price, duration_to_harvest);
            temp_plant = fruit_plant;
        }

        pc.addPlant(temp_plant);
    }

    // close file stream
    my_file.close();
}

void Main::readFile(std::string file_name, ProductConfig &pc)
{
    std::ifstream my_file(file_name);
    std::string my_string;

    if (!my_file)
    {
        // if file does not exist
        ExceptionFileNotFound e;
        throw e;
    }

    std::string file_content = "";
    while (std::getline(my_file, my_string))
    {
        // string cleeaning
        my_string.erase(my_string.find('\r'));

        file_content.append(my_string);
        file_content.append(" ");
    }

    stringstream s(file_content);

    int id;
    string code;
    string name;
    string type;
    int added_weight;
    string origin;
    int price;

    while (s >> id >> code >> name >> type >> origin >> added_weight >> price)
    {
        Product *temp_product;
        if (added_weight == 0)
        {
            MaterialProduct *material_product = new MaterialProduct(id, code, name, price, added_weight, origin, "MATERIAL_PRODUCT");
            temp_product = material_product;
        }
        else
        {
            FoodProduct *food_product = new FoodProduct(id, code, name, price, added_weight, origin, "FOOD_PRODUCT");
            temp_product = food_product;
        }

        pc.addProduct(temp_product);
    }

    // close file stream
    my_file.close();
}

void Main::readFile(std::string file_name, RecipeConfig &rc)
{
    std::ifstream my_file(file_name);
    std::string my_string;

    if (!my_file)
    {
        // if file does not exist
        ExceptionFileNotFound e;
        throw e;
    }

    std::string file_content = "";
    while (std::getline(my_file, my_string))
    {
        // string cleeaning
        my_string.erase(my_string.find('\r'));

        file_content.append(my_string);
        file_content.append(" | -123456 ");
    }

    stringstream s(file_content);

    int id;
    string code;
    string name;
    int price;

    while (s >> id >> code >> name >> price)
    {
        Building *temp_building = new Building(id, code, name, price);

        string temp_val1;
        int temp_val2;
        while (s >> temp_val1 >> temp_val2)
        {
            if (temp_val1 == "|" && temp_val2 == -123456)
                break;

            pair<string, int> material_pair;
            material_pair.first = temp_val1;
            material_pair.second = temp_val2;

            temp_building->addMaterial(material_pair);
        }

        rc.addRecipe(temp_building);
    }

    // closing file stream
    my_file.close();
}

void Main::readFile(std::string file_name, __attribute__((unused)) vector<Player *> &vp, __attribute__((unused)) AnimalConfig &ac, __attribute__((unused)) PlantConfig &pc, ProductConfig &prod, __attribute__((unused)) RecipeConfig &rc, GameConfig &gc, Toko &t)
{
    std::ifstream my_file(file_name);
    std::string my_string;

    if (!my_file)
    {
        // if file does not exist
        ExceptionFileNotFound e;
        throw e;
    }

    std::string file_content = "";
    while (std::getline(my_file, my_string))
    {
        // string cleeaning
        size_t a = my_string.find('\r');

        if (a != string::npos)
            my_string.erase();

        file_content.append(my_string);
        file_content.append(" ");
    }

    stringstream s(file_content);

    int n_player = 0;

    s >> n_player;

    int inventory_row = gc.getInventoryRow();
    int inventory_col = gc.getInventoryCol();
    int field_row = gc.getFieldRow();
    int field_col = gc.getFieldCol();
    int pen_row = gc.getPenRow();
    int pen_col = gc.getPenCol();

    for (int i = 0; i < n_player; i++)
    {
        Player *p;
        std::string player_name;
        std::string type;
        int body_weight;
        int gulden;

        std::string temp;

        int j = 0;
        while (s >> temp)
        {
            if (temp == "Petani" || temp == "Peternak" || temp == "Walikota")
            {
                break;
            }
            if (j != 0)
                player_name.append(" ");
            player_name.append(temp);
            j++;
        }

        type = temp;

        s >> body_weight >> gulden;

        if (type == "Walikota")
        {
            p = new Walikota(player_name, body_weight, gulden, inventory_row, inventory_col);
        }
        else if (type == "Petani")
        {
            p = new Petani(player_name, body_weight, gulden, inventory_row, inventory_col, field_row, field_col);
        }
        else if (type == "Peternak")
        {
            p = new Peternak(player_name, body_weight, gulden, inventory_row, inventory_col, pen_row, pen_col);
        }

        int n_inventory = 0;
        s >> n_inventory;

        Matrix<GameObject *> *inventory = new Matrix<GameObject *>(gc.getInventoryCol(), gc.getInventoryRow(), "Penyimpanan");

        for (int j = 0; j < n_inventory; j++)
        {
            std::string temp_item;
            s >> temp_item;

            // cek what type of item is this
            // ac pc prod rc
            pair<Product *, bool> resp = prod.isInstanceOf(temp_item);
            if (resp.second)
            {
                inventory->addElement(resp.first);
            }

            pair<Animal *, bool> resp_a = ac.isInstanceOf(temp_item);
            if (resp_a.second)
            {
                inventory->addElement(resp_a.first);
            }

            pair<Plant *, bool> resp_p = pc.isInstanceOf(temp_item);
            if (resp_p.second)
            {
                inventory->addElement(resp_p.first);
            }

            pair<Building *, bool> resp_r = rc.isInstanceOf(temp_item);
            if (resp_r.second)
            {
                inventory->addElement(resp_r.first);
            }
        }

        p->setInventory(inventory);

        if (type == "Petani")
        {
            Field *field = new Field(gc.getFieldCol(), gc.getFieldRow());

            int n_game_object = 0;
            s >> n_game_object;

            for (int j = 0; j < n_game_object; j++)
            {
                std::string coordinate, name;
                int plant_days;
                s >> coordinate >> name >> plant_days;

                pair<Plant *, bool> resp_p = pc.isInstanceOf(name);
                resp_p.first->setCurrentDays(plant_days);

                field->addElement(resp_p.first, coordinate);
            }
            p->setField(field);
        }
        else if (type == "Peternak")
        {
            Farm *farm = new Farm(gc.getPenCol(), gc.getPenRow());

            int n_game_object = 0;
            s >> n_game_object;

            for (int j = 0; j < n_game_object; j++)
            {
                std::string coordinate, name;
                int animal_weight;
                s >> coordinate >> name >> animal_weight;

                pair<Animal *, bool> resp_p = ac.isInstanceOf(name);
                resp_p.first->setCurrentWeight(animal_weight);

                farm->addElement(resp_p.first, coordinate);
            }

            p->setPen(farm);
        }

        vp.push_back(p);
    }

    int n_item_toko = 0;
    s >> n_item_toko;

    for (int i = 0; i < n_item_toko; i++)
    {
        std::string item;
        int quantity;

        s >> item >> quantity;
        t.setItemQuantity(item, quantity);
    }

    // close file stream
    my_file.close();
}

void Main::writeFile(std::string file_name, vector<Player *> &vp, __attribute__((unused)) AnimalConfig &ac, __attribute__((unused)) PlantConfig &pc, __attribute__((unused)) ProductConfig &prod, __attribute__((unused)) RecipeConfig &rc, __attribute__((unused)) GameConfig &gc, __attribute__((unused)) Toko &t)
{
    std::ifstream my_file(file_name);
    std::string my_string;

    if (!my_file)
    {
        // if file does not exist
        my_file.close();

        std::string segment;
        std::string temp;
        std::vector<std::string> path;

        stringstream s_fn(file_name);

        std::getline(s_fn, segment, '/');
        temp.append(segment);
        path.push_back(temp);

        while (std::getline(s_fn, segment, '/'))
        {
            temp.append("/");
            temp.append(segment);
            path.push_back(temp);
        }

        if (path.size() == 1)
        {
        }
        else
        {
            for (int i = 0; i < (int)path.size() - 1; i++)
            {
                fs::path f_path = path[i];
                if (fs::is_directory(f_path))
                {
                    // exist
                }
                else
                {
                    // not exist

                    // create path
                    fs::create_directory(f_path);
                }
            }
        }
    }

    std::ofstream out_file(file_name);

    // write jumlah player
    out_file << vp.size() << "\n";
    for (int i = 0; i < (int)vp.size(); i++)
    {
        // write name, body weight, gulden
        out_file << vp[i]->getName() << " " << vp[i]->getType() << " " << vp[i]->getBodyWeight() << " " << vp[i]->getGulden() << "\n";

        // write jumlah item inventory
        vector<pair<GameObject *, string>> inventory = vp[i]->getAllItem();
        out_file << inventory.size() << "\n";
        for (int i = 0; i < (int)inventory.size(); i++)
        {
            out_file << inventory[i].first->getObjectName() << "\n";
        }

        // write jumlah tanaman di ladang
        if (vp[i]->getType() == "Petani")
        {
            vector<pair<GameObject *, string>> field = vp[i]->getAllPosession();
            out_file << field.size() << "\n";
            for (int i = 0; i < (int)field.size(); i++)
            {
                out_file << field[i].second << " " << field[i].first->getObjectName() << " " << field[i].first->getCurrentDays() << "\n";
            }
            // write jumlah hewan di peternakan
        }
        else if (vp[i]->getType() == "Peternak")
        {
            vector<pair<GameObject *, string>> pen = vp[i]->getAllPosession();
            out_file << pen.size() << "\n";
            for (int i = 0; i < (int)pen.size(); i++)
            {
                out_file << pen[i].second << " " << pen[i].first->getObjectName() << " " << pen[i].first->getCurrentWeight() << "\n";
            }
        }
    }

    // write toko ke file
    vector<pair<GameObject *, int>> isi_toko;
    for (int i = 0; i < t.getNumJenisItem(); i++)
    {
        pair<GameObject *, int> temp = t.getItemI(i);
        if (temp.second != 0 && temp.second != -1000)
        {
            isi_toko.push_back(temp);
        }
    }

    out_file << isi_toko.size() << "\n";

    for (int i = 0; i < (int)isi_toko.size(); i++)
    {
        out_file << isi_toko[i].first->getObjectName() << " " << isi_toko[i].second << "\n";
    }

    out_file.close();

    // close file stream
    my_file.close();
}

/* BAGIAN RUNNING PROGRAM UTAM */

int main()
{
    Field jos(5,5);
    jos.addElement(new FruitPlant(12, "JAR", "Vanson", "Fruit Plant",56, 2));
    jos.addElement(new MaterialPlant(12, "COC", "Vanson", "Fruit Plant",56, 3));
    int n = 2;
    for(int i = 0 ; i < n ; i++){
        jos.updatePlant();
    }
    jos.printHarvest();

    return 0;
}