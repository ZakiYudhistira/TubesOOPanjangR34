#include "Player.hpp"

Player::Player(){
    this->name = "null";
    this->body_weight = 0;
    this->gulden = 0;
}

Player::Player(string name, int body_weight, int gulden, int inventory_row, int inventory_col){
    this->name = name;
    this->body_weight = body_weight;
    this->gulden = gulden;

    // initiate inventory
    this->inventory = new Matrix<GameObject*>(inventory_col, inventory_row, "Penyimpanan");
}

Player::~Player() {
    delete this->inventory;
}

void Player::eat() {
    string slot ;
    cout << "Choose food from inventory" << endl ;
    this->inventory->printMatrix() ;
    cout << "Slot : " ;
    cin >> slot ;
    GameObject* item = this->inventory->getElement(slot) ;
    string type = item->getType() ;
    if (type == "PRODUCT_FRUIT_PLANT" || type == "PRODUCT_ANIMAL") {
        this->addBodyWeight(item->getAddedWeight()) ;
        this->inventory->removeElement(slot) ;
    }
    else {
        IsNotFood e ;
        throw e ;
    }
} 

void Player::setInventory(Matrix<GameObject*>* m){
    this->inventory = m;
}

vector<pair<GameObject*, string>> Player::getAllItem(){
    return this->inventory->getAllElement();
}

void Player::addInventory(GameObject* item, string slot) {
    this->inventory->addElement(item, slot);
}

void Player::addInventory(GameObject* item, vector<string> slots) {
    for (int i=0; i<(int)slots.size(); i++) {
        this->inventory->addElement(item, slots[i]);
    }
}

GameObject* Player::getInventory(string location) {
    return this->inventory->getElement(location);
}

void Player::printInventory() {
    this->inventory->printMatrix();
} 

void Player::printStatus() {
    cout << "name:" << setw(30) << this->name << "\n"
        << "gulden:" << setw(30) << this->gulden << "\n"
        << "weight:" << setw(30) << this->body_weight << "\n"
        << "type:" << setw(30) << this->getType() << "\n"
        << "\n";
}

int Player::getInventoryAvailableCount() {
    return this->inventory->getSlotAvailableCount();
}

void Player::buy(Toko& toko_cina){
    if (toko_cina.getCheapestPrice() > this->gulden)
    {
        throw GuldenNotEnough();
    }
    else if(this->getInventoryAvailableCount() == 0){
        throw InventoryFullException();
    } else {
        cout << "Uang Anda : " << this->getGulden() << endl;
        cout << "Slot penyimpanan tersedia : " << this->getInventoryAvailableCount() << endl;
        
        int idx_to_buy;
        int quantity;
        GameObject* item_bought;
        
        cout << "Barang yang ingin dibeli : ";
        cin >> idx_to_buy;
        cout << "Kuantitas : ";
        cin >> quantity;

        item_bought = toko_cina.beli(idx_to_buy, quantity, this->gulden, this->getInventoryAvailableCount());
        this->addGulden(quantity * item_bought->getPrice() * (-1));

        cout << "Selamat, Anda berhasil membeli " << quantity << " " << item_bought->getObjectName()
                << ". Uang Anda tersisa " << this->gulden << " gulden." << endl;
        cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
        this->printInventory();
        vector<string> petak_beli = this->inputPetakBeli(quantity);
        this->addInventory(item_bought, petak_beli);
        cout << item_bought->getObjectName() << " berhasil disimpan dalam penyimpanan!" << endl;
    }
}

void Player::sell(Toko& toko_cina){
    cout << "Berikut merupakan penyimpanan Anda" << endl;
    this->printInventory();
    cout << "Silahkan pilih petak yang ingin Anda jual" << endl;
    
    vector<string> petak_jual;
    string input_petak;
    
    cout << "Petak : ";
    cin >> ws;
    getline(cin, input_petak);
    
    string s;
    stringstream ssinput(input_petak);
    while (ssinput >> s)
    {
        petak_jual.push_back(s);
    }

    int gulden_given = 0;
    vector<GameObject *> sold;
    // try {
    for (int i = 0; i < (int)petak_jual.size(); i++)
    {
        sold.push_back(this->getInventory(petak_jual[i]));
    }


    gulden_given = toko_cina.jual(sold);

    /* DELETE ITEM SOLD IN INVENTORY */
    for(int i=0; i<(int)petak_jual.size(); i++){
        this->inventory->removeElement(petak_jual[i]);
    }
    
    this->addGulden(gulden_given);
    cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << gulden_given << "gulden!\n";
    // } catch (Exception e) {
    //     cout << "";
    // }
    
}

vector<string> Player::inputPetakBeli(int quantity){
    vector<string> petak_beli;
    string input_petak;
    string s;
    while ((int)petak_beli.size() != quantity)
    {
        cout << quantity << endl;
        cout << petak_beli.size() << endl;
        petak_beli.clear();
        cout << "Petak : ";
        cin >> ws;
        getline(cin, input_petak);
        stringstream ssinput(input_petak);
        while (getline(ssinput, s, ','))
        {
            petak_beli.push_back(s);
            cout << s << endl;
        }
        if ((int)petak_beli.size() != quantity)
        {
            cout << "Masukkan sesuai kuantitas yang Anda beli!" << endl;
        }
    }
    return petak_beli;
}

void Player::printCurrentTurn(){
    string title = this->name + " - " + this->getType();
    cout << "+";
    for(int i=0; i<(int)title.length() + 2; i++){
        cout << "-";
    }
    cout << "+\n";

    cout << "| " << title << " |\n";

    cout << "+";
    for(int i=0; i<(int)title.length() + 2; i++){
        cout << "-";
    }
    cout << "+\n";
}

string Player::getName() {
    return this->name ;
}

int Player::getBodyWeight() {
    return this->body_weight ;
}

int Player::getGulden() {
    return this->gulden ;
}

void Player::addBodyWeight(int weight) {
    this->body_weight += weight ;
}

void Player::addGulden(int gulden) {
    this->gulden += gulden ;
}

ostream& operator<<(ostream& os, Player& p){
    p.inventory->printMatrix();
    
    os << p.name << " "
        << p.body_weight << " "
        << p.gulden << "\n";


    return os;
}