import sys
from mazegen import MazeGenerator
import random
import display


def instruction(
    maze: MazeGenerator, seed: int, strategy: int, perfect: bool
) -> tuple[int, int, bool]:
    print(f"\033[{maze.height * 2 + 9};1H\033[J", end="")
    print(f"1. Seed number: {maze.seed} Enter '1' to change seed.")
    maze_type = "Perfect" if maze.perfect else "Imperfect"
    print(f"2. Maze type: {maze_type} Enter '2' to change type.")
    print("3. Press 3 to change wall's color")
    print("4. Press 4 to change 42's color")
    print(f"5. Press 5 to change generator algo {maze.strategy}")
    print("Press enter to generate same maze again")
    print("Enter '67' to generate random maze")
    print("Enter 'exit' to quit")
    while True:
        try:
            print(f"\033[{maze.height * 2 + 18};1H\033[J", end="")
            user_input1: str = input("Input: ")
            if not user_input1:
                break
            elif user_input1 == "67":
                seed = random.randint(0, 9999)
                break
            elif user_input1 == "exit":
                sys.exit()
            elif user_input1 == "1":
                seed = int(input("Seed: "))
                break
            elif user_input1 == "2":
                if maze_type == "Perfect":
                    perfect = False
                    break
                else:
                    perfect = True
                    break
            elif user_input1 == "3":
                maze.color = (maze.color + 1) % 8
                print("\033[2J\033[H", end="")
                print(display.output(maze))
            elif user_input1 == "4":
                print(f"\033[{maze.height * 2 + 18};1H\033[J", end="")
                maze.color_42 = int(input("Color: "))
                print(display.output(maze))
            elif user_input1 == "5":
                strategy = (strategy + 1) % 2
                break
            else:
                break
        except Exception as e:
            print(e)

    return seed, strategy, perfect
