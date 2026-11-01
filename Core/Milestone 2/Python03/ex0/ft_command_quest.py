import sys


def ft_command_quest() -> None:
    print("=== Command Quest ===")
    print(f"Program name: {sys.argv[0]}")
    size = len(sys.argv)
    if size == 1:
        print("No arguments provided!")
    else:
        print(f"Arguments received: {size - 1}")
        argument_number = 1
        for argument in sys.argv[1:]:
            print(f"Argument {argument_number}: {argument}")
            argument_number += 1
    print(f"Total arguments: {size}")


if __name__ == "__main__":
    ft_command_quest()
