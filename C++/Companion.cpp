#pragma once
#include "FriendlyNPC.cpp"
#include "CanBattle.cpp"

class Companion : public CanBattle, public FriendlyNPC {
private:
    int fee;
    std::string grade; // F/E/D/C/B/A/S/SS

public:
    Companion(std::string name, std::string gender, std::string race, Factions* affiliation,
              int maxAP, int maxHP, int maxM, std::string charClass,
              bool is_marryable, std::string birthday, Quest* quest,
              int fee, std::string grade)
        : Karakter(name, gender, race, affiliation), // <-- Companion (most derived) initializes VIRTUAL BASE Karakter
          CanBattle(name, gender, race, affiliation, maxAP, maxHP, maxM, charClass),
          FriendlyNPC(name, gender, race, affiliation, is_marryable, birthday, quest),
          fee(fee), grade(grade) {}

    // Getter
    int getFee() const { return fee; }
    std::string getGrade() const { return grade; }

    // Setter
    void setFee(int f) { fee = f; }
    void setGrade(std::string g) { grade = g; }

    // Override Display
    void display() const override {
        // Cukup panggil salah satu base class yang menampilkan Karakter (misal FriendlyNPC)
        FriendlyNPC::display();
        
        // Menambahkan detail CanBattle yang hilang (HP/AP/Mana)
        std::cout << "  Kelas (Battle): " << CanBattle::getCharClass() << std::endl;
        std::cout << "  Max HP: " << CanBattle::getMaxHealth() << std::endl;
        std::cout << "  Max Mana: " << CanBattle::getMaxMana() << std::endl;
        std::cout << "  Max AP: " << CanBattle::getMaxActionPoint() << std::endl;

        // Detail Companion
        std::cout << "  Bayaran: " << fee << std::endl;
        std::cout << "  Peringkat: " << grade << std::endl;
    }
};