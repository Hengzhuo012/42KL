class Plant:
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.height = height
        self.age = age

    def show(self):
        print(f'{self.name}: {self.height:.1f}cm, {self.age} days old')

    def grow(self):
        self.height += 0.8

    def aged(self):
        self.age += 1


def ft_plant_growth():
    print("=== Garden Plant Growth ===")
    plant = Plant("Rose", 25, 30)
    growth = plant.height
    plant.show()
    for i in range(1, 8, 1):
        plant.grow()
        plant.aged()
        print(f'=== Day {i} ===')
        plant.show()
    growth = plant.height - growth
    print(f'Growth this week: {growth:.1f}cm')


if __name__ == "__main__":
    ft_plant_growth()
