#ifndef __RECIPE_CONFIG__
#define __RECIPE_CONFIG__

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