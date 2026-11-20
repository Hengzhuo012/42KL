Coord = tuple[int, int]


def is_solved(exit: Coord, visited_cells: set[Coord]) -> bool:
    """Check if it visited exit before
    Args:
        exit: `(x, y)` coordinates of the maze exit.
        visited_cells: set of `(x, y)` coordiantes visited

    Return:
        boolean value that if set visited_cells contained exit
    """
    if exit in visited_cells:
        return True
    return False


def get_next_valid_cells(
        maze: list[list[int]],
        visited_cells: set[Coord],
        prev_cells_dict: dict[Coord, Coord],
        cells_to_check: set[Coord]
) -> set[Coord]:
    """Return valid adjacent cells not blocked by walls or visited.

    Args:
        maze: 2D list of each cells' wall info.
        visited_cells: Set of cells' coordinates already visited.
        prev_cells_dict: Mapping of each cell's coordinates to the
            previous cell's coordinates used to reach it.
        cells_to_check: Set of cells' coordinates to be checked.

    Returns:
        Set of adjacent cells' coordinates that are valid.
    """
    next_valid_cells: set[Coord] = set()
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
            if next_cell in visited_cells:
                continue

            next_valid_cells.add(next_cell)
            visited_cells.add(next_cell)
            prev_cells_dict[next_cell] = current_cell

    return next_valid_cells


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
    visited_cells: set[Coord] = {entry}
    next_valid_cells: set[Coord] = get_next_valid_cells(
        maze=maze,
        visited_cells=visited_cells,
        prev_cells_dict=prev_cells_dict,
        cells_to_check={entry}
    )

    while (not is_solved(exit, visited_cells)) and next_valid_cells:
        last_visited: set[Coord] = next_valid_cells
        next_valid_cells = get_next_valid_cells(
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
