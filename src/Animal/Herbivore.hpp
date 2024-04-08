#ifndef HERBIVORE
#define HERBIVORE

#include "Animal.hpp"

class Herbivore: public Animal {
    private:
        string type;
    public:
        Herbivore();

        Herbivore(int id, string code_name, string object_name, string type, int price, int weight_to_harvest);
};

#endif