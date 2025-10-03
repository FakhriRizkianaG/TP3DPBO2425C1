from FriendlyNPC import FriendlyNPC

class Trainer(FriendlyNPC):
    """NPC pelatih untuk membantu meningkatkan stats player."""
    def __init__(self, name: str, gender: str, race: str, affiliation,
                 is_marryable: bool, birthday: str, haveQuest,
                 fee: int, trainingType: str, **kwargs):
        super().__init__(name, gender, race, affiliation, is_marryable, birthday, haveQuest, **kwargs)
        self.fee = fee
        self.trainingType = trainingType

    def display(self):
        super().display()
        print(f"  Bayaran: {self.fee}")
        print(f"  Tipe Latihan: {self.trainingType}")