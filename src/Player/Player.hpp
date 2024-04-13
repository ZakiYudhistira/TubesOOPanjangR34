#ifndef PLAYER
#define PLAYER

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#include "GameObject/Product/Product.hpp"
#include "Matrix/Matrix.hpp"
#include "Matrix/Farm.hpp"
#include "Matrix/Field.hpp"
#include "GameObject/GameObject.hpp"
#include "Exception/Exception.hpp"

using namespace std;

/*
* Abstract Class. Player.
*/
class Player  {
    protected :
        /* nama dari pemain */
        string name ;
        /* berat badan dari pemain */
        int body_weight ;
        /* jumlah gulden yang dimiliki pemain */
        int gulden ;
        /* pointer ke inventory dari pemain */
        Matrix<GameObject*>* inventory;
    
    public:
        /*
        * Default Constructor. set name bodyweight gulden dan inventory
        */
        Player() ;
        /*
        * User Defined Constructor. set name bodyweight gulden dan inventory
        * @param name `string` nama dari pemain
        * @param body_weight `int` berat badan
        * @param gulden `int` jumlah gulden
        * @param inventory_row `int` baris dari inventory
        * @param inventory_col `int` kolom dari inventory
        */
        Player(string name, int body_weight, int gulden, int inventory_row, int inventory_col) ;
        /*
        * Virtual Destructor. delete pointer inventory
        */
        virtual ~Player() ;
        /*
        * Fungsi eat.
        * delete pointer di object yang dimakan.
        */
        void eat() ;
        /*
        * Fungsi set inventory sesuai dengan masukan.
        * @param m `Matrix<GameObject*>*` pointer ke matrix baru
        */
        void setInventory(Matrix<GameObject*>* m);
        /*
        * Fungsi untuk set berat badan
        * @param weight `int` nilai berat badan
        */
        void addBodyWeight(int weight) ;
        /*
        * Fungsi untuk set gulden
        * @param gulden `int` nilai gulden
        */
        void addGulden(int gulden) ;
        /*
        * Fungsi untuk menampilkan inventory dari player
        */
        void printInventory() ;

        int getInventoryAvailableCount();
        /*
        * Fungsi untuk menampilkan turn siapa saat ini.
        *
        * `+-------------+`
        * `| Name - Type |`
        * `+-------------+`
        */
        void printCurrentTurn();
        /*
        * Fungsi mengembalikan seluruh item pada inventory
        * @return vector item barang pada inventory
        */
        vector<pair<GameObject*, string>> getAllItem();
        /*
        * Fungsi untuk mendapatkan nama player.
        * @return nama `string` nama dari player
        */
        string getName() ;
        /*
        * Fungsi untuk mendapatkan berat badan player.
        * @return berat `int` berat badan player.
        */
        int getBodyWeight() ;
        /*
        * Fungsi untuk mendapatkan gulden dari player.
        * @return guldent `int` jumlah gulden player.
        */
        int getGulden() ;
        /*
        * Operator Overloading. Untuk debug
        */
        friend ostream& operator<<(ostream& os, Player& p);
        /*
        * Virtual Function.
        * untuk Petani set ladangnya.
        */
        virtual void setField(Field* m) = 0;
        /*
        * Virtual Function.
        * untuk Peternak set ladangnya.
        */
        virtual void setPen(Farm* m) = 0;
        /*
        * Virtual Function.
        * untuk child class mengembalikan tipe (PETANI, PETERNAK, WALIKOTA)
        * @return type `string` tipe dari player.
        */
        virtual string getType() = 0;
        /*
        * Virtual Function.
        * untuk child class membayar pajak.
        * @return jumlah_gulden `int` jumlah gulden yang harus disetor.
        */
        virtual int payTax() = 0 ;
        /*
        * Virtual Function.
        * Petani:
        *       mengembalikan vector berisi tanaman dan koordinat
        * Peternak:
        *       mengembalikan vector berisi hewan dan koordinat
        * @return list `vector<pair<GameObject*, string>>` 
        */
        virtual vector<pair<GameObject*, string>> getAllPosession() = 0;
        /*
        * Virtual Function.
        * fungsi untuk melakukan action / perintah pada setiap turn.
        */
        virtual void currentTurn(string) = 0;
};

#endif