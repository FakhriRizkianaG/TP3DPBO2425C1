#pragma once
#include "Karakter.cpp"
#include "Quest.cpp"
#include <memory> 

class FriendlyNPC : public virtual Karakter { // <-- VIRTUAL INHERITANCE
protected:
    bool is_marryable;
    std::string birthday;
    std::unique_ptr<Quest> haveQuest; // Composition

public:
    FriendlyNPC(std::string name, std::string gender, std::string race, Factions* affiliation,
                bool is_marryable, std::string birthday, Quest* quest = nullptr)
        // Karakter(name, gender, race, affiliation) tidak dieksekusi oleh FriendlyNPC jika diwariskan secara virtual.
        : Karakter(name, gender, race, affiliation), 
          is_marryable(is_marryable), birthday(birthday), haveQuest(quest) {}
    
    // Getter
    bool getIsMarryable() const { return is_marryable; }
    std::string getBirthday() const { return birthday; }
    Quest* getHaveQuest() const { return haveQuest.get(); }

    // Setter
    void setIsMarryable(bool m) { is_marryable = m; }
    void setBirthday(std::string b) { birthday = b; }
    void setQuest(Quest* q) {
        haveQuest.reset(q);
    }

    // Override Display
    void display() const override {
        Karakter::display();
        std::cout << "  Bisa Dinikahi: " << (is_marryable ? "Ya" : "Tidak") << std::endl;
        std::cout << "  Ulang Tahun: " << birthday << std::endl;
        std::cout << "  Quest yang Ditawarkan: ";
        if (haveQuest) {
            std::cout << haveQuest->getName() << std::endl;
            haveQuest->display();
        } else {
            std::cout << "Tidak ada Quest" << std::endl;
        }
    }
};