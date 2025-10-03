from CanBattle import CanBattle

class Enemies(CanBattle):
    """Karakter hostile."""
    def __init__(self, name: str, gender: str, race: str, affiliation,
                 maxAP: int, maxHP: int, maxM: int, charClass: str,
                 is_elite: bool, is_escapable: bool, **kwargs):
        super().__init__(name, gender, race, affiliation, maxAP, maxHP, maxM, charClass, **kwargs) # Meneruskan ke CanBattle
        self.is_elite = is_elite
        self.is_escapable = is_escapable

    def display(self):
        super().display()
        elite_status = "Ya" if self.is_elite else "Tidak"
        escape_status = "Ya" if self.is_escapable else "Tidak"
        print(f"  Elite: {elite_status}")
        print(f"  Bisa Dilarikan: {escape_status}")