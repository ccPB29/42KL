class Plant:
    def __init__(self, name: str, height: float, days: int) -> None:
        self.name = name
        self.height = height
        self.days = days

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.days} days old")

    def age(self) -> None:
        self.days += 1

    def grow(self, speed: float) -> None:
        self.height += speed
        self.height = round(self.height, 1)


if __name__ == "__main__":
    print("=== Plant Factory Output ===")

    garden = [
        Plant("Rose", 25.0, 30),
        Plant("Oak", 200.0, 365),
        Plant("Cactus", 5.0, 90),
        Plant("Sunflower", 80.0, 45),
        Plant("Fern", 15.0, 120)
    ]

    for p in garden:
        print("Created: ", end="")
        p.show()
