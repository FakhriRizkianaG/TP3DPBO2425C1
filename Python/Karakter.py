from Factions import Factions

class Karakter:
    """Mencakup semua karakter yang ada di game ini (Base Class)."""
    def __init__(self, name: str, gender: str, race: str, affiliation: Factions = None, **kwargs):
        # Menerima **kwargs tapi mengabaikannya karena ini adalah kelas dasar
        self.name = name
        self.gender = gender
        self.race = race
        self.affiliation = affiliation

    def display(self):
        print(f"Nama: {self.name}")
        print(f"  Gender: {self.gender}")
        print(f"  Ras: {self.race}")
        
        aff_name = self.affiliation.name if self.affiliation else "Tidak Berafiliasi"
        print(f"  Afiliasi: {aff_name}")