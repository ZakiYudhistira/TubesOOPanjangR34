#ifndef PETANI
#define PETANI
 
#include "Player/Player.hpp"
#include "GameObject/Plant/Plant.hpp"

/*
* Class. Petani
*/
class Petani : public Player {
    private :
        /* type dari suatu pemain */
        string type ;
        /* pointer ke pen (peternakan) dari pemain*/
        Field* field;
        /* list perintah yang boleh dijalankan */
        vector<string> command_list = {"CETAK_PENYIMPANAN", "CETAK_LADANG", "TANAM", "MAKAN", "BELI", ""};
    public :
        /*
        * Default Constructor.
        */
        Petani() ;
        /*
        * User Define Constructor. set name bodyweight gulden dan inventory
        * @param name `string` nama dari pemain
        * @param body_weight `int` berat badan
        * @param gulden `int` jumlah gulden
        * @param inventory_row `int` baris dari inventory
        * @param inventory_col `int` kolom dari inventory
        */
        Petani(string name, int body_weight, int gulden, int inventory_row, int inventory_col, int farm_row, int farm_col) ;
        /*
        * Destructor. untuk delete pointer ke pen
        */
        ~Petani() ;
        /*
        * Fungsi untuk menempatkan tanaman dari inventory ke field
        * 
        */
        void plant() ;
        /*
        * Fungsi untuk menempatkan tanaman dari field ke inventory.
        * 
        */
        void harvest() ;
        /*
        * Override Function.
        * untuk Petani set ladangnya.
        */
        void setField(Field* m);
        /*
        * Override Function. tidak berlaku pada petani
        */
        void setPen(Farm* m);
        /*
        * Fungsi untuk menampilkan field dari peani
        */
        void printField() ;
        /*
        * Override Function.
        * untuk child class mengembalikan tipe (PETANI, PETERNAK, WALIKOTA)
        * @return type `string` tipe dari player.
        */
        string getType() ;
        /*
        * Override Function.
        * untuk child class membayar pajak.
        * @return jumlah_gulden `int` jumlah gulden yang harus disetor.
        */
        int payTax() ;
        /*
        * Override Function.
        * mengembalikan vector berisi tanmaan dan koordinat
        * @return list `vector<pair<GameObject*, string>>` 
        */
        vector<pair<GameObject*, string>> getAllPosession();
        /*
        * Operator Overloading. Untuk debug
        */
        friend ostream& operator<<(ostream& os, Petani& p);
        /*
        * Override Function.
        * fungsi untuk melakukan action / perintah pada setiap turn.
        */
        void currentTurn(string);

} ;


#endif