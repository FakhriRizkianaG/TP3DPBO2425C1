from CanBattle import CanBattle
from Skills import Skills
from Magics import Magics
from Quest import Quest

class Player(CanBattle):
    """Karakter yang dimainkan oleh user."""
    def __init__(self, name: str, gender: str, race: str, affiliation,
                 maxAP: int, maxHP: int, maxM: int, charClass: str, level: int, **kwargs):
        super().__init__(name, gender, race, affiliation, maxAP, maxHP, maxM, charClass, **kwargs) # Meneruskan ke CanBattle
        self.level = level
        self.skillOwned = []
        self.magicOwned = []
        self.activeQuest = []

    def add_skill(self, skill: Skills):
        self.skillOwned.append(skill)
        
    def add_magic(self, magic: Magics):
        self.magicOwned.append(magic)
        
    def add_quest(self, quest: Quest):
        self.activeQuest.append(quest)

    def display(self):
        super().display()
        print(f"  Level: {self.level}")

        print(f"  Skills Dimiliki ({len(self.skillOwned)}):")
        if not self.skillOwned:
            print("    Tidak ada skill.")
        for skill in self.skillOwned:
            skill.display()

        print(f"  Magics Dimiliki ({len(self.magicOwned)}):")
        if not self.magicOwned:
            print("    Tidak ada magic.")
        for magic in self.magicOwned:
            magic.display()

        print(f"  Quest Aktif ({len(self.activeQuest)}):" )
        if not self.activeQuest:
            print("    Tidak ada quest aktif.")
        for quest in self.activeQuest:
            quest.display()