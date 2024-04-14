#include "Peternak.hpp"

Peternak::Peternak() : Player()
{
    this->type = "Peternak";
}

Peternak::Peternak(string name, int body_weight, int gulden, int inventory_row, int inventory_col, int pen_row, int pen_col) : Player(name, body_weight, gulden, inventory_row, inventory_col)
{
    this->type = "Peternak";

    this->pen = new Farm(pen_col, pen_row);
}

Peternak::~Peternak()
{
    delete this->pen;
}

void Peternak::ternak() {
    cout << "Choose an animal from inventory!" << endl ;
    this->inventory->printMatrix() ;
    string slot ;

    // Input and validate animal from inventory
    Animal *hasil ;
    while(true) {
        cout << "Slot : " ;
        cin >> slot ;
        try {
            GameObject* animal = this->inventory->getElement(slot) ;
            if (this->pen->getSlotAvailableCount() == 0) {
                throw MatrixFull() ;
            }
            if (animal->getType() == "CARNIVORE") {
                Carnivore *hasilc = new Carnivore(animal->getId(), animal->getCode(), animal->getObjectName(), animal->getType(), animal->getPrice(), animal->getWeightToHarvest()) ;
                this->inventory->removeElement(slot) ;
                cout << "You choose " << hasilc->getObjectName() << "." << endl ;
                hasil = hasilc ;
                break;
            }
            else if (animal->getType() == "HERBIVORE") {
                Herbivore *hasilh = new Herbivore(animal->getId(), animal->getCode(), animal->getObjectName(), animal->getType(), animal->getPrice(), animal->getWeightToHarvest()) ;
                this->inventory->removeElement(slot) ;
                cout << "You choose " << hasilh->getObjectName() << "." << endl ;
                hasil = hasilh ;
                break;
            }
            else if (animal->getType() == "OMNIVORE") {
                Omnivore *hasilo = new Omnivore(animal->getId(), animal->getCode(), animal->getObjectName(), animal->getType(), animal->getPrice(), animal->getWeightToHarvest()) ;
                this->inventory->removeElement(slot) ;
                cout << "You choose " << hasilo->getObjectName() << "." << endl ;
                hasil = hasilo ;
                break;
            }
            else {
                throw ItemNotFound() ;
            }
        }
        catch(MatrixFull &e) {
            cout << "There is no space in your field!" << endl ;
        }
        catch(MatrixException &e) {
            cout << "Input invalid, try again!" << endl ;
        }
        catch(ItemNotFound &e) {
            cout << e.what() << endl ;
        }
    }

    // Put the animal into the field
    cout << "Choose space to put the animal!" << endl ;
    this->pen->printHarvest() ;
    while(true) {
        cout << "Slot : " ;
        cin >> slot ;
        try {
            this->pen->addElement(hasil) ;
            cout << hasil->getObjectName() << " successfully placed!" << endl ;
            break;
        }

        catch(MatrixException &e) {
            cout << "Input invalid, try again!" << endl ;
        }
    }   
}

void Peternak::feed() {} // matrix boi

void Peternak::harvest(ProductConfig &product_list) {
    int slot_available = this->inventory->getSlotAvailableCount() ;
    vector<Animal*> harvest_list = this->pen->harvest(slot_available) ;
    vector<Product*> config_list = product_list.getProductList() ;
    int len_harvest = (int)harvest_list.size() ;

    for (int i = 0 ; i < len_harvest ; i++) {
        Product* product_to_make ;
        int j = 0 ;
        while(true) {
            if (config_list[j]->getOrigin() == harvest_list[i]->getObjectName()) {
                product_to_make = config_list[j] ;
                break ;
            }
            else {
                j++ ;
            }
        }
        if (product_to_make->getType() == "MATERIAL_PRODUCT") {
            MaterialProduct *hasil = new MaterialProduct(product_to_make->getId(), product_to_make->getCode(), product_to_make->getObjectName(), product_to_make->getPrice(), product_to_make->getAddedWeight(), product_to_make->getOrigin(), product_to_make->getType()) ;
            this->inventory->addElement(hasil) ;
        }
        else {
            FoodProduct *hasil = new FoodProduct(product_to_make->getId(), product_to_make->getCode(), product_to_make->getObjectName(), product_to_make->getPrice(), product_to_make->getAddedWeight(), product_to_make->getOrigin(), product_to_make->getType()) ;
            this->inventory->addElement(hasil) ;
        }
    }

}

void Peternak::printPen() {
    this->pen->printHarvest() ;
}

string Peternak::getType()
{
    return this->type;
}

int Peternak::payTax()
{
    double gulden = -11;
    gulden += this->getGulden() ;
    
    // hitung total kekayaan dari Inventory
    map<string, GameObject *>::iterator it = this->inventory->getContent().begin();
    while (it != this->inventory->getContent().end())
    {
        gulden += it->second->getPrice();
        it++;
    }

    // hitung total kekayaan dari Field
    map<string, Animal *>::iterator it2 = this->pen->getContent().begin();
    while (it2 != this->pen->getContent().end())
    {
        gulden += it2->second->getPrice();
        it++;
    }

    // hitung pajak total
    if (gulden <= 0)
    {
        gulden = 0;
    }
    else if (gulden <= 6)
    {
        gulden = round(gulden * 0.05);
    }
    else if (gulden <= 25)
    {
        gulden = round(gulden * 0.15);
    }
    else if (gulden <= 50)
    {
        gulden = round(gulden * 0.25);
    }
    else if (gulden <= 500)
    {
        gulden = round(gulden * 0.30);
    }
    else
    {
        gulden = round(gulden * 0.35);
    }
    return (int)gulden;
}

vector<pair<GameObject *, string>> Peternak::getAllPosession()
{
    vector<pair<Animal *, string>> v = this->pen->getAllElement();

    vector<pair<GameObject *, string>> p;
    for (int i = 0; i < (int)v.size(); i++)
    {
        p.push_back(make_pair((GameObject *)v[i].first, v[i].second));
    }
    return p;
}

void Peternak::setField(__attribute__((unused)) Field *m)
{
}

void Peternak::setPen(Farm *m)
{
    this->pen = m;
}

void Peternak::currentTurn(string command)
{
    this->pen->printHarvest();
    if (command == "CETAK_PETERNAKAN")
    {
        cout << command << "succeed"; // debug purposes
    }
    else if (command == "TERNAK")
    {
        cout << command << "succeed";
    }
    else if (command == "MAKAN")
    {
        cout << command << "succeed";
    }
    else if (command == "BELI")
    {
        cout << command << "succeed";
    }
    else if (command == "JUAL")
    {
        cout << command << "succeed";
    }
    else if (command == "KASIH_MAKAN")
    {
        cout << command << "succeed";
    }
    else if (command == "PANEN")
    {
        cout << command << "succeed";
    }
    else
    {
        invalidCommand e;
        throw e;
    }
}