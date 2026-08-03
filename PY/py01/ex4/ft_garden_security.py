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

    def show(self):
        return f"{self.name}: {self._height:.1f}cm, {self._age} days old"


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