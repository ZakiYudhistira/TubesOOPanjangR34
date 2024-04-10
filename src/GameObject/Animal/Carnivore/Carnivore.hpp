#ifndef CARNIVORE
#define CARNIVORE

#include "GameObject/Animal/Animal.hpp"

class Carnivore: public Animal {
    private:
        string type;
    public:
        Carnivore();

        Carnivore(int id, string code_name, string object_name, string type, int price, int weight_to_harvest);

        string getType();

        void setType(string s);
};

#endif