#pragma once
#include "Karakter.cpp"

class CanBattle : public virtual Karakter { // <-- VIRTUAL INHERITANCE
protected:
    int maxActionPoint;
    int maxHealth;
    int maxMana;
    std::string charClass; // class

public:
    CanBattle(std::string name, std::string gender, std::string race, Factions* affiliation,
              int maxAP, int maxHP, int maxM, std::string charClass)
        // Karakter(name, gender, race, affiliation) tidak dieksekusi oleh CanBattle jika diwariskan secara virtual
        // kecuali CanBattle adalah kelas yang paling diturunkan.
        : Karakter(name, gender, race, affiliation), // Tetap ada, tapi hanya dipanggil jika CanBattle bukan virtual base.
          maxActionPoint(maxAP), maxHealth(maxHP), maxMana(maxM), charClass(charClass) {}

    // Getter
    int getMaxActionPoint() const { return maxActionPoint; }
    int getMaxHealth() const { return maxHealth; }
    int getMaxMana() const { return maxMana; }
    std::string getCharClass() const { return charClass; }

    // Setter
    void setMaxActionPoint(int ap) { maxActionPoint = ap; }
    void setMaxHealth(int hp) { maxHealth = hp; }
    void setMaxMana(int m) { maxMana = m; }
    void setCharClass(std::string c) { charClass = c; }

    // Override Display
    void display() const override {
        Karakter::display();
        std::cout << "  Kelas: " << charClass << std::endl;
        std::cout << "  Max HP: " << maxHealth << std::endl;
        std::cout << "  Max Mana: " << maxMana << std::endl;
        std::cout << "  Max AP: " << maxActionPoint << std::endl;
    }
};