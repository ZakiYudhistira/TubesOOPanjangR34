#ifndef OMNIVORE
#define OMNIVORE

#include "GameObject/Animal/Animal.hpp"

class Omnivore: public Animal {
    private:
        string type;
    public:
        Omnivore();

        Omnivore(int id, string code_name, string object_name, string type, int price, int weight_to_harvest);

        string getType();

        void setType(string s);
};

#endif