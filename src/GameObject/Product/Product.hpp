#ifndef PRODUCT
#define PRODUCT

#include "GameObject/GameObject.hpp"

/*
* Class. Product
*/
class Product : public GameObject {
    private:
        /* berat yang ditambahkan jika dikonsumsi */
        int added_weight;
        /* nama asal produk */
        string origin;
    public:
        /* 
        * Default Constructor.
        */
        Product();
        /*
        * User Defined Constructor. 
        * @param id `int` id dari produk
        * @param code_name `string` 3 huruf kode
        * @param object_name `string` nama dari produk
        * @param price `int` harga dari objek
        * @param added_weight `int` berat yang ditambahkan
        * @param origin `string` asal usul produk
        */
        Product(int id, string code_name, string object_name, int price, int added_weight, string origin);
        /*
        * Copy Constructor.
        * @param p `Product&`
        */
        Product(const Product&);
        /*
        * Assignment Operator.
        * @param Product&
        * @return Product&
        */
        Product& operator=(Product&);
        /*
        * Virtual Destructor.
        */
        virtual ~Product();
        /*
        * Fungsi mengembalikan berat yang ditambahkan jika dikonsumsi
        * @return added_weight `int`
        */
        int getAddedWeight();
        /*
        * Fungsi mengembalikan asal usul dari produk
        * @return origin `string`
        */
        string getOrigin();
        /*
        * Override Function. tidak berlaku pada Produk
        */
        int getCurrentWeight(){return 0;}
        /*
        * Override Function. tidak berlaku pada Produk
        */
        int getCurrentDays(){return 0;}

        int getDurationToHarvest(){return 0;}

        int getWeightToHarvest() {return 0;}
        /*
        * Operator Overloading. Untuk debug
        */
        friend std::ostream& operator<<(std::ostream& os, const Product& p);
        /*
        * Virtual Function.
        * untuk child class mengembalikan tipe (MATERIAL_PRODUCT, FOOD_PRODUCT)
        * @return type `string` tipe dari objek.
        */
        virtual string getType() = 0;
        /*
        * Virtual Function.
        * untuk child class set tipe (MATERIAL_PRODUCT, FOOD_PRODUCT)
        * @param type `string` tipe dari objek.
        */
        virtual void setType(string s) = 0;
};

#endif