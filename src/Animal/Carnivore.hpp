#ifndef __CARNIVORE__
#define __CARNIVORE__

#include "Animal.hpp"

class Carnivore: public Animal {
    private:
        string type;
    public:
        Carnivore();

        Carnivore(int id, string code_name, string object_name, string type, int price, int weight_to_harvest);
};

#endif