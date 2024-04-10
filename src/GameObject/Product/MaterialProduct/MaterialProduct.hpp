#ifndef MATERIAL_PRODUCT
#define MATERIAL_PRODUCT

#include "GameObject/Product/Product.hpp"

class MaterialProduct: public Product {
    private:
        string type;
    public:
        MaterialProduct();

        MaterialProduct(int id, string code_name, string object_name, int price, int added_weight, string origin, string type);

        string getType();
        
        void setType(string s);
};

#endif