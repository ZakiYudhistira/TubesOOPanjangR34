#ifndef GAME_OBJECT
#define GAME_OBJECT

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class GameObject {
    protected:
        int id;
        string code_name;
        string object_name;
        int price;

    public:
        GameObject();

        GameObject(int id, string code_name, string object_name, int price);

        GameObject(const GameObject&);

        GameObject& operator=(const GameObject&);

        // Returns the code_name from a GameObject
        string getCode();
        // Returns the object_name from a GameObject
        string getObjectName();
        // Returns the price or value from a GameObject
        int getPrice();

        virtual string getType() ;
};

#endif