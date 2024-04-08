#ifndef PLANT
#define PLANT

#include "GameObject/GameObject.hpp"

class Plant : public GameObject {
    private:
        int duration_to_harvest;
        int currentDays ;
    public:
        Plant();

        Plant(int id, string code_name, string object_name, int price, int duration_to_harvest);

        bool isHarvest() ;

        friend std::ostream& operator<<(std::ostream& os, Plant p);
};


#endif