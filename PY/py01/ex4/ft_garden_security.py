class Plant:
    def __init__(self, name: str, height: float, days: int) -> None:
        self.name = name
        self._height = height
        self._days = days

    def show(self) -> None:
        print(f"{self.name}: {self._height}cm, {self._days} days old")

    def age(self) -> None:
        self._days += 1

    def grow(self, speed: float) -> None:
        self._height += speed
        self._height = round(self._height, 1)

    def set_height(self, new_height: float) -> bool:
        if new_height < 0:
            return False
        self._height = new_height
        return True

    def set_age(self, new_age: int) -> bool:
        if new_age < 0:
            return False
        self._days = new_age
        return True

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._days


print("=== Garden Security System ===")

rose = Plant("Rose", 15.0, 10)
print(f"Plant created: {rose.show()}")

print()

if rose.set_height(25):
    print("Height updated: 25cm")
else:
    print("Height update rejected")

if rose.set_age(30):
    print("Age updated: 30 days")
else:
    print("Age update rejected")

print()

if rose.set_height(-5):
    print("Height updated: -5cm")
else:
    print("Height update rejected")

if rose.set_age(-2):
    print("Age updated: -2 days")
else:
    print("Age update rejected")

print()
print(f"Current state: {rose.show()}")