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
        Animal* temp_animal = new Animal();
        if(type == "HERBIVORE"){
            Herbivore herbivore(id, code, name, type, price, weight_to_harvest);
            *temp_animal = herbivore;
        } else if(type == "CARNIVORE"){
            Carnivore carnivore(id, code, name, type, price, weight_to_harvest);
            *temp_animal = carnivore;
        } else if(type == "OMNIVORE"){
            Omnivore omnivore(id, code, name, type, price, weight_to_harvest);
            *temp_animal = omnivore;
        }

        ac.addAnimal(*temp_animal);

        delete temp_animal;
    }
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
        Plant* temp_plant = new Plant();
        if(type == "MATERIAL_PLANT"){
            MaterialPlant material_plant(id, code, name, type, price, duration_to_harvest);
            *temp_plant = material_plant;
        } else if(type == "FRUIT_PLANT"){
            FruitPlant fruit_plant(id, code, name, type, price, duration_to_harvest);
            *temp_plant = fruit_plant;
        }

        pc.addPlant(*temp_plant);

        delete temp_plant;
    }
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
        Product* temp_product = new Product();
        if(added_weight == 0){
            MaterialProduct material_product(id, code, name, price, added_weight, origin, type);
            *temp_product = material_product;
        } else {
            FoodProduct food_product(id, code, name, price, added_weight, origin, type);
            *temp_product = food_product;
        }

        pc.addProduct(*temp_product);

        delete temp_product;
    }
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

        rc.addRecipe(*temp_building);

        delete temp_building;
    }
}