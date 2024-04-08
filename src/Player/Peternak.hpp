#ifndef PETERNAK
#define PETERNAK

#include "Player.hpp"

class Peternak : public Player {
    private:
        std::string type;
        // Matrix pen ;
    public:
        Peternak();
        Peternak(std::string name, int body_weight, int gulden);
        ~Peternak();
        void ternak();
        void feed();
        void harvest();
        void printPen();
};

#endif