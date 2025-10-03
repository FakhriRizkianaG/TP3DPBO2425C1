from Abilities import Abilities

class Skills(Abilities):
    """Kemampuan yang menggunakan Action Point (AP)."""
    def __init__(self, name: str, description: str, type: str, cooldown: int, apCost: int):
        super().__init__(name, description, type, cooldown)
        self.apCost = apCost

    def display(self):
        super().display()
        print(f"    Biaya AP: {self.apCost}")