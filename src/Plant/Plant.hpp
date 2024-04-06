#ifndef __PLANT__
#define __PLANT__

#include "GameObject/GameObject.hpp"

class Plant : public GameObject {
    private:
        int duration_to_harvest;
    public:
        Plant();

        Plant(int id, string code_name, string object_name, int price, int duration_to_harvest);

        friend std::ostream& operator<<(std::ostream& os, Plant p);
};


#endif