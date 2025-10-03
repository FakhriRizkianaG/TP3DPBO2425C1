#pragma once
#include "FriendlyNPC.cpp"

class Trainer : public FriendlyNPC {
private:
    int fee;
    std::string trainingType; // Health / Mana / ActionPoint

public:
    Trainer(std::string name, std::string gender, std::string race, Factions* affiliation,
            bool is_marryable, std::string birthday, Quest* quest,
            int fee, std::string trainingType)
        : Karakter(name, gender, race, affiliation), // Trainer (the most derived) initializes Karakter
          FriendlyNPC(name, gender, race, affiliation, is_marryable, birthday, quest),
          fee(fee), trainingType(trainingType) {}

    // Override Display
    void display() const override {
        FriendlyNPC::display();
        std::cout << "  Bayaran: " << fee << std::endl;
        std::cout << "  Tipe Latihan: " << trainingType << std::endl;
    }
};