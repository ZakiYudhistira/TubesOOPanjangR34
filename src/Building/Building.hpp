#ifndef __BUILDING__
#define __BUILDING__

#include <vector>

#include "GameObject/GameObject.hpp"

class Building: public GameObject {
    private:
        vector<pair<string, int>> material_list;
        int neff;
    public:
        Building();

        Building(int id, string code, string name, int price);

        ~Building();
        
        void addMaterial(pair<string, int>);

        friend std::ostream& operator<<(std::ostream& os, Building& b);
};

#endif