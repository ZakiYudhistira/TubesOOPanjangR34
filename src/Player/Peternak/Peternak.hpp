#ifndef PETERNAK
#define PETERNAK

#include "Player/Player.hpp"
#include "GameObject/Animal/Animal.hpp"
#include "GameObject/Animal/Carnivore/Carnivore.hpp"
#include "GameObject/Animal/Herbivore/Herbivore.hpp"
#include "GameObject/Animal/Omnivore/Omnivore.hpp"
#include "Config/ProductConfig.hpp"

/*
 * Class. Peternak
 */
class Peternak : public Player
{
private:
    /* type dari suatu pemain */
    string type;
    /* pointer ke pen (peternakan) dari pemain*/
    Farm *pen;
    /* list perintah yang boleh dijalankan */
    vector<string> command_list = {"STATUS", "HELP", "CETAK_PENYIMPANAN", "CETAK_PETERNAKAN", "TERNAK", "KASIH_MAKAN", "MAKAN", "BELI", "JUAL", "PANEN", "NEXT", "SIMPAN"};

public:
    /*
     * Default Constructor.
     */
    Peternak();
    /*
     * User Define Constructor. set name bodyweight gulden dan inventory
     * @param name `string` nama dari pemain
     * @param body_weight `int` berat badan
     * @param gulden `int` jumlah gulden
     * @param inventory_row `int` baris dari inventory
     * @param inventory_col `int` kolom dari inventory
     */
    Peternak(string name, int body_weight, int gulden, int inventory_row, int inventory_col, int pen_row, int pen_col);
    /*
     * Destructor. untuk delete pointer ke pen
     */
    ~Peternak();
    /*
     * Fungsi untuk menempatkan hewan dari inventory ke pen
     *
     */
    void ternak();
    /*
     * Fungsi untuk memberi makan hewan pada pen
     */
    void feed();
    /*
     * Fungsi untuk menempatkan hasil hewan dari pen ke inventory.
     *
     */
    void harvest(ProductConfig &product_list);
    /*
     * Override Function. tidak berlaku pada peternak
     */
    void setField(Field *m);
    /*
     * Override Function.
     * untuk Peternak set peternakannya.
     */
    void setPen(Farm *m);
    /*
     * Fungsi untuk menampilkan pen dari peternak
     */
    void printPen();

    void nextDay() {}
    /*
     * Override Function.
     * untuk child class mengembalikan tipe (PETANI, PETERNAK, WALIKOTA)
     * @return type `string` tipe dari player.
     */
    string getType();
    /*
     * Override Function.
     * untuk child class membayar pajak.
     * @return jumlah_gulden `int` jumlah gulden yang harus disetor.
     */
    int payTax();
    /*
     * Override Function.
     * mengembalikan vector berisi hewan dan koordinat
     * @return list `vector<pair<GameObject*, string>>`
     */
    vector<pair<GameObject *, string>> getAllPosession();
    /*
     * Override Function.
     * fungsi untuk melakukan action / perintah pada setiap turn.
     */
    void currentTurn(string, vector<Player *> &, int &, GameConfig &, AnimalConfig &, PlantConfig &, ProductConfig &, RecipeConfig &, Toko &);
};

#endif