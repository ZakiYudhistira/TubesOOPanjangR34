#ifndef RECIPE_CONFIG
#define RECIPE_CONFIG

#include <vector>

#include "Building/Building.hpp"

class RecipeConfig {
    private:
        vector<Building> building_list;
        int neff;
    public:
        RecipeConfig();

        vector<Building> getRecipeList();

        void addRecipe(Building& b);

        friend std::ostream& operator<<(std::ostream& os, const RecipeConfig rc);
};

#endif