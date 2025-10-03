#pragma once
#include "CanBattle.cpp"

class Enemies : public CanBattle {
private:
    bool is_elite;
    bool is_escapable;

public:
    Enemies(std::string name, std::string gender, std::string race, Factions* affiliation,
            int maxAP, int maxHP, int maxM, std::string charClass,
            bool is_elite, bool is_escapable)
        : Karakter(name, gender, race, affiliation), // Enemies (the most derived) initializes Karakter
          CanBattle(name, gender, race, affiliation, maxAP, maxHP, maxM, charClass),
          is_elite(is_elite), is_escapable(is_escapable) {}

    // Getter
    bool getIsElite() const { return is_elite; }
    bool getIsEscapable() const { return is_escapable; }

    // Setter
    void setIsElite(bool e) { is_elite = e; }
    void setIsEscapable(bool e) { is_escapable = e; }

    // Override Display
    void display() const override {
        CanBattle::display();
        std::cout << "  Elite: " << (is_elite ? "Ya" : "Tidak") << std::endl;
        std::cout << "  Bisa Dilarikan: " << (is_escapable ? "Ya" : "Tidak") << std::endl;
    }
};