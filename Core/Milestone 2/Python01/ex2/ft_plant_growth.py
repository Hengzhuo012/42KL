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


def ft_plant_growth():
    print("=== Garden Plant Growth ===")
    plant = Plant("Rose", 25, 30)
    growth = plant.height
    plant.show()
    for i in range(1, 8, 1):
        plant.grow(0.8)
        plant.age()
        print(f'=== Day {i} ===')
        plant.show()
    growth = plant.height - growth
    print(f'Growth this week: {growth:.1f}cm')


if __name__ == "__main__":
    ft_plant_growth()
