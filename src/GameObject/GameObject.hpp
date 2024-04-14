#ifndef GAME_OBJECT
#define GAME_OBJECT

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
* Class. GameObject. Hampir semuanya merupakan GameObject.
*/
class GameObject {
    protected:
        /* id dari suatu objek */
        int id;
        /* kode dari suatu objek */
        string code_name;
        /* nama dari suatu objek */
        string object_name;
        /* harga dari suatu objek */
        int price;
    public:
        /* 
        * Default Constructor.
        */
        GameObject();
        /*
        * User Defined Constructor. 
        * @param id `int` id dari objek
        * @param code_name `string` 3 huruf kode
        * @param object_name `string` nama dari objek
        * @param price `int` harga dari objek
        */
        GameObject(int id, string code_name, string object_name, int price);
        /*
        * Copy Constructor.
        * @param g `GameObject&`
        */
        GameObject(const GameObject&);
        /*
        * Virtual Destructor.
        */
        virtual ~GameObject() ;
        /*
        * Assignment Operator.
        * @param GameObject&
        * @return GameObject&
        */
        GameObject& operator=(const GameObject&);
        /*
        * Fungsi mengembalikan id dari objek
        * @return id `int` id dari objek
        */
        int getId();
        /*
        * Fungsi mengembalikan kode dari objek
        * @return code `string` 3 huruf
        */
        string getCode();
        /*
        * Fungsi mengembalikan nama dari objek
        * @return name `string` nama dari objek
        */
        string getObjectName();
        /*
        * Fungsi mengembalikan harga dari objek
        * @return price `int` harga dari objek
        */
        int getPrice();
        /*
        * Virtual Function.
        * untuk child class mengembalikan tipe (HERBIVORE, MATERIAL_PLANT, ...)
        * @return type `string` tipe dari objek.
        */
        virtual string getType() = 0;
        /*
        * Virtual Function.
        * untuk Product class mengembalikan berat yang dapat ditambah jika dimakan
        * @return added_weight `int` dari product.
        */
        virtual int getAddedWeight() = 0;
        /*
        * Virtual Function.
        * untuk Animal class mengembalikan berat animal saat ini
        * @return current_weight `int` dari animal.
        */
        virtual int getCurrentWeight() = 0;
        /*
        * Virtual Function.
        * untuk Plant class mengembalikan umur tanaman saat ini
        * @return current_days `int` dari plant.
        */
        virtual int getCurrentDays() = 0;

        virtual int getDurationToHarvest() = 0 ;

        virtual int getWeightToHarvest() = 0 ;
};

#endif