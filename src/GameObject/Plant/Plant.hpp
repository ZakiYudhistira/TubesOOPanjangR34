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

        virtual ~Plant();

        void setCurrentDays(int x);

        int getDurationToHarvest();

        bool isHarvest() ;

        virtual string getType() = 0;
        
        virtual void setType(string s) = 0;

        friend std::ostream& operator<<(std::ostream& os, const Plant& p);
};


#endif