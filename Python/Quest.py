class Quest:
    """Quest yang bisa dilaksanakan oleh Player."""
    def __init__(self, name: str, desc: str):
        self.name = name
        self.desc = desc

    def display(self):
        print(f"  Quest: {self.name}")
        print(f"    Deskripsi: {self.desc}")