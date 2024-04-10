#ifndef PETERNAK
#define PETERNAK

#include "Player/Player.hpp"
#include "GameObject/Animal/Animal.hpp"

class Peternak : public Player {
    private:
        std::string type;
        Matrix<Animal*> pen;
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