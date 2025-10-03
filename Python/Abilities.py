class Abilities:
    """Kemampuan yang bisa digunakan oleh player (Base Class)."""
    def __init__(self, name: str, description: str, type: str, cooldown: int):
        self.name = name
        self.description = description
        self.type = type
        self.cooldown = cooldown

    def display(self):
        print(f"  Kemampuan: {self.name}")
        print(f"    Deskripsi: {self.description}")
        print(f"    Tipe: {self.type}")
        print(f"    Cooldown: {self.cooldown} detik")