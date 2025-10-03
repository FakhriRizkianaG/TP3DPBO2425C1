from Abilities import Abilities

class Magics(Abilities):
    """Kemampuan yang menggunakan Mana."""
    def __init__(self, name: str, description: str, type: str, cooldown: int, manaCost: int, element: str):
        super().__init__(name, description, type, cooldown)
        self.manaCost = manaCost
        self.element = element

    def display(self):
        super().display()
        print(f"    Biaya Mana: {self.manaCost}")
        print(f"    Elemen: {self.element}")