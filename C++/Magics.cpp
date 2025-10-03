#pragma once
#include "Abilities.cpp"

class Magics : public Abilities {
private:
    int manaCost;
    std::string element; // Fire / Water / Earth / Wind / Dark / Light

public:
    Magics(std::string name, std::string description, std::string type, int cooldown, int manaCost, std::string element)
        : Abilities(name, description, type, cooldown), manaCost(manaCost), element(element) {}

    // Getter
    int getManaCost() const { return manaCost; }
    std::string getElement() const { return element; }

    // Setter
    void setManaCost(int mc) { manaCost = mc; }
    void setElement(std::string e) { element = e; }

    // Override Display
    void display() const override {
        Abilities::display();
        std::cout << "    Biaya Mana: " << manaCost << std::endl;
        std::cout << "    Elemen: " << element << std::endl;
    }
};