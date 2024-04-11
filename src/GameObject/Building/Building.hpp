#ifndef BUILDING
#define BUILDING

#include <vector>

#include "GameObject/GameObject.hpp"

class Building: public GameObject {
    private:
        vector<pair<string, int>> material_list;
        int neff;
        string type;
    public:
        Building();

        Building(int id, string code, string name, int price);

        Building(const Building&);

        Building& operator=(Building &);

        ~Building();
        
        vector<pair<string, int>> getMaterialList();

        int getNeff();
        
        string getType();

        void addMaterial(pair<string, int>);

        int getAddedWeight();

        int getCurrentWeight(){return 0;}

        int getCurrentDays(){return 0;}

        friend std::ostream& operator<<(std::ostream& os, Building& b);
};

#endif