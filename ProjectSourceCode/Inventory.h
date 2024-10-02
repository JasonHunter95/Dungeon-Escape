#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory
{
private: // data that the inventory contains
    int gold_;
    int ingredients_;
    int pots_, pans_, cauldrons_;
    int clubs_, spears_, rapiers_, axes_, swords_;
    int num_weapons_;
    int armour_;
    int rings_, necklaces_, bracelets_, circlets_, goblets_;

public:
    Inventory();           // default constructor
    void printInventory(); // prints current inventory contents
    // getters/accessors
    int getGold();
    int getIngredients();
    int getPots();
    int getPans();
    int getCauldrons();
    int getClubs();
    int getSpears();
    int getRapiers();
    int getAxes();
    int getSwords();
    int getNumWeapons();
    int getArmour();
    int getRings();
    int getNecklaces();
    int getBracelets();
    int getCirclets();
    int getGoblets();

    // setters/mutators
    void setGold(int gold);
    void setIngredients(int ingredients);
    void setPots(int pots);
    void setPans(int pans);
    void setCauldrons(int cauldrons);
    void setClubs(int clubs);
    void setSpears(int spears);
    void setRapiers(int rapiers);
    void setAxes(int axes);
    void setSwords(int swords);
    void setNumWeapons(int num_weapons);
    void setArmour(int armour);
    void addRings(int rings);
    void addNecklaces(int necklaces);
    void addBracelets(int bracelets);
    void addCirclets(int circlets);
    void addGoblets(int goblets);
    void sellRings(int rings);
    void sellNecklaces(int necklaces);
    void sellBracelets(int bracelets);
    void sellCirclets(int circlets);
    void sellGoblets(int goblets);
};

#endif