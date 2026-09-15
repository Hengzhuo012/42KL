class Garden:
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.height = height
        self.age = age


def ft_garden_intro():
    garden_test = Garden("Rose", 25, 30)
    print("=== Welcome to My Garden ===")
    print(f'Plant: {garden_test.name}')
    print(f'Height: {garden_test.height}cm')
    print(f'Age: {garden_test.age} days')
    print("")
    print("=== End of Program ===")


if __name__ == "__main__":
    ft_garden_intro()
