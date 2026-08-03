class Plant:
    def __init__(self, name, height=0.0, age=0):
        self.name = name
        self._height = 0.0
        self._age = 0

        self.set_height(height)
        self.set_age(age)

    def set_height(self, height):
        if height < 0:
            print(f"{self.name}: Error, height can't be negative")
            return False

        self._height = float(height)
        return True

    def set_age(self, age):
        if age < 0:
            print(f"{self.name}: Error, age can't be negative")
            return False

        self._age = int(age)
        return True

    def get_height(self):
        return self._height

    def get_age(self):
        return self._age

    def grow(self):
        self._height += 1.0

    def age(self):
        self._age += 1

    def show(self):
        print(f"{self.name}: {round(self._height, 1)}cm, {self._age} days old")


class Flower(Plant):
    def __init__(self, name, height, age, color):
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
    def __init__(self, name, height, age, trunk_diameter):
        super().__init__(name, height, age)
        self.trunk_diameter = float(trunk_diameter)

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
    def __init__(self, name, height, age, harvest_season):
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