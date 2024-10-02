#include "Merchant.h"
#include <iostream>

using namespace std;

// base prices for default constructor
Merchant::Merchant()
{
    pan_price = 10;
    pot_price = 5;
    cauldron_price = 20;
    axe_price = 15;
    sword_price = 50;
    rapier_price = 5;
    spear_price = 2;
    club_price = 2;
    armour_price = 5;
    ingredients_price = 1;
    ring_price = 10;
    necklace_price = 20;
    bracelet_price = 30;
    circlet_price = 40;
    goblet_price = 50;
}

// function updates merchants prices depending on num_rooms_cleared
// returns void
// parameters: int num_rooms_cleared
void Merchant::Merchant_updater(int num_rooms_cleared)
{
    if (num_rooms_cleared == 0) // if 0 rooms cleared
    {
        Merchant(); // base prices applied
    }
    else if (num_rooms_cleared == 1) // if 1 rooms cleared
    {
        double cost_mult = 0.25; // 25% multiplier applied
        setPanPrice(cost_mult);
        setPotPrice(cost_mult);
        setCauldronPrice(cost_mult);
        setAxePrice(cost_mult);
        setSwordPrice(cost_mult);
        setRapierPrice(cost_mult);
        setSpearPrice(cost_mult);
        setClubPrice(cost_mult);
        setIngredientsPrice(cost_mult);
        setArmourPrice(cost_mult);
    }
    else if (num_rooms_cleared == 2) // if 2 rooms cleared
    {
        double cost_mult = 0.50; // 50% multiplier applied
        setPanPrice(cost_mult);
        setPotPrice(cost_mult);
        setCauldronPrice(cost_mult);
        setAxePrice(cost_mult);
        setSwordPrice(cost_mult);
        setRapierPrice(cost_mult);
        setSpearPrice(cost_mult);
        setClubPrice(cost_mult);
        setIngredientsPrice(cost_mult);
        setArmourPrice(cost_mult);
    }
    else if (num_rooms_cleared == 3) // if 3 rooms cleared
    {
        double cost_mult = 0.75; // 75% multiplier applied
        setPanPrice(cost_mult);
        setPotPrice(cost_mult);
        setCauldronPrice(cost_mult);
        setAxePrice(cost_mult);
        setSwordPrice(cost_mult);
        setRapierPrice(cost_mult);
        setSpearPrice(cost_mult);
        setClubPrice(cost_mult);
        setIngredientsPrice(cost_mult);
        setArmourPrice(cost_mult);
    }
    else if (num_rooms_cleared == 4) // if 4 rooms cleared
    {
        double cost_mult = 1.00; // 100% multiplier applied
        setPanPrice(cost_mult);
        setPotPrice(cost_mult);
        setCauldronPrice(cost_mult);
        setAxePrice(cost_mult);
        setSwordPrice(cost_mult);
        setRapierPrice(cost_mult);
        setSpearPrice(cost_mult);
        setClubPrice(cost_mult);
        setIngredientsPrice(cost_mult);
        setArmourPrice(cost_mult);
    }
    else if (num_rooms_cleared == 5) // if 5 rooms cleared
    {
        double cost_mult = 1.25; // 125% multiplier applied
        setPanPrice(cost_mult);
        setPotPrice(cost_mult);
        setCauldronPrice(cost_mult);
        setAxePrice(cost_mult);
        setSwordPrice(cost_mult);
        setRapierPrice(cost_mult);
        setSpearPrice(cost_mult);
        setClubPrice(cost_mult);
        setIngredientsPrice(cost_mult);
        setArmourPrice(cost_mult);
    }
}

// getters/accessors
int Merchant::getPanPrice()
{
    return pan_price;
}

int Merchant::getPotPrice()
{
    return pot_price;
}

int Merchant::getCauldronPrice()
{
    return cauldron_price;
}

int Merchant::getAxePrice()
{
    return axe_price;
}

int Merchant::getSwordPrice()
{
    return sword_price;
}

int Merchant::getRapierPrice()
{
    return rapier_price;
}

int Merchant::getSpearPrice()
{
    return spear_price;
}

int Merchant::getClubPrice()
{
    return club_price;
}

int Merchant::getGobletPrice()
{
    return goblet_price;
}

int Merchant::getCircletPrice()
{
    return circlet_price;
}

int Merchant::getBraceletPrice()
{
    return bracelet_price;
}

int Merchant::getNecklacePrice()
{
    return necklace_price;
}

int Merchant::getRingPrice()
{
    return ring_price;
}

int Merchant::getIngredientsPrice()
{
    return ingredients_price;
}

int Merchant::getArmourPrice()
{
    return armour_price;
}

// setters/mutators take in price multiplier and return newly updated values
void Merchant::setPanPrice(double cost_mult)
{
    pan_price = pan_price + (pan_price * cost_mult);
}

void Merchant::setPotPrice(double cost_mult)
{
    pot_price = pot_price + (pot_price * cost_mult);
}

void Merchant::setCauldronPrice(double cost_mult)
{
    cauldron_price = cauldron_price + (cauldron_price * cost_mult);
}

void Merchant::setAxePrice(double cost_mult)
{
    axe_price = axe_price + (axe_price * cost_mult);
}

void Merchant::setSwordPrice(double cost_mult)
{
    sword_price = sword_price + (sword_price * cost_mult);
}

void Merchant::setRapierPrice(double cost_mult)
{
    rapier_price = rapier_price + (rapier_price * cost_mult);
}

void Merchant::setSpearPrice(double cost_mult)
{
    spear_price = spear_price + (spear_price * cost_mult);
}

void Merchant::setClubPrice(double cost_mult)
{
    club_price = club_price + (club_price * cost_mult);
}

void Merchant::setIngredientsPrice(double cost_mult)
{
    ingredients_price = ingredients_price + (ingredients_price * cost_mult);
}

void Merchant::setArmourPrice(double cost_mult)
{
    armour_price = armour_price + (armour_price * cost_mult);
}

// int main()
// {
//     Merchant Merchant;
//     cout << Merchant.getIngredientsPrice() << endl;
//     cout << Merchant.getPotPrice() << endl;
//     cout << Merchant.getPanPrice() << endl;
//     cout << Merchant.getCauldronPrice() << endl;
//     cout << Merchant.getClubPrice() << endl;
//     cout << Merchant.getAxePrice() << endl;
//     cout << Merchant.getRapierPrice() << endl;
//     cout << Merchant.getSwordPrice() << endl;
//     cout << Merchant.getSpearPrice() << endl;
//     cout << Merchant.getRingPrice() << endl;
//     cout << Merchant.getBraceletPrice() << endl;
//     cout << Merchant.getNecklacePrice() << endl;
//     cout << Merchant.getCircletPrice() << endl;
//     cout << Merchant.getGobletPrice() << endl;
//     cout << Merchant.getIngredientsPrice() << endl;
//     cout << Merchant.getPotPrice() << endl;
//     cout << Merchant.getPanPrice() << endl;
//     cout << Merchant.getCauldronPrice() << endl;
//     cout << Merchant.getClubPrice() << endl;
//     cout << Merchant.getAxePrice() << endl;
//     cout << Merchant.getRapierPrice() << endl;
//     cout << Merchant.getSwordPrice() << endl;
//     cout << Merchant.getSpearPrice() << endl;
//     cout << Merchant.getRingPrice() << endl;
//     cout << Merchant.getBraceletPrice() << endl;
//     cout << Merchant.getNecklacePrice() << endl;
//     cout << Merchant.getCircletPrice() << endl;
//     cout << Merchant.getGobletPrice() << endl;
// }