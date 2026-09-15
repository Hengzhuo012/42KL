class Plant:
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self._height = height
        self._age = age

    def show(self):
        print(f'{self.name}: {self.get_height():.1f}cm, '
              f'{self.get_age()} days old')

    def grow(self):
        self._height += 0.8

    def aged(self):
        self._age += 1

    def set_height(self, height: int):
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

    def get_height(self) -> int:
        return (self._height)

    def get_age(self) -> int:
        return (self._age)

class Flower:
    def __init__(self, name, height, age, color)
        super().__init__(name, height, age)
        self.color = color

	def show(self):
			print(f'{self.name}: {self.get_height():.1f}cm, '
				  f'{self.get_age()} days old, {self.color} color')

	def bloom():
    