class Plant:
    def __init__(self, name: str, height: float, days: int):
        self.name = name
        self.height = height
        self.days = days

    def show(self):
        print(f'{self.name}: {self.height:.1f}cm, {self.days} days old')

    def grow(self, growth: float):
        self.height += growth

    def age(self):
        self.days += 1


def ft_plant_factory():
    plant_1 = Plant("Rose", 25, 30)
    plant_2 = Plant("Oak", 200, 365)
    plant_3 = Plant("Cactus", 5, 90)
    plant_4 = Plant("Sunflower", 80, 45)
    plant_5 = Plant("Fern", 15, 120)
    print("=== Plant Factory Output ===")
    print("Created: ", end="")
    plant_1.show()
    print("Created: ", end="")
    plant_2.show()
    print("Created: ", end="")
    plant_3.show()
    print("Created: ", end="")
    plant_4.show()
    print("Created: ", end="")
    plant_5.show()


if __name__ == "__main__":
    ft_plant_factory()
