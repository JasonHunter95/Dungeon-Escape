// this class contains the merchant functions relating to various multipliers applied throughout the game depending on rooms cleared

#ifndef MERCHANT_H
#define MERCHANT_H

class Merchant
{
private:
    // base prices declared here
    int pan_price = 10;
    int pot_price = 5;
    int cauldron_price = 20;
    int axe_price = 15;
    int sword_price = 50;
    int rapier_price = 5;
    int spear_price = 2;
    int club_price = 2;
    int armour_price = 5;
    int ingredients_price = 1;
    int ring_price = 10;
    int necklace_price = 20;
    int bracelet_price = 30;
    int circlet_price = 40;
    int goblet_price = 50;

public:
    Merchant();                                   // default constructor
    void Merchant_updater(int num_rooms_cleared); // updates merchant based on how many rooms have been cleared

    // getters/accessors for prices
    int getPanPrice();
    int getPotPrice();
    int getCauldronPrice();
    int getAxePrice();
    int getSwordPrice();
    int getRapierPrice();
    int getSpearPrice();
    int getClubPrice();
    int getGobletPrice();
    int getCircletPrice();
    int getBraceletPrice();
    int getNecklacePrice();
    int getRingPrice();
    int getIngredientsPrice();
    int getArmourPrice();

    // setters/mutators to update prices
    void setPanPrice(double cost_mult);
    void setPotPrice(double cost_mult);
    void setCauldronPrice(double cost_mult);
    void setAxePrice(double cost_mult);
    void setSwordPrice(double cost_mult);
    void setRapierPrice(double cost_mult);
    void setSpearPrice(double cost_mult);
    void setClubPrice(double cost_mult);
    void setIngredientsPrice(double cost_mult);
    void setArmourPrice(double cost_mult);
};

#endif