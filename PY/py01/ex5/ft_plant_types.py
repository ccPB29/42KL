class Plant:
    def __init__(self, name: str, height: float, days: int) -> None:
        self.name = name
        self._height = 0.0
        self._days = 0
        self.set_height(height)
        self.set_age(days)

    def show(self) -> None:
        print(f"{self.name}: {self._height}cm, {self._days} days old")

    def age(self) -> None:
        self._days += 1

    def grow(self, speed: float) -> None:
        self._height += speed
        self._height = round(self._height, 1)

    def set_height(self, new_height: float) -> bool:
        if new_height < 0:
            print(f"{self.name}: Error, height can't be negative")
            return False
        self._height = new_height
        return True

    def set_age(self, new_age: int) -> bool:
        if new_age < 0:
            print(f"{self.name}: Error, age can't be negative")
            return False
        self._days = new_age
        return True

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._days


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color = color
        self.has_bloomed = False

    def bloom(self):
        self.has_bloomed = True

    def show(self):
        super().show()
        print(f" Color: {self.color}")

        if self.has_bloomed:
            print(f" {self.name} is blooming beautifully!")
        else:
            print(f" {self.name} has not bloomed yet")


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int, trunk_diameter: float) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self):
        print(
            f"Tree {self.name} now produces a shade of "
            f"{round(self._height, 1)}cm long and "
            f"{round(self.trunk_diameter, 1)}cm wide."
        )

    def show(self):
        super().show()
        print(f" Trunk diameter: {round(self.trunk_diameter, 1)}cm")


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int, harvest_season: str) -> None:
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = 0

    def grow(self):
        self._height += 2.1
        self.nutritional_value += 0.5

    def age(self):
        self._age += 1
        self.nutritional_value += 0.5

    def show(self):
        super().show()
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {int(self.nutritional_value)}")


print("=== Garden Plant Types ===")

print("=== Flower")
rose = Flower("Rose", 15.0, 10, "red")
rose.show()

print("[asking the rose to bloom]")
rose.bloom()
rose.show()

print()

print("=== Tree")
oak = Tree("Oak", 200.0, 365, 5.0)
oak.show()

print("[asking the oak to produce shade]")
oak.produce_shade()

print()

print("=== Vegetable")
tomato = Vegetable("Tomato", 5.0, 10, "April")
tomato.show()

print("[make tomato grow and age for 20 days]")
for i in range(20):
    tomato.grow()
    tomato.age()

tomato.show()