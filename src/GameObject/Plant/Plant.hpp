#ifndef PLANT
#define PLANT

#include "GameObject/GameObject.hpp"

class Plant : public GameObject {
    private:
        int duration_to_harvest;
        int current_days ;
    public:
        Plant();

        Plant(int id, string code_name, string object_name, int price, int duration_to_harvest);

        Plant(const Plant&);

        Plant& operator=(Plant&);

        void setCurrentDays(int x);

        bool isHarvest() ;

        friend std::ostream& operator<<(std::ostream& os, const Plant& p);

        void justToMakeVirtual();
};


#endif