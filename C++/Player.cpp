#pragma once
#include "CanBattle.cpp"
#include "Skills.cpp"
#include "Magics.cpp"
#include "Quest.cpp"
#include <vector>

class Player : public CanBattle {
private:
    int level;
    std::vector<Skills*> skillOwned; // Aggregation
    std::vector<Magics*> magicOwned; // Aggregation
    std::vector<Quest*> activeQuest; // Aggregation

public:
    Player(std::string name, std::string gender, std::string race, Factions* affiliation,
           int maxAP, int maxHP, int maxM, std::string charClass, int level)
        : Karakter(name, gender, race, affiliation), // Player (the most derived) initializes Karakter
          CanBattle(name, gender, race, affiliation, maxAP, maxHP, maxM, charClass), 
          level(level) {}

    // Destructor (Aggregasi tidak menghapus, tapi bagus untuk housekeeping)
    ~Player() = default;

    // Getter/Adder
    void addSkill(Skills* s) { skillOwned.push_back(s); }
    void addMagic(Magics* m) { magicOwned.push_back(m); }
    void addQuest(Quest* q) { activeQuest.push_back(q); }

    // Override Display
    void display() const override {
        CanBattle::display();
        std::cout << "  Level: " << level << std::endl;

        std::cout << "  Skills Dimiliki (" << skillOwned.size() << "):" << std::endl;
        if (skillOwned.empty()) {
            std::cout << "    Tidak ada skill." << std::endl;
        } else {
            for (const auto& skill : skillOwned) {
                skill->display();
            }
        }

        std::cout << "  Magics Dimiliki (" << magicOwned.size() << "):" << std::endl;
        if (magicOwned.empty()) {
            std::cout << "    Tidak ada magic." << std::endl;
        } else {
            for (const auto& magic : magicOwned) {
                magic->display();
            }
        }

        std::cout << "  Quest Aktif (" << activeQuest.size() << "):" << std::endl;
        if (activeQuest.empty()) {
            std::cout << "    Tidak ada quest aktif." << std::endl;
        } else {
            for (const auto& quest : activeQuest) {
                quest->display();
            }
        }
    }
};