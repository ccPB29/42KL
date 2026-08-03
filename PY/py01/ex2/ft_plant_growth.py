class Plant:
    def show(self):
        print(f"{self.name}: {self.height:.1f}cm, {self.age} days old")
    def aged(self):
        self.age += 1
    def grow(self, speed):
        self.height += speed
        self.height = round(self.height, 1)

if __name__ == "__main__":
    print("=== Garden Plant Growth ===")

    rose = Plant()
    rose.name = "Rose"
    rose.height = 25.0
    rose.age = 30

    initial_height = rose.height
    rose.show()

    for day in range(1,8):
        print(f"=== Day {day} ===")
        rose.grow(0.8)
        rose.aged()
        rose.show()
    
    total_growth = rose.height - initial_height
    print(f"Growth this week: {total_growth:.1f}cm")