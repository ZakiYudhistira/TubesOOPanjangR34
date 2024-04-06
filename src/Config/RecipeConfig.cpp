#include "RecipeConfig.hpp"

RecipeConfig::RecipeConfig(){
    this->neff = 0;
}

vector<Building> RecipeConfig::getRecipeList(){
    return this->building_list;
}

void RecipeConfig::addRecipe(Building& b){
    this->building_list.push_back(b);
    this->neff++;
}

std::ostream& operator<<(std::ostream& os, RecipeConfig rc){
    os << std::setw(2) << "id" << ' '
        << std::setw(10) << "code name" << ' '
        << std::setw(15) << "object name" << ' '
        << std::setw(5) << "price" << '\n';
    
    for(int i=0; i < rc.neff; i++){
        os << rc.building_list[i] << '\n';
    }

    return os;
}