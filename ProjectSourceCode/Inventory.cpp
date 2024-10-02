#include "Inventory.h"
#include <iostream>

using namespace std;

// default constructor initialize contents of inventory at beginning of game
Inventory::Inventory()
{
    gold_ = 100; // player's party starts with 100 base gold
    ingredients_ = 0;
    pots_ = 0;
    pans_ = 0;
    cauldrons_ = 0;
    clubs_ = 0;
    spears_ = 0;
    rapiers_ = 0;
    axes_ = 0;
    swords_ = 0;
    num_weapons_ = 0;
    armour_ = 0;
    rings_ = 0;
    necklaces_ = 0;
    bracelets_ = 0;
    circlets_ = 0;
    goblets_ = 0;
}

// prints current inventory
void Inventory::printInventory()
{
    cout << "+-------------+" << endl;
    cout << "| INVENTORY   |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Gold        | " << gold_ << endl;
    cout << "| Ingredients | " << getIngredients() << " kg" << endl;
    cout << "| Cookware    | P: " << getPots() << " | F: " << getPans() << " | Ca: " << getCauldrons() << endl;
    cout << "| Weapons     | Cl: " << getClubs() << " | Sp: " << getSpears() << " | R: " << getRapiers() << " | A: " << getAxes() << " | Sw: " << getSwords() << endl;
    cout << "| Armor       | " << getArmour() << endl;
    cout << "| Treasures   | R: " << getRings() << " | N: " << getNecklaces() << " | B: " << getBracelets() << " | C: " << getCirclets() << " | G: " << getGoblets() << endl;
}

// getters/accessors for various items stored in the inventory object
int Inventory::getGold()
{
    return gold_;
}

int Inventory::getIngredients()
{
    return ingredients_;
}

int Inventory::getPots()
{
    return pots_;
}

int Inventory::getPans()
{
    return pans_;
}

int Inventory::getCauldrons()
{
    return cauldrons_;
}

int Inventory::getClubs()
{
    return clubs_;
}

int Inventory::getSpears()
{
    return spears_;
}

int Inventory::getRapiers()
{
    return rapiers_;
}

int Inventory::getAxes()
{
    return axes_;
}

int Inventory::getSwords()
{
    return swords_;
}

int Inventory::getNumWeapons()
{
    return num_weapons_;
}

int Inventory::getArmour()
{
    return armour_;
}

int Inventory::getRings()
{
    return rings_;
}

int Inventory::getNecklaces()
{
    return necklaces_;
}

int Inventory::getBracelets()
{
    return bracelets_;
}

int Inventory::getCirclets()
{
    return circlets_;
}

int Inventory::getGoblets()
{
    return goblets_;
}

// setters/mutators for updating components of the inventory
void Inventory::setGold(int gold)
{
    gold_ = gold_ + gold;
}

void Inventory::setIngredients(int ingredients)
{
    ingredients_ = ingredients_ + ingredients;
}

void Inventory::setPots(int pots)
{
    pots_ = pots_ + pots;
}

void Inventory::setPans(int pans)
{
    pans_ = pans_ + pans;
}

void Inventory::setCauldrons(int cauldrons)
{
    cauldrons_ = cauldrons_ + cauldrons;
}

void Inventory::setClubs(int clubs)
{
    clubs_ = clubs_ + clubs;
}

void Inventory::setSpears(int spears)
{
    spears_ = spears_ + spears;
}

void Inventory::setRapiers(int rapiers)
{
    rapiers_ = rapiers_ + rapiers;
}

void Inventory::setAxes(int axes)
{
    axes_ = axes_ + axes;
}

void Inventory::setSwords(int swords)
{
    swords_ = swords_ + swords;
}

void Inventory::setNumWeapons(int num_weapons)
{
    num_weapons_ = num_weapons_ + num_weapons;
}

void Inventory::setArmour(int armour)
{
    armour_ = armour_ + armour;
}

void Inventory::addRings(int rings)
{
    rings_ = rings_ + rings;
}

