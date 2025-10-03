from FriendlyNPC import FriendlyNPC

class Merchant(FriendlyNPC):
    """NPC pedagang."""
    def __init__(self, name: str, gender: str, race: str, affiliation,
                 is_marryable: bool, birthday: str, haveQuest,
                 type: str, openTime: str, **kwargs):
        super().__init__(name, gender, race, affiliation, is_marryable, birthday, haveQuest, **kwargs)
        self.type = type
        self.openTime = openTime

    def display(self):
        super().display()
        print(f"  Tipe Pedagang: {self.type}")
        print(f"  Jam Buka: {self.openTime}")