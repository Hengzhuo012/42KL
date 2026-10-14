import abc
import typing


class Creature(abc.ABC):
    def __init__(self, name: str, type: str):
        self.name = name
        self.type = type

    @abc.abstractmethod
    def attack(self) -> str:
        pass

    def describe(self) -> str:
        return f"{self.name} is a {self.type} type Creature"


class Flameling(Creature):
    def __init__(self, name: str, type: str) -> None:
        super().__init__(name, type)

    def attack(self) -> str:
        return f"{self.name} uses Ember!"


class Pyrodon(Creature):
    def __init__(self, name: str, type: str) -> None:
        super().__init__(name, type)

    def attack(self) -> str:
        return f"{self.name} uses Flamethrower!"


class TransformCapability(abc.ABC):
    def __init__(self, transformed: bool = False):
        self.transformed = transformed

    @abc.abstractmethod
    def transform(self) -> typing.Any:
        pass

    @abc.abstractmethod
    def revert(self) -> typing.Any:
        pass


class Shiftling(Creature, TransformCapability):
    def __init__(self, name: str, type: str, transformed: bool = False):
        Creature.__init__(self, name, type)
        TransformCapability.__init__(self, transformed)

    def attack(self) -> str:
        if self.transformed:
            return f"{self.name} performs a boosted strike!"
        return f"{self.name} attacks normally."

    def transform(self) -> str:
        self.transformed = True
        return f"{self.name} shifts into a sharper form!"

    def revert(self) -> str:
        self.transformed = False
        return f"{self.name} returns to normal."


class Morphagon(Creature, TransformCapability):
    def __init__(self, name: str, type: str, transformed: bool = False):
        Creature.__init__(self, name, type)
        TransformCapability.__init__(self, transformed)

    def attack(self) -> str:
        if self.transformed:
            return f"{self.name} unleashes a devastating morph strike!"
        return f"{self.name} attacks normally."

    def transform(self) -> str:
        self.transformed = True
        return f"{self.name} morphs into a dragonic battle form!"

    def revert(self) -> str:
        self.transformed = False
        return f"{self.name} stabilizes its form."
