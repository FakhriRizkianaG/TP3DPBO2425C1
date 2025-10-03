#pragma once
#include <iostream>
#include <string>

class Quest {
private:
    std::string name;
    std::string desc;

public:
    Quest(std::string name, std::string desc) : name(name), desc(desc) {}

    // Getter
    std::string getName() const { return name; }
    std::string getDesc() const { return desc; }

    // Setter
    void setName(std::string n) { name = n; }
    void setDesc(std::string d) { desc = d; }

    // Display
    void display() const {
        std::cout << "  Quest: " << name << std::endl;
        std::cout << "    Deskripsi: " << desc << std::endl;
    }
};