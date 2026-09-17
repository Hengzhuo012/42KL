def garden_operations(operation_number: int):
    if operation_number == 0:
        int("abc")
    elif operation_number == 1:
        1 / 0
    elif operation_number == 2:
        open("/non/existent/file")
    elif operation_number == 3:
        "garden " + 5
    else:
        return


def test_error_types():
    print("=== Garden Error Types Demo ===")
    for opt in range(5):
        print(f"Testing operation {opt}...")
        try:
            garden_operations(opt)
        except ValueError as error:
            print(f"Caught ValueError: {error}")
        except ZeroDivisionError as error:
            print(f"Caught ZeroDivisionError: {error}")
        except FileNotFoundError as error:
            print(f"Caught FileNotFoundError: {error}")
        except TypeError as error:
            print(f"Caught TypeError: {error}")
        else:
            print("Operation completed successfully")

    print("\nAll error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
