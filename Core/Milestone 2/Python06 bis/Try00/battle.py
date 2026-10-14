import ex3


def create(factory: ex3.CreatureFactory) -> None:
    entity = factory.create_base()
    evolved_entity = factory.create_evolved()
    print(f"{entity.describe()}")
    print(f"{entity.attack()}")
    print(f"{evolved_entity.describe()}")
    print(f"{evolved_entity.attack()}")


def battle(factory_1: ex3.CreatureFactory,
           factory_2: ex3.CreatureFactory) -> None:
    entity_1 = factory_1.create_base()
    entity_2 = factory_2.create_base()
    print(f"{entity_1.describe()}")
    print(" vs.")
    print(f"{entity_2.describe()}")
    print(" fight!")
    print(f"{entity_1.attack()}")
    print(f"{entity_2.attack()}")


if __name__ == "__main__":
    flame_factory = ex3.FlameFactory()
    transform_creature_factory = ex3.TransformCreatureFactory()

    print("Testing factory")
    create(flame_factory)
    print("")

    print("Testing factory")
    create(transform_creature_factory)
    print("")

    print("Testing battle")
    battle(flame_factory, transform_creature_factory)
