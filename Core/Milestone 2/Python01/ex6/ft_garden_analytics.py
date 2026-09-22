class Plant:
    class Count:
        def __init__(self):
            self._grow_count = 0
            self._age_count = 0
            self._show_count = 0

        def increment_grow_count(self):
            self._grow_count += 1

        def increment_age_count(self):
            self._age_count += 1

        def increment_show_count(self):
            self._show_count += 1

        def get_grow_count(self):
            return self._grow_count

        def get_age_count(self):
            return self._age_count

        def get_show_count(self):
            return self._show_count

    def __init__(self, name: str, height: float, age: int):
        self.name = name
        self._height = 0.0
        self._age = 0
        self.set_height(height, False)
        self.set_age(age, False)
        self.count: Plant.Count = self.Count()

    def show(self):
        print(f'{self.name}: {self.get_height():.1f}cm, '
              f'{self.get_age()} days old')
        self.count.increment_show_count()

    def grow(self, growth: float):
        self._height += growth
        self.count.increment_grow_count()

    def age(self):
        self._age += 1
        self.count.increment_age_count()

    def set_height(self, height: float, announce: bool = True):
        if (height < 0):
            print(f'{self.name}: Error, height can\'t be negative')
            print("Height update rejected")
        else:
            self._height = height
            if announce:
                print(f'Height updated: {self.get_height():.0f}cm')

    def set_age(self, age: int, announce: bool = True):
        if (age < 0):
            print(f'{self.name}: Error, age can\'t be negative')
            print("Age update rejected")
        else:
            self._age = age
            if announce:
                print(f'Age updated: {self.get_age()} days')

    def get_height(self) -> float:
        return (self._height)

    def get_age(self) -> int:
        return (self._age)

    @staticmethod
    def is_older_than_a_year(days: int):
        return days > 365

    @classmethod
    def create_plant(cls):
        return cls("Unknown plant", 0.0, 0)

    def show_stats(self):
        print(f'Stats: {self.count.get_grow_count()} grow, '
              f'{self.count.get_age_count()} age, '
              f'{self.count.get_show_count()} show')


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
        self._shade_count = 0

    def show(self):
        super().show()
        print(f' Trunk diameter: {self.trunk_diameter:.1f}cm')

    def increment_shade(self):
        self._shade_count += 1

    def get_shade_count(self):
        return self._shade_count

    def produce_shade(self):
        print(f'Tree {self.name} now produces a shade of '
              f'{self.get_height():.1f}cm long and '
              f'{self.trunk_diameter:.1f}cm wide.')
        self.increment_shade()

    def show_stats(self):
        super().show_stats()
        print(f' {self.get_shade_count()} shade')


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


class Seed(Flower):
    def __init__(self, name: str, height: float, age: int, color: str):
        super().__init__(name, height, age, color)
        self.number_of_seeds = 0

    def seeds(self):
        if self.is_bloom:
            self.number_of_seeds = 42

    def show(self):
        super().show()
        print(f' Seeds: {self.number_of_seeds}')

    def age(self):
        self._age += 20
        self.count.increment_age_count()


def display_plant_stats(plant: Plant) -> None:
    print(f"[statistic for {plant.name}]")
    plant.show_stats()


def ft_garden_analytics():
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print(f'Is 30 days more than a year? -> {Plant.is_older_than_a_year(30)}')
    print(f'Is 400 days more than a year? -> '
          f'{Plant.is_older_than_a_year(400)}')
    print("")
    # FLOWER
    print("=== Flower")
    flower_1 = Flower("Rose", 15, 10, "red")
    flower_1.show()
    display_plant_stats(flower_1)
    print("[asking the rose to grow and bloom]")
    flower_1.grow(8)
    flower_1.bloom()
    flower_1.show()
    display_plant_stats(flower_1)
    print("")
    # TREE
    print("=== Tree")
    tree_1 = Tree("Oak", 200, 365, 5)
    tree_1.show()
    display_plant_stats(tree_1)
    print("[asking the oak to produce shade]")
    tree_1.produce_shade()
    display_plant_stats(tree_1)
    print("")
    # SEED
    print("=== Seed")
    seed_1 = Seed("Sunflower", 80, 45, "yellow")
    seed_1.show()
    print("[make sunflower grow, age and bloom]")
    seed_1.grow(30)
    seed_1.age()
    seed_1.bloom()
    seed_1.seeds()
    seed_1.show()
    display_plant_stats(seed_1)
    print("")
    # Anonymous
    print("=== Anonymous")
    anonymous = Plant.create_plant()
    anonymous.show()
    display_plant_stats(anonymous)


if __name__ == "__main__":
    ft_garden_analytics()
