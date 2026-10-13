import typing
import abc


class Creature(abc.ABC):
    def __init__(self, name, type):
        self.name = name
        self.type = type

    @abc.abstractmethod
    def attack(self) -> str:
        pass

    def describe(self) -> str:
        return f"{self.name} is a {self.type} type Creature"


class Flameling(Creature):
    def __init__(self, name, type):
        super().__init__(name, type)

    def attack(self) -> str:
        return f"{self.name} uses Ember!"


class Pyrodon(Creature):
    def __init__(self, name, type):
        super().__init__(name, type)

    def attack(self) -> str:
        return f"{self.name} uses Flamethrower!"


class Aquabub(Creature):
    def __init__(self, name, type):
        super().__init__(name, type)

    def attack(self) -> str:
        return f"{self.name} uses Water Gun!"


class Torragon(Creature):
    def __init__(self, name, type):
        super().__init__(name, type)

    def attack(self) -> str:
        return f"{self.name} uses Hydro Pump!"


class CreatureFactory(abc.ABC):
    @abc.abstractmethod
    def create_base(self) -> typing.Any:
        pass

    @abc.abstractmethod
    def create_evolved(self) -> typing.Any:
        pass


class FlameFactory(CreatureFactory):
    def create_base(self):
        return Flameling("Flamling", "Fire")

    def create_evolved(self):
        return Pyrodon("Pyrodon", "Fire/Flying")


class AquaFactory(CreatureFactory):
    def create_base(self) -> typing.Any:
        return Aquabub("Aquabub", "Water")

    def create_evolved(self) -> typing.Any:
        return Torragon("Torragon", "Water")
