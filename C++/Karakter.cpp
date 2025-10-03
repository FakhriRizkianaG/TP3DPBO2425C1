#pragma once
#include <iostream>
#include <string>
#include "Factions.cpp"

class Karakter {
protected:
    std::string name;
    std::string gender;
    std::string race;
    Factions* affiliation; // Aggregation (0..1)

public:
    // Konstruktor ini akan dipanggil oleh Companion (most derived class)
    Karakter(std::string name, std::string gender, std::string race, Factions* affiliation = nullptr)
        : name(name), gender(gender), race(race), affiliation(affiliation) {}

    virtual ~Karakter() = default;

    // Getter
    std::string getName() const { return name; }
    std::string getGender() const { return gender; }
    std::string getRace() const { return race; }
    Factions* getAffiliation() const { return affiliation; }

    // Setter
    void setName(std::string n) { name = n; }
    void setGender(std::string g) { gender = g; }
    void setRace(std::string r) { race = r; }
    void setAffiliation(Factions* f) { affiliation = f; }

    // Display (virtual)
    virtual void display() const {
        std::cout << "Nama: " << name << std::endl;
        std::cout << "  Gender: " << gender << std::endl;
        std::cout << "  Ras: " << race << std::endl;
        std::cout << "  Afiliasi: ";
        if (affiliation) {
            std::cout << affiliation->getName() << std::endl;
        } else {
            std::cout << "Tidak Berafiliasi" << std::endl;
        }
    }
};