import ex3
import ex4


def format_opponent(
    factory: ex3.CreatureFactory,
    strategy: ex4.BattleStrategy,
) -> str:
    entity = factory.create_base()
    entity_name = entity.__class__.__name__
    strategy_name = strategy.__class__.__name__.replace("Strategy", "")
    return f"({entity_name}+{strategy_name})"


def battle(
    opponents: list[tuple[ex3.CreatureFactory, ex4.BattleStrategy]],
) -> None:
    for i in range(len(opponents) - 1):
        for j in range(i + 1, len(opponents)):
            factory_a, strategy_a = opponents[i]
            factory_b, strategy_b = opponents[j]

            entity_a = factory_a.create_base()
            entity_b = factory_b.create_base()

            print(f"{entity_a.describe()}")
            print(" vs.")
            print(f"{entity_b.describe()}")
            print(" now fight!")

            for entity, strategy in ((entity_a, strategy_a),
                                     (entity_b, strategy_b)):
                if not strategy.is_valid(entity):
                    raise ex4.StrategyError(
                        f"Invalid Creature '{entity.__class__.__name__}' "
                        f"for this aggressive strategy"
                    )
                for line in strategy.act(entity).splitlines():
                    print(line)


if __name__ == "__main__":
    print("Tournament 0 (basic)")
    opponents: list[tuple[ex3.CreatureFactory, ex4.BattleStrategy]] = [
        (ex3.FlameFactory(), ex4.NormalStrategy()),
        (ex3.TransformCreatureFactory(), ex4.AggressiveStrategy()),
    ]
    display = ", ".join(format_opponent(factory, strategy)
                        for factory, strategy in opponents)
    print(f"[{display}]")
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")
    print("")
    print("* Battle *")
    battle(opponents)

    print("\nTournament 1 (error)")
    opponents = [
        (ex3.TransformCreatureFactory(), ex4.AggressiveStrategy()),
        (ex3.FlameFactory(), ex4.AggressiveStrategy()),
    ]
    display = ", ".join(format_opponent(factory, strategy)
                        for factory, strategy in opponents)
    print(f"[{display}]")
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")
    print("* Battle *")
    try:
        battle(opponents)
    except ex4.StrategyError as exc:
        print(f"Battle error, aborting tournament: {exc}")
