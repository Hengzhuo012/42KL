class GardenError(Exception):
    def __init__(self, message: str = "Unknown garden error") -> None:
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message: str = "Unknown plant error") -> None:
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message: str = "Unknown water error") -> None:
        super().__init__(message)


def ft_custom_errors() -> None:
    print("=== Custom Garden Errors Demo ===")
    print("")
    print("Testing PlantError...")
    msg = "The tomato plant is wilting!"
    try:
        if msg == "The tomato plant is wilting!":
            raise PlantError(msg)
    except PlantError as error:
        print(f"Caught PlantError: {error}")
    print("")

    print("Testing WaterError...")
    msg = "Not enough water in the tank!"
    try:
        if msg == "Not enough water in the tank!":
            raise WaterError(msg)
    except WaterError as error:
        print(f"Caught WaterError: {error}")
    print("")

    print("Testing catching all garden errors...")
    for msg in ["The tomato plant is wilting!",
                "Not enough water in the tank!"]:
        try:
            if msg == "The tomato plant is wilting!":
                raise PlantError(msg)
            elif msg == "Not enough water in the tank!":
                raise WaterError(msg)
        except GardenError as error:
            print(f"Caught GardenError: {error}")
    print("")
    print("All custom error types work correctly!")


if __name__ == "__main__":
    ft_custom_errors()
