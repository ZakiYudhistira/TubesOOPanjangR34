#ifndef RECIPE_CONFIG
#define RECIPE_CONFIG

#include <vector>

#include "GameObject/Building/Building.hpp"

class RecipeConfig {
    private:
        vector<Building*> building_list;
        int neff;
    public:
        RecipeConfig();

        ~RecipeConfig();

        vector<Building*> getRecipeList();

        void addRecipe(Building* b);

        pair<Building*, bool> isInstanceOf(std::string);

        friend std::ostream& operator<<(std::ostream& os, RecipeConfig& rc);
};

#endif