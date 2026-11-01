def input_temperature(temp_str: str) -> int:
    tempt = int(temp_str)
    if (tempt < 0):
        raise ValueError(f"{tempt}°C is too cold for plants (min 0°C)")
    elif (tempt > 40):
        raise ValueError(f"{tempt}°C is too hot for plants (max 40°C)")
    else:
        return (tempt)


def test_temperature() -> None:
    print("=== Garden Temperature ===")
    print("")

    test_one_temperature("25")
    test_one_temperature("abc")
    test_one_temperature("100")
    test_one_temperature("-50")

    print("All tests completed - program didn't crash!")


def test_one_temperature(temp_str: str) -> None:
    try:
        print(f"Input data is '{temp_str}'")
        tempt = input_temperature(temp_str)
        if (tempt):
            print(f"Temperature is now {tempt}°C")
        print("")
    except ValueError as error:
        print(f"Caught input_temperature error: {error}\n")


if __name__ == "__main__":
    test_temperature()
