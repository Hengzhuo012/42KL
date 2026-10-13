import ex3

if __name__ == "__main__":
    print("Testing Creature with transform capability")
    print(" base:")
    transform_creature_factory = ex3.TransformCreatureFactory()
    shiftling = transform_creature_factory.create_base()
    print(f"{shiftling.describe()}")
    print(f"{shiftling.attack()}")
    print(f"{shiftling.transform()}")
    print(f"{shiftling.attack()}")
    print(f"{shiftling.revert()}")

    print(" evolved:")
    morphagon = transform_creature_factory.create_evolved()
    print(f"{morphagon.describe()}")
    print(f"{morphagon.attack()}")
    print(f"{morphagon.transform()}")
    print(f"{morphagon.attack()}")
    print(f"{morphagon.revert()}")
