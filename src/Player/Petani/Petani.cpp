#include "Petani.hpp"

Petani::Petani() : Player()
{
    this->type = "Petani";
}

Petani::Petani(string name, int body_weight, int gulden, int inventory_row, int inventory_col, int field_row, int field_col) : Player(name, body_weight, gulden, inventory_row, inventory_col)
{
    this->type = "Petani";

    // initiate field;
    this->field = new Field(field_col, field_row);
}

Petani::~Petani()
{
    delete this->field;
}

void Petani::plant()
{
    cout << "Choose plant from inventory!" << endl;
    this->inventory->printMatrix();
    string slot;

    // Input and validate plant from inventory
    Plant *hasil;
    while (true)
    {
        cout << "Slot : ";
        cin >> slot;
        try
        {
            GameObject *plant = this->inventory->getElement(slot);
            if (this->field->getSlotAvailableCount() == 0)
            {
                throw MatrixFull();
            }
            if (plant->getType() == "FRUIT_PLANT")
            {
                FruitPlant *hasilf = new FruitPlant(plant->getId(), plant->getCode(), plant->getObjectName(), plant->getType(), plant->getPrice(), plant->getDurationToHarvest());
                this->inventory->removeElement(slot);
                cout << "You choose " << hasilf->getObjectName() << "." << endl;
                hasil = hasilf;
                break;
            }
            else if (plant->getType() == "MATERIAL_PLANT")
            {
                MaterialPlant *hasilm = new MaterialPlant(plant->getId(), plant->getCode(), plant->getObjectName(), plant->getType(), plant->getPrice(), plant->getDurationToHarvest());
                this->inventory->removeElement(slot);
                cout << "You choose " << hasilm->getObjectName() << "." << endl;
                hasil = hasilm;
                break;
            }
            else
            {
                throw ItemNotFound();
            }
        }
        catch (MatrixFull &e)
        {
            cout << "There is no space in your field!" << endl;
        }
        catch (MatrixException &e)
        {
            cout << "Input invalid, try again!" << endl;
        }
        catch (ItemNotFound &e)
        {
            cout << e.what() << endl;
        }
    }

    // Put the plant into the field
    cout << "Choose space to plant!" << endl;
    this->field->printHarvest();
    while (true)
    {
        cout << "Slot : ";
        cin >> slot;
        try
        {
            this->field->addElement(hasil);
            cout << hasil->getObjectName() << " successfully planted!" << endl;
            break;
        }

        catch (MatrixException &e)
        {
            cout << "Input invalid, try again!" << endl;
        }
    }
}

void Petani::harvest(ProductConfig &product_list)
{
    int slot_available = this->inventory->getSlotAvailableCount();
    vector<Plant *> harvest_list = this->field->harvest(slot_available);
    vector<Product *> config_list = product_list.getProductList();
    int len_harvest = (int)harvest_list.size();

    for (int i = 0; i < len_harvest; i++)
    {
        Product *product_to_make;
        int j = 0;
        while (true)
        {
            if (config_list[j]->getOrigin() == harvest_list[i]->getObjectName())
            {
                product_to_make = config_list[j];
                break;
            }
            else
            {
                j++;
            }
        }
        if (product_to_make->getType() == "PRODUCT_MATERIAL_PLANT")
        {
            MaterialProduct *hasil = new MaterialProduct(product_to_make->getId(), product_to_make->getCode(), product_to_make->getObjectName(), product_to_make->getPrice(), product_to_make->getAddedWeight(), product_to_make->getOrigin(), product_to_make->getType());
            this->inventory->addElement(hasil);
        }
        else
        {
            FoodProduct *hasil = new FoodProduct(product_to_make->getId(), product_to_make->getCode(), product_to_make->getObjectName(), product_to_make->getPrice(), product_to_make->getAddedWeight(), product_to_make->getOrigin(), product_to_make->getType());
            this->inventory->addElement(hasil);
        }
    }
}

void Petani::printField()
{
    this->field->printHarvest();
}

string Petani::getType()
{
    return this->type;
}

int Petani::payTax()
{
    double gulden = -13;
    gulden += this->getGulden();

    // hitung total kekayaan dari Inventory
    map<string, GameObject *>::iterator it = this->inventory->getContent().begin();
    while (it != this->inventory->getContent().end())
    {
        gulden += it->second->getPrice();
        it++;
    }

    // hitung total kekayaan dari Field
    map<string, Plant *>::iterator it2 = this->field->getContent().begin();
    while (it2 != this->field->getContent().end())
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

ostream &operator<<(ostream &os, Petani &p)
{
    p.field->printMatrix();

    os << "ini dari class petani";

    return os;
}

vector<pair<GameObject *, string>> Petani::getAllPosession()
{
    vector<pair<Plant *, string>> v = this->field->getAllElement();

    vector<pair<GameObject *, string>> p;
    for (int i = 0; i < (int)v.size(); i++)
    {
        p.push_back(make_pair((GameObject *)v[i].first, v[i].second));
    }
    return p;
}

void Petani::setField(Field *m)
{
    this->field = m;
}
void Petani::setPen(__attribute__((unused)) Farm *m) {}

void Petani::currentTurn(string command, vector<Player *> player_list, int current_player_idx, __attribute__((unused)) GameConfig game_config, ProductConfig product_config, __attribute__((unused)) recipe_config, Toko toko_cina)
{
    if (command == "CETAK_LADANG")
    {
        cout << command << "succeed"; // debug purposes
    }
    else if (command == "TANAM")
    {
        cout << command << "succeed";
    }
    else if (command == "MAKAN")
    {
        // Makan
        this->eat();
        cout << command << " succeed\n";
    }
    else if (command == "BELI")
    {
        // Beli
        toko_cina.beli(player_list[current_player_idx]);
        cout << command << " succeed\n";
    }
    else if (command == "JUAL")
    {
        // Jual
        toko_cina.jual(player_list[current_player_idx]);
        cout << command << " succeed\n";
    }
    else if (command == "PANEN")
    {
        cout << command << "succeed";
    }
    else if (command != "NEXT")
    {
        invalidCommand e;
        throw e;
    }
}