from mazegen import MazeGenerator


def output(
    maze: MazeGenerator, highlight: tuple[int, int] | None = None
) -> str:
    total_maze: list[str] = []
    color_list: list[int] = [97, 90, 91, 92, 93, 94, 95, 96]
    color: int = color_list[maze.color]
    color_42: int = maze.color_42

    for y, row in enumerate(maze.maze):
        to_print1: list[str] = []
        to_print2: list[str] = []
        for x, column in enumerate(row):
            if column & 1 and column & 8:
                to_print1.append(f"\033[{color}m██\033[0m")
                if (
                    (y - 1) > 0
                    and (y - 1, x) in maze.cells_42
                    and (y, x) in maze.cells_42
                ):
                    to_print1.append(f"\033[{color_42}m██\033[0m")
                else:
                    to_print1.append(f"\033[{color}m██\033[0m")
                if (
                    (x - 1) > 0
                    and (y, x - 1) in maze.cells_42
                    and (y, x) in maze.cells_42
                ):
                    to_print2.append(f"\033[{color_42}m██\033[0m")
                else:
                    to_print2.append(f"\033[{color}m██\033[0m")
                if (y, x) in maze.cells_42:
                    to_print2.append(f"\033[{color_42}m██\033[0m")
                elif (x, y) == maze.exit:
                    to_print2.append("\033[92m██\033[0m")
                elif (x, y) == maze.entry:
                    to_print2.append("\033[91m██\033[0m")
                elif (x, y) == highlight:
                    to_print2.append("\033[93m██\033[0m")
                else:
                    to_print2.append("  ")
            elif column & 1 and not column & 8:
                to_print1.append(f"\033[{color}m██\033[0m")
                to_print1.append(f"\033[{color}m██\033[0m")
                to_print2.append(f"\033[{color}m  \033[0m")
                if (x, y) == maze.exit:
                    to_print2.append("\033[95m██\033[0m")
                elif (x, y) == maze.entry:
                    to_print2.append("\033[91m██\033[0m")
                elif (x, y) == highlight:
                    to_print2.append("\033[93m██\033[0m")
                else:
                    to_print2.append("  ")
            elif not column & 1 and column & 8:
                to_print1.append(f"\033[{color}m██\033[0m")
                to_print1.append(f"\033[{color}m  \033[0m")
                to_print2.append(f"\033[{color}m██\033[0m")
                if (x, y) == maze.exit:
                    to_print2.append("\033[92m██\033[0m")
                elif (x, y) == maze.entry:
                    to_print2.append("\033[91m██\033[0m")
                elif (x, y) == highlight:
                    to_print2.append("\033[93m██\033[0m")
                else:
                    to_print2.append("  ")
            else:
                to_print1.append(f"\033[{color}m██\033[0m")
                to_print1.append("  ")
                to_print2.append("  ")
                if (x, y) == maze.exit:
                    to_print2.append("\033[92m██\033[0m")
                elif (x, y) == maze.entry:
                    to_print2.append("\033[91m██\033[0m")
                elif (x, y) == highlight:
                    to_print2.append("\033[93m██\033[0m")
                else:
                    to_print2.append("  ")
        to_print1.append(f"\033[{color}m██\n\033[0m")
        to_print2.append(f"\033[{color}m██\n\033[0m")
        total_maze.extend(to_print1)
        total_maze.extend(to_print2)
    to_print1 = []
    for _ in range(maze.width):
        to_print1.append(f"\033[{color}m██\033[0m")
        to_print1.append(f"\033[{color}m██\033[0m")
    to_print1.append(f"\033[{color}m██\n\033[0m")
    total_maze.extend(to_print1)
    out: str = "".join(total_maze)
    return out
