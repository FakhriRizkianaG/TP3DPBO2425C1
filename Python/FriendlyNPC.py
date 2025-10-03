from Karakter import Karakter
from Quest import Quest

class FriendlyNPC(Karakter):
    """Karakter yang bersifat friendly ke player."""
    def __init__(self, name: str, gender: str, race: str, affiliation,
                 is_marryable: bool, birthday: str, haveQuest: Quest = None, **kwargs):
        super().__init__(name, gender, race, affiliation, **kwargs) # Meneruskan ke Karakter
        self.is_marryable = is_marryable
        self.birthday = birthday
        self.haveQuest = haveQuest

    def display(self):
        super().display()
        marry_status = "Ya" if self.is_marryable else "Tidak"
        print(f"  Bisa Dinikahi: {marry_status}")
        print(f"  Ulang Tahun: {self.birthday}")
        print("  Quest yang Ditawarkan:")
        if self.haveQuest:
            self.haveQuest.display()
        else:
            print("    Tidak ada Quest")