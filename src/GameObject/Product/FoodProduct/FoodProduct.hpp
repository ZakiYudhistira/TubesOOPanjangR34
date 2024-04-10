#ifndef FOOD_PRODUCT
#define FOOD_PRODUCT

#include "GameObject/Product/Product.hpp"

class FoodProduct: public Product {
    private:
        string type;
    public:
        FoodProduct();

        FoodProduct(int id, string code_name, string object_name, int price, int added_weight, string origin, string type);

        string getType();

        void setType(string s);
};

#endif