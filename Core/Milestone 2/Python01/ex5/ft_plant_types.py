class Plant:
    def __init__(self, name: str, height: float, age: int):
        self.name = name
        self._height = height
        self._age = age

    def show(self):
        print(f'{self.name}: {self.get_height():.1f}cm, '
              f'{self.get_age()} days old')

    def grow(self, growth: float):
        self._height += growth

    def age(self):
        self._age += 1

    def set_height(self, height: float):
        if (height < 0):
            print(f'{self.name}: Error, height can\'t be negative')
            print("Height update rejected")
        else:
            self._height = height
            print(f'Height updated: {self.get_height():.0f}cm')

    def set_age(self, age: int):
        if (age < 0):
            print(f'{self.name}: Error, age can\'t be negative')
            print("Age update rejected")
        else:
            self._age = age
            print(f'Age updated: {self.get_age()} days')

    def get_height(self) -> float:
        return (self._height)

    def get_age(self) -> int:
        return (self._age)


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str):
        super().__init__(name, height, age)
        self.color = color
        self.is_bloom = False

    def show(self):
        super().show()
        print(f' Color: {self.color}')
        if self.is_bloom:
            print(f' {self.name} is blooming beautifully!')
        else:
            print(f' {self.name} has not bloomed yet')

    def bloom(self):
        self.is_bloom = True


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int,
                 trunk_diameter: int):
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def show(self):
        super().show()
        print(f' Trunk diameter: {self.trunk_diameter:.1f}cm')

    def produce_shade(self):
        print(f'Tree {self.name} now produces a shade of '
              f'{self._height:.1f}cm long and '
              f'{self.trunk_diameter:.1f}cm wide.')


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int,
                 harvest_season: str, nutritional_value: int):
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def show(self):
        super().show()
        print(f' Harvest season: {self.harvest_season}')
        print(f' Nutritional value: {self.nutritional_value}')

    def age(self):
        super().age()
        self.nutritional_value += 1


def ft_plant_types():
    print("=== Garden Plant Types ===")
    print("=== Flower")
    flower_1 = Flower("Rose", 15, 10, "red")
    flower_1.show()
    print("[asking the rose to bloom]")
    flower_1.bloom()
    flower_1.show()
    print("")
    print("=== Tree")
    tree_1 = Tree("Oak", 200, 365, 5)
    tree_1.show()
    print("[asking the oak to produce shade]")
    tree_1.produce_shade()
    print("")
    print("=== Vegetable")
    vege_1 = Vegetable("Tomato", 5, 10, "April", 0)
    vege_1.show()
    print("[make tomato grow and age for 20 days]")
    for _ in range(20):
        vege_1.age()
        vege_1.grow(2.1)
    vege_1.show()


if __name__ == "__main__":
    ft_plant_types()
