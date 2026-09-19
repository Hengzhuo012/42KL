import sys


def ft_command_quest():
    print("=== Command Quest ===")
    print(f"Program name: {sys.argv[0]}")
    size = len(sys.argv)
    if size == 1:
        print("No argruments provided!")
    else:
        print(f"Arguments received: {size - 1}")
        for i in range(1, size, 1):
            print(f"Argument {i}: {sys.argv[i]}")
    print(f"Total arguments: {size}")


if __name__ == "__main__":
    ft_command_quest()
