class Plant:
    class Stats:
        def __init__(self):
            self._grow_calls = 0
            self._age_calls = 0
            self._show_calls = 0

        def add_grow(self):
            self._grow_calls += 1

        def add_age(self):
            self._age_calls += 1

        def add_show(self):
            self._show_calls += 1

        def show(self):
            print(
                f"Stats: {self._grow_calls} grow, "
                f"{self._age_calls} age, "
                f"{self._show_calls} show"
            )

    def __init__(self, name, height=0.0, age=0):
        self.name = name
        self._height = 0.0
        self._age = 0
        self._stats = Plant.Stats()

        self.set_height(height)
        self.set_age(age)

    @staticmethod
    def is_older_than_year(age):
        return age > 365

    @classmethod
    def create_anonymous(cls):
        return cls("Unknown plant", 0.0, 0)

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
        self._height += 8.0
        self._stats.add_grow()

    def age(self):
        self._age += 1
        self._stats.add_age()

    def show(self):
        self._stats.add_show()
        print(f"{self.name}: {round(self._height, 1)}cm, {self._age} days old")

    def show_stats(self):
        self._stats.show()


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
    class TreeStats(Plant.Stats):
        def __init__(self):
            super().__init__()
            self._shade_calls = 0

        def add_shade(self):
            self._shade_calls += 1

        def show(self):
            super().show()
            print(f" {self._shade_calls} shade")

    def __init__(self, name, height, age, trunk_diameter):
        super().__init__(name, height, age)
        self.trunk_diameter = float(trunk_diameter)
        self._stats = Tree.TreeStats()

    def produce_shade(self):
        self._stats.add_shade()
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
        self._stats.add_grow()

    def age(self):
        self._age += 1
        self.nutritional_value += 0.5
        self._stats.add_age()

    def show(self):
        super().show()
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {int(self.nutritional_value)}")


class Seed(Flower):
    def __init__(self, name, height, age, color):
        super().__init__(name, height, age, color)
        self.seeds = 0

    def bloom(self):
        super().bloom()
        self.seeds = 42

    def grow(self):
        self._height += 30.0
        self._stats.add_grow()

    def age(self):
        self._age += 20
        self._stats.add_age()

    def show(self):
        super().show()
        print(f" Seeds: {self.seeds}")


def display_statistics(plant):
    print(f"[statistics for {plant.name}]")
    plant.show_stats()


print("=== Garden statistics ===")

print("=== Check year-old")
print(f"Is 30 days more than a year? -> {Plant.is_older_than_year(30)}")
print(f"Is 400 days more than a year? -> {Plant.is_older_than_year(400)}")

print()

print("=== Flower")
rose = Flower("Rose", 15.0, 10, "red")
rose.show()
display_statistics(rose)

print("[asking the rose to grow and bloom]")
rose.grow()
rose.bloom()
rose.show()
display_statistics(rose)

print()

print("=== Tree")
oak = Tree("Oak", 200.0, 365, 5.0)
oak.show()
display_statistics(oak)

print("[asking the oak to produce shade]")
oak.produce_shade()
display_statistics(oak)

print()

print("=== Seed")
sunflower = Seed("Sunflower", 80.0, 45, "yellow")
sunflower.show()

print("[make sunflower grow, age and bloom]")
sunflower.grow()
sunflower.age()
sunflower.bloom()
sunflower.show()
display_statistics(sunflower)

print()

print("=== Anonymous")
unknown = Plant.create_anonymous()
unknown.show()
display_statistics(unknown)