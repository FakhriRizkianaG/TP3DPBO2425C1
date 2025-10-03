#pragma once
#include "Abilities.cpp"

class Skills : public Abilities {
private:
    int apCost;

public:
    Skills(std::string name, std::string description, std::string type, int cooldown, int apCost)
        : Abilities(name, description, type, cooldown), apCost(apCost) {}

    // Getter
    int getApCost() const { return apCost; }

    // Setter
    void setApCost(int ap) { apCost = ap; }

    // Override Display
    void display() const override {
        Abilities::display();
        std::cout << "    Biaya AP: " << apCost << std::endl;
    }
};