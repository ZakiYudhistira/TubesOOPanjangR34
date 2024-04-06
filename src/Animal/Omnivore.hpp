#ifndef __OMNIVORE__
#define __OMNIVORE__

#include "Animal.hpp"

class Omnivore: public Animal {
    private:
        string type;
    public:
        Omnivore();

        Omnivore(int id, string code_name, string object_name, string type, int price, int weight_to_harvest);
};

#endif