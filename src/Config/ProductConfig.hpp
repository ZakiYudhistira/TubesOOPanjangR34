#ifndef __PRODUCT_CONFIG__
#define __PRODUCT_CONFIG__

#include <vector>

#include "Product/Product.hpp"

class ProductConfig {
    private:
        vector<Product> product_list;
        int neff;
    public:
        ProductConfig();

        vector<Product> getProductList();

        void addProduct(Product&);

        friend std::ostream& operator<<(std::ostream& os, const ProductConfig pc);
};

#endif