#include <iostream>
#include <string>
using namespace std;

class GameObject {
    private:
        string code_name;
        string object_name;
        int price;
    public:
        string getCode();
        // Returns the code_name from a GameObject
        string getObjectName();
        // Returns the object_name from a GameObject
        int getPrice();
        // Returns the price or value from a GameObject
};

class Product : public GameObject {
    private:
        int added_weight;
    public:
        int getAddedWeight();
        // Returns the added_weight of a product; 
};

class Plant : public GameObject {
    private:
        int duration_to_harvest;
    public:
};

class Animal : public GameObject {
    private :
        int weight_to_harvest;
    public:
};

class Bangunan : public GameObject {
    
};