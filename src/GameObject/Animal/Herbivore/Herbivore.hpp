#ifndef HERBIVORE
#define HERBIVORE

#include "GameObject/Animal/Animal.hpp"

class Herbivore: public Animal {
    private:
        string type;
    public:
        Herbivore();

        Herbivore(int id, string code_name, string object_name, string type, int price, int weight_to_harvest);

        string getType();

        void setType(string s);
};

#endif