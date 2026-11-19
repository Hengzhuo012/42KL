Coord = tuple[int, int]


def is_solved(exit: Coord, visited_cells: list[Coord]) -> bool:
    """Check if it visited exit before
    Args:
        exit: `(x, y)` coordinates of the maze exit.
        visited_cells: list `(x, y)` coordiantes visited

    Return:
        boolean value that if list visited_cells contained exit
    """
    for coords in reversed(visited_cells):
        if coords == exit:
            return True
    return False


def get_next_possible_cells(
        maze: list[list[int]],
        visited_cells: list[Coord],
        prev_cells_dict: dict[Coord, Coord],
        cells_to_check: list[Coord]
) -> list[Coord]:
    """Return eligible adjacent cells not blocked by walls or visited.

    Args:
        maze: 2D list of each cells' wall info.
        visited_cells: List of cells' coordinates already visited.
        prev_cells_dict: Mapping of each cell's coordinates to the
            previous cell's coordinates used to reach it.
        cells_to_check: List of cells' coordinates to be checked.

    Returns:
        List of adjacent cells' coordinates that are eligible.
    """
    next_possible_cells: list[Coord] = []
    maze_width = len(maze[0])
    maze_height = len(maze)
    for current_cell in cells_to_check:
        current_cell_x = current_cell[0]
        current_cell_y = current_cell[1]
        maze_wall = maze[current_cell_y][current_cell_x]
        directions = ((0, -1), (1, 0), (0, 1), (-1, 0))
        for i, (dx, dy) in enumerate(directions):
            next_cell: Coord = (current_cell_x + dx,
                                current_cell_y + dy)
            # Check if the cell is out of bound
            if not (0 <= next_cell[0] < maze_width
                    and 0 <= next_cell[1] < maze_height):
                continue

            # Check if there is wall in between
            if (maze_wall >> i) & 1:
                continue

            # Check if the cell is visited
            if any(
                    next_cell == visited_cell
                    for visited_cell in visited_cells
            ):
                continue

            next_possible_cells.append(next_cell)
            visited_cells.append(next_cell)
            prev_cells_dict[next_cell] = current_cell

    return next_possible_cells


def breadth_first_search(
    entry: Coord,
    exit: Coord,
    maze: list[list[int]]
) -> list[Coord] | None:
    """Algorithm breadth first search used to solve the maze

    Args:
        entry: `(x, y)` coordinates of the maze entry.
        exit: `(x, y)` coordinates of the maze exit.
        maze: 2D-list of the wall-condition of each coordinates.

    Return:
        A 2D-list of the shortest path from entry to exit
    """

    prev_cells_dict: dict[Coord, Coord] = {}
    visited_cells: list[Coord] = [entry]
    next_possible_cells: list[Coord] = get_next_possible_cells(
        maze=maze,
        visited_cells=visited_cells,
        prev_cells_dict=prev_cells_dict,
        cells_to_check=[entry]
    )

    while (not is_solved(exit, visited_cells)) and next_possible_cells:
        last_visited: list[Coord] = next_possible_cells
        next_possible_cells = get_next_possible_cells(
            maze=maze,
            visited_cells=visited_cells,
            prev_cells_dict=prev_cells_dict,
            cells_to_check=last_visited
        )

    if not is_solved(exit, visited_cells):
        return None

    path_to_exit: list[Coord] = [exit]
    current_cell: Coord = exit
    while current_cell != entry:
        current_cell = prev_cells_dict[current_cell]
        path_to_exit.append(current_cell)

    return list(reversed(path_to_exit))
