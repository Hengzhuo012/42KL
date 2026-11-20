from enum import Enum


class StrategyType(Enum):
    """Enumerator for strategy type"""

    DEPTH_FIRST_SEARCH = "depth_first_search"
    HUNT_AND_KILL = "hunt_and_kill"

    def next(self) -> "StrategyType":
        strategies = list(self.__class__)
        next_index = (strategies.index(self) + 1) % len(strategies)
        return strategies[next_index]
