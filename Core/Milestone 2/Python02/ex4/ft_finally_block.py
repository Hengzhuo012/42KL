class GardenError(Exception):
    "Basic error for garden problems"
    pass


class PlantError(GardenError):
    "Problems with plants"
    pass


class WaterError(GardenError):
    "Problems with watering"
    pass


def water_plant(plant_name: str):
    if plant_name == plant_name.capitalize():
        print(f"Watering {plant_name}: [OK]")
    else:
        raise PlantError(plant_name)


def test_watering_system(plant_1: str, plant_2: str, plant_3: str):
    try:
        print("Opening watering system")
        water_plant(plant_1)
        water_plant(plant_2)
        water_plant(plant_3)
    except PlantError as error:
        print(f"Caught PlantError: Invalid plant name to water: '{error}'")
        print(".. ending tests and returning to main")
    finally:
        print("Closing watering system")


def main():
    print("=== Garden Watering System ===")
    print("")
    print("Testing valid plants...")
    test_watering_system("Tomato", "Lettuce", "Carrots")
    print("")
    print("Testing invalid plants...")
    test_watering_system("Tomato", "lettuce", "Carrots")
    print("")
    print("Cleanup always happens, even with errors!")


if __name__ == "__main__":
    main()
