#ifndef ANIMAL
#define ANIMAL

#include "GameObject/GameObject.hpp"

class Animal : public GameObject {
    private :
        int weight_to_harvest;
        int current_weight ;
    public:
        Animal();

        Animal(int id, string code_name, string object_name, int price, int weight_to_harvest);

        bool isHarvest() ;

        friend std::ostream& operator<<(std::ostream& os, Animal a);
};

#endif
