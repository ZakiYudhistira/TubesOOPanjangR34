#include "Player.hpp"

Player::Player()
{
    this->name = "null";
    this->body_weight = 0;
    this->gulden = 0;
}

Player::Player(string name, int body_weight, int gulden, int inventory_row, int inventory_col)
{
    this->name = name;
    this->body_weight = body_weight;
    this->gulden = gulden;

    // initiate inventory
    this->inventory = new Matrix<GameObject *>(inventory_col, inventory_row, "Penyimpanan");
}

Player::~Player()
{
    delete this->inventory;
}

void Player::eat()
{
    string slot;
    cout << "Choose food from inventory" << endl;
    this->inventory->printMatrix();
    cout << "Slot : ";
    cin >> slot;
    GameObject *item = this->inventory->getElement(slot);
    string type = item->getType();
    if (type == "PRODUCT_FRUIT_PLANT" || type == "PRODUCT_ANIMAL")
    {
        this->addBodyWeight(item->getAddedWeight());
        this->inventory->removeElement(slot);
    }
    else
    {
        IsNotFood e;
        throw e;
    }
}

void Player::setInventory(Matrix<GameObject *> *m)
{
    this->inventory = m;
}

vector<pair<GameObject *, string>> Player::getAllItem()
{
    return this->inventory->getAllElement();
}

void Player::addInventory(GameObject *item, string slot)
{
    this->inventory->addElement(item, slot);
}

void Player::addInventory(GameObject *item, vector<string> slots)
{
    for (int i = 0; i < (int)slots.size(); i++)
    {
        this->inventory->addElement(item, slots[i]);
    }
}

GameObject *Player::getInventory(string location)
{
    return this->inventory->getElement(location);
}

void Player::printInventory()
{
    this->inventory->printMatrix();
    cout << "Terdapat: " << this->getInventoryAvailableCount() << "\n";
}

void Player::printStatus()
{
    cout << "name:" << setw(30) << this->name << "\n"
         << "gulden:" << setw(28) << this->gulden << "\n"
         << "weight:" << setw(28) << this->body_weight << "\n"
         << "type:" << setw(30) << this->getType() << "\n"
         << "\n";
}

int Player::getInventoryAvailableCount()
{
    return this->inventory->getSlotAvailableCount();
}

void Player::buy(Toko &toko_cina)
{
    if (toko_cina.getCheapestPrice() > this->gulden)
    {
        throw GuldenNotEnough();
    }
    else if (this->getInventoryAvailableCount() == 0)
    {
        throw InventoryFullException();
    }
    else
    {
        cout << "Uang Anda : " << this->getGulden() << endl;
        cout << "Slot penyimpanan tersedia : " << this->getInventoryAvailableCount() << endl;

        int idx_to_buy;
        int quantity;
        vector<GameObject*> item_bought;

        cout << "Barang yang ingin dibeli : ";
        cin >> idx_to_buy;
        cout << "Kuantitas : ";
        cin >> quantity;

        if (toko_cina.getItemI(idx_to_buy).first->getType() == "Building" && this->getType() == "Walikota") {
            throw ProhibitedBuyingException();
        } else {
            for(int count_item = 0; count_item < quantity; count_item++) {
                item_bought.push_back(toko_cina.beli(idx_to_buy, 1, this->gulden, this->getInventoryAvailableCount()));
                this->addGulden(item_bought[0]->getPrice() * (-1));
            }

            cout << "Selamat, Anda berhasil membeli " << quantity << " " << item_bought[0]->getObjectName()
                << ". Uang Anda tersisa " << this->gulden << " gulden." << endl;
            cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
            this->printInventory();
            vector<string> petak_beli = this->inputPetakBeli();
            if ((int)petak_beli.size() != quantity) {
                toko_cina.batalBeli(idx_to_buy, quantity);
                throw InvalidInput();
            } else {
                for(int i=0; i<(int)petak_beli.size(); i++){
                    this->addInventory(item_bought[i], petak_beli[i]);
                }
                cout << item_bought[0]->getObjectName() << " berhasil disimpan dalam penyimpanan!" << endl;
            }
        }
    }
}

void Player::sell(Toko &toko_cina)
{
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

    bool valid = true;
    for (int i = 0; i < (int)petak_jual.size(); i++)
    {
        sold.push_back(this->getInventory(petak_jual[i]));
        if (this->getInventory(petak_jual[i])->getType() == "Building" && this->getType() != "Walikota")
        {
            valid = false;
        }
    }

    if (valid)
    {
        gulden_given = toko_cina.jual(sold);

        /* DELETE ITEM SOLD IN INVENTORY */
        for (int i = 0; i < (int)petak_jual.size(); i++)
        {
            this->inventory->removeElement(petak_jual[i]);
        }

        this->addGulden(gulden_given);
        cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << gulden_given << " gulden!\n";
    }
    else
    {
        throw ProhibitedSellingException();
    }
}

vector<string> Player::inputPetakBeli()
{
    vector<string> petak_beli;
    string input_petak;
    cout << "Petak : ";
    cin >> ws;
    getline(cin, input_petak);
    int start = 0;
    int end = 0;
    while ((end = input_petak.find(", ", start)) != (int) string::npos)
    {
        petak_beli.push_back(input_petak.substr(start, end-start));
        start = end + 2;
    }
    petak_beli.push_back(input_petak.substr(start));
    
    return petak_beli;
}

void Player::printCurrentTurn()
{
    string title = this->name + " - " + this->getType();
    cout << "+";
    for (int i = 0; i < (int)title.length() + 2; i++)
    {
        cout << "-";
    }
    cout << "+\n";

    cout << "| " << title << " |\n";

    cout << "+";
    for (int i = 0; i < (int)title.length() + 2; i++)
    {
        cout << "-";
    }
    cout << "+\n";
}

string Player::getName()
{
    return this->name;
}

int Player::getBodyWeight()
{
    return this->body_weight;
}

int Player::getGulden()
{
    return this->gulden;
}

void Player::addBodyWeight(int weight)
{
    this->body_weight += weight;
}

void Player::addGulden(int gulden)
{
    this->gulden += gulden;
}

ostream &operator<<(ostream &os, Player &p)
{
    p.inventory->printMatrix();

    os << p.name << " "
       << p.body_weight << " "
       << p.gulden << "\n";

    return os;
}