#ifndef ANIMAL_CONFIG
#define ANIMAL_CONFIG

#include <vector>

#include "Config.hpp"
#include "GameObject/Animal/Animal.hpp"
#include "GameObject/Animal/Carnivore/Carnivore.hpp"
#include "GameObject/Animal/Herbivore/Herbivore.hpp"
#include "GameObject/Animal/Omnivore/Omnivore.hpp"

class AnimalConfig: public Config {
    private:
        vector<Animal*> animal_list;
        int neff;
    public:
        AnimalConfig();

        vector<Animal*> getAnimalList();

        void addAnimal(Animal*);

        pair<Animal*, bool> isInstanceOf(std::string);

        friend std::ostream& operator<<(std::ostream& os, AnimalConfig ac);
};

#endif