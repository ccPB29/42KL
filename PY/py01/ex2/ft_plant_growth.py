class Plant:
    name: str
    height: float
    days: int

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.days} days old")

    def age(self) -> None:
        self.days += 1

    def grow(self, speed: float) -> None:
        self.height += speed
        self.height = round(self.height, 1)


if __name__ == "__main__":
    print("=== Garden Plant Growth ===")

    rose = Plant()
    rose.name = "Rose"
    rose.height = 25.0
    rose.days = 30

    initial_height = rose.height
    rose.show()

    for day in range(1, 8):
        print(f"=== Day {day} ===")
        rose.grow(0.8)
        rose.age()
        rose.show()

    total_growth = rose.height - initial_height
    print(f"Growth this week: {total_growth:.1f}cm")
