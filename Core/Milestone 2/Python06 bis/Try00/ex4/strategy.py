import abc

from ex3.factory import TransformCapability


class StrategyError(Exception):
    """Raised when a strategy is used on an unsuitable entity."""


class BattleStrategy(abc.ABC):
    @abc.abstractmethod
    def is_valid(self, entity) -> bool:
        raise NotImplementedError

    @abc.abstractmethod
    def act(self, entity) -> str:
        raise NotImplementedError


class NormalStrategy(BattleStrategy):
    def is_valid(self, entity) -> bool:
        return True

    def act(self, entity) -> str:
        if not self.is_valid(entity):
            raise StrategyError(
                f"Invalid Creature '{entity.__class__.__name__}' for this strategy"
            )
        return entity.attack()


class AggressiveStrategy(BattleStrategy):
    def is_valid(self, entity) -> bool:
        return isinstance(entity, TransformCapability)

    def act(self, entity) -> str:
        if not self.is_valid(entity):
            raise StrategyError(
                f"Invalid Creature '{entity.__class__.__name__}' for this aggressive strategy"
            )
        transform_message = entity.transform()
        attack_message = entity.attack()
        revert_message = entity.revert()
        return "\n".join([transform_message, attack_message, revert_message])
