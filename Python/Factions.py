class Factions:
    """Faksi atau guild."""
    def __init__(self, name: str, desc: str):
        self.name = name
        self.desc = desc

    def display(self):
        print(f"  Faksi: {self.name}")
        print(f"    Deskripsi: {self.desc}")