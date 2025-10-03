from FriendlyNPC import FriendlyNPC
from CanBattle import CanBattle

class Companion(FriendlyNPC, CanBattle):
    """FriendlyNPC yang bisa ikut bertarung dengan player."""
    def __init__(self, name: str, gender: str, race: str, affiliation,
                 maxAP: int, maxHP: int, maxM: int, charClass: str,
                 is_marryable: bool, birthday: str, haveQuest,
                 fee: int, grade: str):
        
        # Panggil konstruktor kelas berikutnya dalam MRO, 
        # meneruskan SEMUA argumen yang dibutuhkan oleh FriendlyNPC dan CanBattle.
        # Python MRO akan memastikan setiap base class mendapatkan argumen yang tepat.
        super().__init__(name=name, gender=gender, race=race, affiliation=affiliation,
                         is_marryable=is_marryable, birthday=birthday, haveQuest=haveQuest,
                         maxAP=maxAP, maxHP=maxHP, maxM=maxM, charClass=charClass)
                         
        self.fee = fee
        self.grade = grade

    def display(self):
        # Memanggil display secara eksplisit untuk menghindari duplikasi display Karakter
        FriendlyNPC.display(self) 
        
        # Tampilkan detail CanBattle yang unik (sudah ter-init di super())
        print(f"  Kelas (Battle): {self.charClass}")
        print(f"  Max HP: {self.maxHealth}")
        print(f"  Max Mana: {self.maxMana}")
        print(f"  Max AP: {self.maxActionPoint}")
        
        # Detail Companion
        print(f"  Bayaran: {self.fee}")
        print(f"  Peringkat: {self.grade}")