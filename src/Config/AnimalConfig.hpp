#ifndef ANIMAL_CONFIG
#define ANIMAL_CONFIG

#include <vector>

#include "Config.hpp"
#include "Animal/Animal.hpp"

class AnimalConfig: public Config {
    private:
        vector<Animal> animal_list;
        int neff;
    public:
        AnimalConfig();

        vector<Animal> getAnimalList();

        void addAnimal(Animal&);

        friend std::ostream& operator<<(std::ostream& os, const AnimalConfig ac);
};

#endif