void Inventory::addNecklaces(int necklaces)
{
    necklaces_ = necklaces_ + necklaces;
}

void Inventory::addBracelets(int bracelets)
{
    bracelets_ = bracelets_ + bracelets;
}

void Inventory::addCirclets(int circlets)
{
    circlets_ = circlets_ + circlets;
}

void Inventory::addGoblets(int goblets)
{
    goblets_ = goblets_ + goblets;
}

void Inventory::sellRings(int rings)
{
    rings_ = rings_ - rings;
}

void Inventory::sellNecklaces(int necklaces)
{
    necklaces_ = necklaces_ - necklaces;
}

void Inventory::sellBracelets(int bracelets)
{
    bracelets_ = bracelets_ - bracelets;
}

void Inventory::sellCirclets(int circlets)
{
    circlets_ = circlets_ - circlets;
}

void Inventory::sellGoblets(int goblets)
{
    goblets_ = goblets_ - goblets;
}

// int main()
// {
//     Inventory inventory;
//     inventory.setIngredients(1);
//     inventory.printInventory();
//     cout << "Now we've added 1kg of ingredients to the inventory" << endl;
//     inventory.setIngredients(-1);
//     inventory.printInventory();
//     cout << "Now we've subtracted 1kg of ingredients from the inventory" << endl;
//     inventory.setGold(1);
//     inventory.printInventory();
//     cout << "Now we've added 1 gold to the inventory" << endl;
//     inventory.setPots(1);
//     inventory.printInventory();
//     cout << "Now we've added 1 pot to the inventory" << endl;
//     inventory.setPans(5);
//     inventory.printInventory();
//     cout << "Now we've added 5 pans to the inventory" << endl;
//     inventory.setCauldrons(2);
//     inventory.printInventory();
//     cout << "Now we've added 2 cauldrons to the inventory" << endl;
//     inventory.setClubs(1);
//     inventory.printInventory();
//     cout << "Now we've added 1 club to the inventory" << endl;
//     inventory.setSpears(2);
//     inventory.printInventory();
//     cout << "Now we've added 2 spears to the inventory" << endl;
//     inventory.setSwords(3);
//     inventory.printInventory();
//     cout << "Now we've added 3 swords to the inventory" << endl;
//     inventory.setRapiers(4);
//     inventory.printInventory();
//     cout << "Now we've added 4 rapiers to the inventory" << endl;
//     inventory.setAxes(5);
//     inventory.printInventory();
//     cout << "Now we've added 5 axes to the inventory" << endl;
//     inventory.setArmour(5);
//     inventory.printInventory();
//     cout << "Now we've added 5 armours to the inventory" << endl;
//     inventory.addRings(1);
//     inventory.printInventory();
//     cout << "Now we've added 1 ring to the inventory" << endl;
//     inventory.addBracelets(1);
//     inventory.printInventory();
//     cout << "Now we've added 1 braceket to the inventory" << endl;
//     inventory.addCirclets(1);
//     inventory.printInventory();
//     cout << "Now we've added 1 circlet to the inventory" << endl;
//     inventory.addGoblets(1);
//     inventory.printInventory();
//     cout << "Now we've added 1 goblet to the inventory" << endl;
//     inventory.addNecklaces(1);
//     inventory.printInventory();
//     cout << "Now we've added 1 necklace to the inventory" << endl;
//     inventory.sellRings(1);
//     inventory.printInventory();
//     cout << "Now we've subtracted 1 ring from the inventory" << endl;
//     inventory.sellNecklaces(1);
//     inventory.printInventory();
//     cout << "Now we've subtracted 1 necklace from the inventory" << endl;
//     inventory.sellGoblets(1);
//     inventory.printInventory();
//     cout << "Now we've subtracted 1 goblet from the inventory" << endl;
//     inventory.sellBracelets(1);
//     inventory.printInventory();
//     cout << "Now we've subtracted 1 bracelet from the inventory" << endl;
//     inventory.sellCirclets(1);
//     inventory.printInventory();
//     cout << "Now we've subtracted 1 circletn from the inventory" << endl;
// }
