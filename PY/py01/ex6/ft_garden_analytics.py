class Plant:
    def __init__(self, name: str, height: float, days: int) -> None:
        self.name = name
        self._height = 0.0
        self._days = 0
        self.set_height(height)
        self.set_age(days)
        self._stats = self.Stats()

    def show(self) -> None:
        print(f"{self.name}: {self._height}cm, {self._days} days old")
        self._stats.record("show")

    def age(self, days: int) -> None:
        self._days += days
        self._stats.record("age")

    def grow(self, speed: float) -> None:
        self._height += speed
        self._height = round(self._height, 1)
        self._stats.record("grow")

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

    @staticmethod
    def is_older_than_year(age: int) -> bool:
        return age > 365

    @classmethod
    def create_anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0)

    class Stats:
        def __init__(self) -> None:
            self._grow_count = 0
            self._age_count = 0
            self._show_count = 0

        def record(self, s: str) -> None:
            if s == "grow":
                self._grow_count += 1
            elif s == "age":
                self._age_count += 1
            elif s == "show":
                self._show_count += 1

        def show(self) -> None:
            print(
                f"Stats: {self._grow_count} grow, "
                f"{self._age_count} age, "
                f"{self._show_count} show"
            )

    def show_statistics(self) -> None:
        self._stats.show()


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color = color
        self.has_bloomed = False

    def bloom(self) -> None:
        self.has_bloomed = True

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")

        if self.has_bloomed:
            print(f" {self.name} is blooming beautifully!")
        else:
            print(f" {self.name} has not bloomed yet")


class Tree(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        trunk_diameter: float,
    ) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter
        self._shade_count = 0

    def produce_shade(self) -> None:
        print(
            f"Tree {self.name} now produces a shade of "
            f"{round(self._height, 1)}cm long and "
            f"{round(self.trunk_diameter, 1)}cm wide."
        )
        self._shade_count += 1

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {round(self.trunk_diameter, 1)}cm")

    def show_statistics(self) -> None:
        super().show_statistics()
        print(f" {self._shade_count} shade")


class Vegetable(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        harvest_season: str,
    ) -> None:
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = 0.0

    def grow(self, speed: float) -> None:
        super().grow(speed)
        self.nutritional_value += 0.5

    def age(self, days: int) -> None:
        super().age(days)
        self.nutritional_value += 0.5

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {int(self.nutritional_value)}")


class Seed(Flower):
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        color: str,
        seeds: int
    ) -> None:
        super().__init__(name, height, age, color)
        self.seed = 0
        self.seeds = seeds

    def bloom(self) -> None:
        super().bloom()
        self.seed = self.seeds

    def show(self) -> None:
        super().show()
        print(f" Seeds: {self.seed}")


def display_statistics(plant: Plant) -> None:
    print(f"[Statistics for {plant.name}]")
    plant.show_statistics()


if __name__ == "__main__":
    print("=== Garden statistics ===")

    print("=== Check year-old")
    print(
        "Is 30 days more than a year? -> "
        f"{Plant.is_older_than_year(30)}"
    )
    print(
        "Is 400 days more than a year? -> "
        f"{Plant.is_older_than_year(400)}"
    )

    print()

    print("=== Flower")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()
    display_statistics(rose)

    print("[asking the rose to grow and bloom]")
    rose.grow(8.0)
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
    sunflower = Seed("Sunflower", 80.0, 45, "yellow", 42)
    sunflower.show()

    print("[make sunflower grow, age and bloom]")
    sunflower.grow(30.0)
    sunflower.age(20)
    sunflower.bloom()
    sunflower.show()
    display_statistics(sunflower)

    print()

    print("=== Anonymous")
    anonymous = Plant.create_anonymous()
    anonymous.show()
    display_statistics(anonymous)
