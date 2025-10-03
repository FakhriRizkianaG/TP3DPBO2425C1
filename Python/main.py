from Factions import Factions
from Quest import Quest
from Skills import Skills
from Magics import Magics
from Karakter import Karakter # Import Karakter untuk type hinting di fungsi
from Player import Player
from Enemies import Enemies
from FriendlyNPC import FriendlyNPC
from Companion import Companion
from Merchant import Merchant
from Trainer import Trainer

def display_empty_data():
    print("=" * 43)
    print("          DATA AWAL (KOSONG)")
    print("=" * 43)
    print("Objek Karakter, Faksi, Quest, dan Kemampuan belum dibuat.")
    print("=" * 43 + "\n")

def display_data(player: Player, faction: Factions, all_karakters: list[Karakter], all_abilities: list):
    print("=" * 43)
    print("          DATA SETELAH PENGISIAN")
    print("=" * 43)

    print("-------------------------------------------")
    print("=> FAKSI")
    faction.display()
    print("-------------------------------------------")

    print("=> PLAYER")
    player.display()
    print("-------------------------------------------")

    print("=> SEMUA KARAKTER LAIN (NPC & ENEMIES)")
    for i, k in enumerate(all_karakters):
        k.display()
        if i < len(all_karakters) - 1:
            print("---")
    print("-------------------------------------------")

    print("=> SEMUA KEMAMPUAN (SKILLS & MAGICS)")
    for i, a in enumerate(all_abilities):
        a.display()
        if i < len(all_abilities) - 1:
            print("---")
    print("=" * 43)

def main():
    display_empty_data()

    # 1. Buat Faksi
    faksi_ksatria = Factions("Ksatria Baja Hitam", "Faksi para ksatria yang menjunjung tinggi keadilan.")
    faksi_dark = Factions("Shadow Syndicate", "Kelompok gelap yang mengincar kekuasaan dunia.")

    # 2. Buat Abilities
    skill_tebasan = Skills("Tebasan Kilat", "Serangan cepat pedang", "Damage", 5, 10)
    magic_api = Magics("Bola Api", "Lemparkan bola api besar", "Damage", 15, 20, "Fire")
    skill_heal = Skills("Penyembuhan Ringan", "Memulihkan sedikit HP", "Heal", 10, 5)

    # 3. Buat Quest
    quest_player = Quest("Bunuh Raja Goblin", "Kalahkan raja goblin di hutan gelap.")
    comp_quest = Quest("Cari Bunga Langka", "Temukan Bunga Langka untuk hadiah pernikahan.")
    npc_quest_base = Quest("Misi Pengiriman", "Antar paket ke kota sebelah.")

    # 4. Buat Player
    user_player = Player("Arashi", "Pria", "Manusia", faksi_ksatria, 150, 1000, 500, "Knight", 50)
    user_player.add_skill(skill_tebasan)
    user_player.add_magic(magic_api)
    user_player.add_quest(quest_player)

    # 5. Buat Enemies
    enemy_goblin = Enemies("Goblin Grunt", "Pria", "Goblin", None, 50, 200, 0, "Goblin Berserker", False, True)

    # 6. Buat FriendlyNPC
    npc_biasa = FriendlyNPC("Aisha", "Wanita", "Elf", faksi_ksatria, True, "15 Mei", None)
    merchant_umum = Merchant("Kleo", "Wanita", "Dwarf", None, False, "12 Des", npc_quest_base, "General Goods", "09.00 - 17.00")
    trainer_hp = Trainer("Garrus", "Pria", "Orc", faksi_ksatria, False, "01 Jan", None, 500, "Health")

    # 7. Buat Companion - Multiple Inheritance
    comp_mage = Companion(
        "Luna", "Wanita", "Peri", faksi_dark,
        100, 500, 800, "Mage",
        True, "21 Maret", comp_quest, 
        1000, "A"
    )

    # Koleksi untuk menampilkan data
    all_karakters = [npc_biasa, merchant_umum, trainer_hp, comp_mage, enemy_goblin]
    all_abilities = [skill_tebasan, magic_api, skill_heal]

    display_data(user_player, faksi_ksatria, all_karakters, all_abilities)

if __name__ == "__main__":
    main()