#ifndef WALIKOTA
#define WALIKOTA

#include "Player/Player.hpp"
#include "Player/Petani/Petani.hpp"
#include "Player/Peternak/Peternak.hpp"
#include "Toko/Toko.hpp"

#include "Config/GameConfig.hpp"
#include "Config/RecipeConfig.hpp"
#include "GameObject/Building/Building.hpp"

/*
 * Class. Walikota
 */
class Walikota : public Player
{
private:
    /* type dari suatu pemain */
    string type;
    /* list perintah yang boleh dijalankan */
    vector<string> command_list = {"STATUS", "HELP", "CETAK_PENYIMPANAN", "PUNGUT_PAJAK", "BANGUN", "MAKAN", "BELI", "JUAL", "TAMBAH_PEMAIN", "NEXT", "SIMPAN"};

public:
    /*
     * Default Constructor.
     */
    Walikota();
    /*
     * User Define Constructor. set name bodyweight gulden dan inventory
     * @param name `string` nama dari pemain
     * @param body_weight `int` berat badan
     * @param gulden `int` jumlah gulden
     * @param inventory_row `int` baris dari inventory
     * @param inventory_col `int` kolom dari inventory
     */
    Walikota(string name, int body_weight, int gulden, int inventory_row, int inventory_col);
    /*
     * Fungsi untuk mengambil pajak dari seluruh player.
     * @param player_list `vector<Player*>` list player
     */
    void tax(vector<Player *> player_list);
    /*
     * Override Function. tidak berlaku pada walikota
     */
    void setField(Field *m);
    /*
     * Override Function. tidak berlaku pada walikota
     */
    void setPen(Farm *m);
    /*
     * Fungsi untuk membuat bangunan dan mengembalikan bangunan
     * @param recipe `RecipeConfig&` dafter recipe
     * @param building `Building*` bangunan baru
     */
    void build(RecipeConfig &recipe);
    /*
     * Fungsi untuk membuat player baru dan mengembalikan player
     * @param gc `GameConfig&` game configuration
     * @param player `Player*` player baru
     */
    Player *addPlayer(GameConfig &gc, vector<Player *> player_list);
    /*
     * Override Function.
     * untuk child class mengembalikan tipe (PETANI, PETERNAK, WALIKOTA)
     * @return type `string` tipe dari player.
     */
    string getType();

    void nextDay() {}
    /*
     * Override Function.
     * untuk child class membayar pajak.
     * @return jumlah_gulden `int` jumlah gulden yang harus disetor.
     */
    int payTax();
    /*
     * Override Function. tidak berlaku pada walikota
     */
    vector<pair<GameObject *, string>> getAllPosession();
    /*
     * Override Function.
     * fungsi untuk melakukan action / perintah pada setiap turn.
     */
    void currentTurn(string, vector<Player *> &, int &, GameConfig &, AnimalConfig &, PlantConfig &, ProductConfig &, RecipeConfig &, Toko &);
};
#endif