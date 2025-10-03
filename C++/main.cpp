#include <iostream>
#include <vector>
#include <string>
#include <memory> 

// Include semua file kelas
#include "Factions.cpp"
#include "Quest.cpp"
#include "Abilities.cpp"
#include "Skills.cpp"
#include "Magics.cpp"
#include "Karakter.cpp"
#include "CanBattle.cpp"
#include "FriendlyNPC.cpp"
#include "Player.cpp"
#include "Enemies.cpp"
#include "Companion.cpp"
#include "Merchant.cpp"
#include "Trainer.cpp"

using namespace std;

// Fungsi untuk menampilkan data ketika kosong
void displayEmptyData() {
    cout << "===========================================" << endl;
    cout << "          DATA AWAL (KOSONG)" << endl;
    cout << "===========================================" << endl;
    cout << "Objek Karakter, Faksi, Quest, dan Kemampuan belum dibuat." << endl;
    cout << "===========================================" << endl << endl;
}

// Fungsi untuk menampilkan data yang sudah terisi
void displayData(const Player& player, const Factions& faction, const vector<Karakter*>& allKarakters, const vector<Abilities*>& allAbilities) {
    cout << "===========================================" << endl;
    cout << "          DATA SETELAH PENGISIAN" << endl;
    cout << "===========================================" << endl;

    cout << "-------------------------------------------" << endl;
    cout << "=> FAKSI" << endl;
    faction.display();
    cout << "-------------------------------------------" << endl;

    cout << "=> PLAYER" << endl;
    player.display();
    cout << "-------------------------------------------" << endl;

    cout << "=> SEMUA KARAKTER LAIN (NPC & ENEMIES)" << endl;
    for (size_t i = 0; i < allKarakters.size(); ++i) {
        allKarakters[i]->display();
        if (i < allKarakters.size() - 1) {
            cout << "---" << endl;
        }
    }
    cout << "-------------------------------------------" << endl;

    cout << "=> SEMUA KEMAMPUAN (SKILLS & MAGICS)" << endl;
    for (size_t i = 0; i < allAbilities.size(); ++i) {
        allAbilities[i]->display();
        if (i < allAbilities.size() - 1) {
            cout << "---" << endl;
        }
    }
    cout << "===========================================" << endl;
}

int main() {
    // Tampilkan data kosong sebelum objek dibuat
    displayEmptyData();

    // --- PEMBUATAN OBJEK DAN RELASI ---

    // 1. Buat Faksi
    Factions* FaksiKsatria = new Factions("Ksatria Baja Hitam", "Faksi para ksatria yang menjunjung tinggi keadilan.");
    Factions* FaksiDark = new Factions("Shadow Syndicate", "Kelompok gelap yang mengincar kekuasaan dunia.");

    // 2. Buat Abilities (Skills & Magics) - Aggregation (Player)
    Skills* SkillTebasan = new Skills("Tebasan Kilat", "Serangan cepat pedang", "Damage", 5, 10);
    Magics* MagicApi = new Magics("Bola Api", "Lemparkan bola api besar", "Damage", 15, 20, "Fire");
    Skills* SkillHeal = new Skills("Penyembuhan Ringan", "Memulihkan sedikit HP", "Heal", 10, 5);

    // 3. Buat Quest - Aggregation (Player) & Composition (FriendlyNPC)
    Quest* questPlayer = new Quest("Bunuh Raja Goblin", "Kalahkan raja goblin di hutan gelap.");
    Quest* compQuest = new Quest("Cari Bunga Langka", "Temukan Bunga Langka untuk hadiah pernikahan.");

    // 4. Buat Player - Aggregation (Factions, Skills, Magics, Quest)
    Player userPlayer("Arashi", "Pria", "Manusia", FaksiKsatria, 150, 1000, 500, "Knight", 50);
    userPlayer.addSkill(SkillTebasan);
    userPlayer.addMagic(MagicApi);
    userPlayer.addQuest(questPlayer);

    // 5. Buat Enemies
    Enemies* enemyGoblin = new Enemies("Goblin Grunt", "Pria", "Goblin", nullptr, 50, 200, 0, "Goblin Berserker", false, true);

    // 6. Buat FriendlyNPC
    FriendlyNPC* npcBiasa = new FriendlyNPC("Aisha", "Wanita", "Elf", FaksiKsatria, true, "15 Mei", nullptr);
    Merchant* merchantUmum = new Merchant("Kleo", "Wanita", "Dwarf", nullptr, false, "12 Des", nullptr, "General Goods", "09.00 - 17.00");
    Trainer* trainerHP = new Trainer("Garrus", "Pria", "Orc", FaksiKsatria, false, "01 Jan", nullptr, 500, "Health");

    // 7. Buat Companion - Composition (Quest)
    Companion* compMage = new Companion(
        "Luna", "Wanita", "Peri", FaksiDark,
        100, 500, 800, "Mage",
        true, "21 Maret", compQuest, 
        1000, "A"
    );

    // Koleksi untuk menampilkan data
    vector<Karakter*> allKarakters;
    allKarakters.push_back(npcBiasa);
    allKarakters.push_back(merchantUmum);
    allKarakters.push_back(trainerHP);
    allKarakters.push_back(compMage);
    allKarakters.push_back(enemyGoblin);

    vector<Abilities*> allAbilities;
    allAbilities.push_back(SkillTebasan);
    allAbilities.push_back(MagicApi);
    allAbilities.push_back(SkillHeal);

    // Tampilkan data setelah pengisian
    displayData(userPlayer, *FaksiKsatria, allKarakters, allAbilities);

    // // --- CLEANUP MEMORY ---
    // delete FaksiKsatria;
    // delete FaksiDark;
    
    // // Aggregation objects
    // delete SkillTebasan;
    // delete MagicApi;
    // delete SkillHeal;
    // delete questPlayer;

    // // Karakter lainnya (Destructor FriendlyNPC akan menghapus quest-nya)
    // delete enemyGoblin;
    // delete npcBiasa;
    // delete merchantUmum;
    // delete trainerHP;
    // delete compMage; 

    return 0;
}