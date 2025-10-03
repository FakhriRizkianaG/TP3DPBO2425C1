#pragma once
#include <iostream>
#include <string>

class Abilities {
protected:
    std::string name;
    std::string description;
    std::string type; // Damage / Heal
    int cooldown; // in seconds

public:
    Abilities(std::string name, std::string description, std::string type, int cooldown)
        : name(name), description(description), type(type), cooldown(cooldown) {}

    virtual ~Abilities() = default;

    // Getter
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    std::string getType() const { return type; }
    int getCooldown() const { return cooldown; }

    // Setter
    void setName(std::string n) { name = n; }
    void setDescription(std::string d) { description = d; }
    void setType(std::string t) { type = t; }
    void setCooldown(int c) { cooldown = c; }

    // Display (virtual untuk polymorphism)
    virtual void display() const {
        std::cout << "  Kemampuan: " << name << std::endl;
        std::cout << "    Deskripsi: " << description << std::endl;
        std::cout << "    Tipe: " << type << std::endl;
        std::cout << "    Cooldown: " << cooldown << " detik" << std::endl;
    }
};