from Karakter import Karakter

class CanBattle(Karakter):
    """Karakter yang bisa ikut pertarungan."""
    def __init__(self, name: str, gender: str, race: str, affiliation,
                 maxAP: int, maxHP: int, maxM: int, charClass: str, **kwargs):
        super().__init__(name, gender, race, affiliation, **kwargs) # Meneruskan ke Karakter
        self.maxActionPoint = maxAP
        self.maxHealth = maxHP
        self.maxMana = maxM
        self.charClass = charClass

    def display(self):
        super().display()
        print(f"  Kelas: {self.charClass}")
        print(f"  Max HP: {self.maxHealth}")
        print(f"  Max Mana: {self.maxMana}")
        print(f"  Max AP: {self.maxActionPoint}")