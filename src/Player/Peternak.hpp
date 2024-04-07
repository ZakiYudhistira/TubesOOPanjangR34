#ifndef __PETERNAK__
#define __PETERNAK__

#include "Player.hpp"

class Peternak : public Player
{
private:
    string type;
    // Matrix pen ;
public:
    Peternak();
    Peternak(string name, int body_weight, int gulden);
    ~Peternak();
    void ternak();
    void feed();
    void harvest();
    void printPen();
};

#endif