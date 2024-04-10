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

        Animal(const Animal&);

        // Animal& operator=(Animal&);

        void setCurrentWeight(int x);

        bool isHarvest() ;

        virtual string getType() = 0;

        virtual void setType(string s) = 0;

        friend std::ostream& operator<<(std::ostream& os, const Animal& a);

};

#endif
