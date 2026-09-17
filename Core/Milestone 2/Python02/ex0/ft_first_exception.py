def input_temperature(temp_str: str):
    try:
        return int(temp_str)

    except ValueError as error:
        print(f"Caught input_temperature error: {error}")


def test_temperature():
    print("=== Garden Temperature ===")
    print("")

    temp_str = "25"
    print(f"Input data is '{temp_str}'")
    tempt = input_temperature(temp_str)
    if (tempt):
        print(f"Temperature is now {tempt}°C")
    print("")

    temp_str = "abc"
    print(f"Input data is '{temp_str}'")
    tempt = input_temperature(temp_str)
    if (tempt):
        print(f"Temperature is now {tempt}°C")
    print("")

    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
