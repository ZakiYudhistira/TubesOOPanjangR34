#include "FileHandler.hpp"

FileHandler::FileHandler(){
    
}

/*
 * debugging function - ga perlu tahu
 *
*/
void check_active_dir(){
    namespace fs = std::filesystem;
    std::string path = "./";
    for (const auto & entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;
}

void FileHandler::readFile(std::string file_name, GameConfig& gc){
    std::ifstream my_file(file_name);
    std::string my_string;

    if(!my_file){
        // if file does not exist
        ExceptionFileNotFound e;
        throw e;
    }
    
    std::string file_content = "";
    while(std::getline(my_file, my_string)){
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

    s >> weight_to_win >> gulden_to_win >> inventory_row >> inventory_col
        >> pen_row >> pen_col >> field_row >> field_col;

    GameConfig new_gc(weight_to_win, gulden_to_win, inventory_row, inventory_col,
                        pen_row, pen_col, field_row, field_col);
    
    gc = new_gc;

    // close file stream
    my_file.close();
}

void FileHandler::readFile(std::string file_name, AnimalConfig& ac){
    std::ifstream my_file(file_name);
    std::string my_string;

    if(!my_file){
        // if file does not exist
        ExceptionFileNotFound e;
        throw e;
    }
    
    std::string file_content = "";
    while(std::getline(my_file, my_string)){
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

    while(s >> id >> code >> name >> type >> weight_to_harvest >> price){
        Animal* temp_animal;
        if(type == "HERBIVORE"){
            Herbivore* herbivore = new Herbivore(id, code, name, type, price, weight_to_harvest);
            temp_animal = herbivore;
        } else if(type == "CARNIVORE"){
            Carnivore* carnivore = new Carnivore(id, code, name, type, price, weight_to_harvest);
            temp_animal = carnivore;
        } else if(type == "OMNIVORE"){
            Omnivore* omnivore = new Omnivore(id, code, name, type, price, weight_to_harvest);
            temp_animal = omnivore;
        }

        std::cout << temp_animal->getType() << "\n";
        ac.addAnimal(temp_animal);
    }

    // close file stream
    my_file.close();
}

void FileHandler::readFile(std::string file_name, PlantConfig& pc){
    std::ifstream my_file(file_name);
    std::string my_string;

    if(!my_file){
        // if file does not exist
        ExceptionFileNotFound e;
        throw e;
    }
    
    std::string file_content = "";
    while(std::getline(my_file, my_string)){
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

    while(s >> id >> code >> name >> type >> duration_to_harvest >> price){
        Plant* temp_plant;
        if(type == "MATERIAL_PLANT"){
            MaterialPlant* material_plant = new MaterialPlant(id, code, name, type, price, duration_to_harvest);
            temp_plant = material_plant;
        } else if(type == "FRUIT_PLANT"){
            FruitPlant* fruit_plant = new FruitPlant(id, code, name, type, price, duration_to_harvest);
            temp_plant = fruit_plant;
        }

        pc.addPlant(temp_plant);
    }

    // close file stream
    my_file.close();
}

void FileHandler::readFile(std::string file_name, ProductConfig& pc){
    std::ifstream my_file(file_name);
    std::string my_string;

    if(!my_file){
        // if file does not exist
        ExceptionFileNotFound e;
        throw e;
    }
    
    std::string file_content = "";
    while(std::getline(my_file, my_string)){
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

    while(s >> id >> code >> name >> type >> origin >> added_weight >> price){
        Product* temp_product;
        if(added_weight == 0){
            MaterialProduct* material_product = new MaterialProduct(id, code, name, price, added_weight, origin, type);
            temp_product = material_product;
        } else {
            FoodProduct* food_product = new FoodProduct(id, code, name, price, added_weight, origin, type);
            temp_product = food_product;
        }

        pc.addProduct(temp_product);
    }

    // close file stream
    my_file.close();
}

void FileHandler::readFile(std::string file_name, RecipeConfig& rc){
    std::ifstream my_file(file_name);
    std::string my_string;

    if(!my_file){
        // if file does not exist
        ExceptionFileNotFound e;
        throw e;
    }
    
    std::string file_content = "";
    while(std::getline(my_file, my_string)){
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

    while(s >> id >> code >> name >> price){
        Building* temp_building = new Building(id, code, name, price);
        
        string temp_val1;
        int temp_val2;
        while(s >> temp_val1 >> temp_val2){
            if(temp_val1 == "|" && temp_val2 == -123456)
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

void FileHandler::readFile(std::string file_name, __attribute__((unused)) vector<Player*>& vp, __attribute__((unused)) AnimalConfig& ac, __attribute__((unused)) PlantConfig& pc, ProductConfig& prod, __attribute__((unused)) RecipeConfig& rc, GameConfig& gc, Toko& t){
    std::ifstream my_file(file_name);
    std::string my_string;

    if(!my_file){
        // if file does not exist
        ExceptionFileNotFound e;
        throw e;
    }

    std::string file_content = "";
    while(std::getline(my_file, my_string)){
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

    for(int i=0; i<n_player; i++){
        __attribute__((unused)) Player* p;
        std::string player_name;
        std::string type;
        int body_weight;
        int gulden;

        std::string temp;

        int j = 0;
        while(s >> temp){
            if(temp == "Petani" || temp == "Peternak" || temp == "Walikota"){
                break;
            }
            if (j != 0)
                player_name.append(" ");
            player_name.append(temp);
            j++;
        }

        type = temp;

        s >> body_weight >> gulden;

        if(type == "Walikota"){
            p = new Walikota(player_name, body_weight, gulden, inventory_row, inventory_col);
        } else if(type == "Petani"){
            p = new Petani(player_name, body_weight, gulden, inventory_row, inventory_col, field_row, field_col);
        } else if(type == "Peternak"){
            p = new Peternak(player_name, body_weight, gulden, inventory_row, inventory_col, pen_row, pen_col);
        }

        int n_inventory = 0;
        s >> n_inventory;

        Matrix<GameObject*>* inventory = new Matrix<GameObject*>(gc.getInventoryCol(), gc.getInventoryRow());

        for(int j=0; j<n_inventory; j++){
            std::string temp_item;
            s >> temp_item;

            // cek what type of item is this
            // ac pc prod rc
            pair<Product*, bool> resp = prod.isInstanceOf(temp_item);
            if(resp.second){
                inventory->addElement(resp.first);
            }

            pair<Animal*, bool> resp_a = ac.isInstanceOf(temp_item);
            if(resp_a.second){
                inventory->addElement(resp_a.first);
            }

            pair<Plant*, bool> resp_p = pc.isInstanceOf(temp_item);
            if(resp_p.second){
                inventory->addElement(resp_p.first);
            }

            pair<Building*, bool> resp_r = rc.isInstanceOf(temp_item);
            if(resp_r.second){
                inventory->addElement(resp_r.first);
            }
        }

        p->setInventory(inventory);

        if (type == "Petani"){
            Matrix<Plant*> farm(gc.getFieldCol(), gc.getFieldRow());

            int n_game_object = 0;
            s >> n_game_object;

            for(int j=0; j<n_game_object; j++){
                std::string coordinate, name;
                int plant_days;
                s >> coordinate >> name >> plant_days;

                pair<Plant*, bool> resp_p = pc.isInstanceOf(name);
                resp_p.first->setCurrentDays(plant_days);

                farm.addElement(resp_p.first, coordinate);
            }
        } else if(type == "Peternak"){
            Matrix<Animal*> pen(gc.getPenCol(), gc.getPenRow());

            int n_game_object = 0;
            s >> n_game_object;

            for(int j=0; j<n_game_object; j++){
                std::string coordinate, name;
                int animal_weight;
                s >> coordinate >> name >> animal_weight;

                pair<Animal*, bool> resp_p = ac.isInstanceOf(name);
                resp_p.first->setCurrentWeight(animal_weight);

                pen.addElement(resp_p.first, coordinate);
            }
        }

        vp.push_back(p);
    }

    // TODO: IMPLEMENT MASUKIN KE TOKO

    int n_item_toko = 0;
    s >> n_item_toko;

    for(int i=0; i<n_item_toko; i++){
        std::string item;
        int quantity;

        s >> item >> quantity;
        t.setItemQuantity(item, quantity);
    }

    // close file stream
    my_file.close();
}

void FileHandler::writeFile(std::string file_name, __attribute__((unused)) vector<Player*>& vp, __attribute__((unused)) AnimalConfig& ac, __attribute__((unused)) PlantConfig& pc, __attribute__((unused)) ProductConfig& prod, __attribute__((unused)) RecipeConfig& rc, __attribute__((unused)) GameConfig& gc, __attribute__((unused)) Toko& t){
    std::ifstream my_file(file_name);
    std::string my_string;

    if(!my_file){
        // if file does not exist
        my_file.close();

        std::string segment;
        std::string temp;
        std::vector<std::string> path;

        stringstream s_fn(file_name);
        
        std::getline(s_fn, segment, '/');
        temp.append(segment);
        path.push_back(temp);

        while(std::getline(s_fn, segment, '/')) {
            temp.append("/");
            temp.append(segment);
            path.push_back(temp);
        }

        if(path.size() == 1){
            std::ofstream out_file(path[0]);

            // write jumlah player
            out_file << vp.size() << "\n";
            for(int i=0; i<(int)vp.size(); i++){
                // write name, body weight, gulden
                out_file << vp[i]->getName() << " " << vp[i]->getBodyWeight() << " " << vp[i]->getGulden() << "\n";

                // write jumlah item inventory
                // out_file << vp[i]->inventory->capacity;
            }
            out_file.close();
        }
        for(int i=0; i<(int)path.size(); i++){
            std::cout << path[i] << "\n";
        }
    }

   

    // close file stream
    my_file.close();
}