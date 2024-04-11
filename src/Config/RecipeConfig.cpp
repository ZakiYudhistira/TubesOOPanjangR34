#include "RecipeConfig.hpp"

RecipeConfig::RecipeConfig(){
    this->neff = 0;
}

vector<Building*> RecipeConfig::getRecipeList(){
    return this->building_list;
}

void RecipeConfig::addRecipe(Building* b){
    this->building_list.push_back(b);
    this->neff++;
}

pair<Building*, bool> RecipeConfig::isInstanceOf(std::string s){
    Building* new_building;
    for(int i=0; i<this->neff; i++){
        if(this->building_list[i]->getObjectName() == s){
            // int id = this->building_list[i]->getId();
            // std::string type = this->building_list[i]->getType();
            // std::string code = this->building_list[i]->getCode();
            // std::string name = this->building_list[i]->getObjectName();
            // int price = this->building_list[i]->getPrice();
            // vector<pair<string, int>> material_list = this->building_list[i]->getMaterialList();
            

            new_building = new Building(*this->building_list[i]);
            return make_pair(new_building, true);
        }
    }
    return make_pair(new_building, false);
}

std::ostream& operator<<(std::ostream& os, RecipeConfig rc){
    os << std::setw(2) << "id" << ' '
        << std::setw(10) << "code name" << ' '
        << std::setw(15) << "object name" << ' '
        << std::setw(5) << "price" << '\n';
    
    for(int i=0; i < rc.neff; i++){
        os << *rc.building_list[i] << '\n';
    }

    return os;
}