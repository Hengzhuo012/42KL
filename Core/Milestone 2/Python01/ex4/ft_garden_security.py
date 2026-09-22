class Plant:
    def __init__(self, name: str, height: float, age: int):
        self.name = name
        self._height = 0.0
        self._age = 0
        self.set_height(height, False)
        self.set_age(age, False)

    def show(self):
        print(f'{self.name}: {self.get_height():.1f}cm, '
              f'{self.get_age()} days old')

    def grow(self, growth: float):
        self._height += growth

    def age(self):
        self._age += 1

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


def ft_garden_security():
    print("=== Garden Security System ===")
    plant = Plant("Rose", 15, 10)
    print("Plant created: ", end="")
    plant.show()
    print("")
    plant.set_height(25)
    plant.set_age(30)
    print("")
    plant.set_height(-5)
    plant.set_age(-5)
    print("")
    print("Current state: ", end="")
    plant.show()


if __name__ == "__main__":
    ft_garden_security()
