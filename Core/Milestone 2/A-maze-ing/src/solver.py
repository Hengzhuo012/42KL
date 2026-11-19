def is_exit_reached(exit: tuple[int, int], coordinate: tuple[int, int]) -> bool:
    """Check if the list of coordinates contained exit
    Args:
        exit: `(x, y)` coordinates of the maze exit.
        coordinate: `(x, y)` coordiantes to be checked
    
    Return:
        boolean value that if it contained exit
    """


def breadth_first_search(
    entry: tuple[int, int],
    exit: tuple[int, int],
    maze: list[list[int]]
):
    """Algorithm breadth first search used to solve the maze

    Args:
        entry: `(x, y)` coordinates of the maze entry.
        exit: `(x, y)` coordinates of the maze exit.
        maze: 2D-list of the wall-condition of each coordinates.
    
    Return:
        A 2D-list of the shortest path from entry to exit
    """

    # use dictionary of lists
    maze_visited: list[tuple[int, int], tuple[int, int]] = [[-1, -1], entry]
    maze_next_available_path: list[tuple[int, int], tuple[int, int]] = []
    maze_dict: dict[tuple[int, int], list[tuple[int, int]]] = {}
    solved: bool = False

    maze_wall = maze[entry[0]][entry[1]]
    for i in range(4):
        if not ((maze_wall >> i) & 1):
            maze_next_available_path.append(entry[0], entry[1])
        maze_dict[entry] = maze_next_available_path
    for