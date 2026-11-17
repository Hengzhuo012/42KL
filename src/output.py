from mazegen import MazeGenerator


def output_maze(maze: MazeGenerator) -> None:
    with open(f"{maze.output_file}", "w") as fd:
        for y in range(maze.height):
            output: list[str] = []
            for x in range(maze.width):
                hex: str = "0123456789abcdef"
                output.append(hex[maze.maze[y][x]])
            output1 = "".join(output)
            fd.write(output1 + "\n")

        fd.write("\n")
        x1, y1 = maze.entry
        x2, y2 = maze.exit
        fd.write(f"{x1},{y1}\n")
        fd.write(f"{x2},{y2}\n")
