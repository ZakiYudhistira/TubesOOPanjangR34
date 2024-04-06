#ifndef __ANIMAL__
#define __ANIMAL__

#include "GameObject/GameObject.hpp"

class Animal : public GameObject {
    private :
        int weight_to_harvest;
    public:
        Animal();

        Animal(int id, string code_name, string object_name, int price, int weight_to_harvest);

        friend std::ostream& operator<<(std::ostream& os, Animal a);
};

#endif
