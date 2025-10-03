#pragma once
#include "FriendlyNPC.cpp"

class Merchant : public FriendlyNPC {
private:
    std::string type; // Alchemist / Blacksmith / General Goods
    std::string openTime; // e.g., 07.00 - 19.00

public:
    Merchant(std::string name, std::string gender, std::string race, Factions* affiliation,
             bool is_marryable, std::string birthday, Quest* quest,
             std::string type, std::string openTime)
        : Karakter(name, gender, race, affiliation), // Merchant (the most derived) initializes Karakter
          FriendlyNPC(name, gender, race, affiliation, is_marryable, birthday, quest),
          type(type), openTime(openTime) {}

    // Override Display
    void display() const override {
        FriendlyNPC::display();
        std::cout << "  Tipe Pedagang: " << type << std::endl;
        std::cout << "  Jam Buka: " << openTime << std::endl;
    }
};