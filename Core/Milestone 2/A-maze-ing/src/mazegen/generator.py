from collections.abc import Callable
import math
import random
from header_file import StrategyType


class MazeGenerator:
    def __init__(
        self,
        width: int,
        height: int,
        entry: tuple,
        exit: tuple,
        output_file: str,
        seed: int | None = None,
        perfect: bool = False,
        color: int = 0,
        color_42: int = 96,
        strategy: StrategyType = StrategyType.DEPTH_FIRST_SEARCH,
    ):
        self.width = width
        self.height = height
        self.entry = entry
        self.exit = exit
        self.output_file = output_file
        self.seed = seed
        self.perfect = perfect
        self.rng = random.Random(self.seed)
        self.maze: list[list[int]] = []
        self.visited: list[list[bool]] = []
        self.cells_42: set[tuple[int, int]] = set()
        self.color = color
        self.color_42 = color_42
        self.strategy = strategy

    def pattern_42(self) -> None:
        x: int = round(self.width / 2 - 1) - 3
        y: int = math.ceil(self.height / 2 - 1) - 2
        offsets: list[tuple[int, int]] = [
            (0, 0),
            (0, 4),
            (0, 5),
            (0, 6),
            (1, 0),
            (1, 6),
            (2, 0),
            (2, 1),
            (2, 2),
            (2, 4),
            (2, 5),
            (2, 6),
            (3, 2),
            (3, 4),
            (4, 2),
            (4, 4),
            (4, 5),
            (4, 6),
        ]
        self.cells_42 = {(y + dy, x + dx) for dy, dx in offsets}
        for dy, dx in self.cells_42:
            self.visited[dy][dx] = True

    def imperfect_insert(self, y: int, x: int) -> None:
        directions = [(-1, 0, 1, 4), (0, 1, 2, 8), (1, 0, 4, 1), (0, -1, 8, 2)]
        edge_dead_end_open: list[tuple] = []
        if self.maze[y][x] in (7, 11, 13, 14, 15):
            for direction in directions:
                dy, dx, nb, ob = direction
                nx = x + dx
                ny = y + dy
                if (15 - self.maze[y][x]) == ob or self.maze[y][x] == 15:
                    if (
                        0 <= nx < self.width
                        and 0 <= ny < self.height
                        and (ny, nx) not in self.cells_42
                    ):
                        self.maze[y][x] -= nb
                        self.maze[ny][nx] -= ob
                        break
                elif (
                    self.maze[y][x] & nb
                    and 0 <= nx < self.width
                    and 0 <= ny < self.height
                    and (ny, nx) not in self.cells_42
                ):
                    edge_dead_end_open.append((y, x, ny, nx, nb, ob))
            if self.maze[y][x] in (7, 11, 13, 14) and edge_dead_end_open:
                cy, cx, ny, nx, nb, ob = random.choice(edge_dead_end_open)
                self.maze[cy][cx] -= nb
                self.maze[ny][nx] -= ob

    def backtracking(
        self, animation: Callable[[int, int], None] | None = None
    ) -> None:
        directions = [(-1, 0, 1, 4), (0, 1, 2, 8), (1, 0, 4, 1), (0, -1, 8, 2)]
        path: list[list[tuple[int, int, int, int, int, int]]] = [[]]
        x: int = self.rng.randint(0, self.width - 1)
        y: int = self.rng.randint(0, self.height - 1)
        if (y, x) in self.cells_42:
            x = round(self.width / 2 - 1)
            y = math.ceil(self.height / 2 - 1)
        sx = x
        sy = y
        while path:
            candidate: list[tuple[int, int, int, int, int, int]] = []
            self.visited[y][x] = True
            for direction in directions:
                dy, dx, nb, ob = direction
                nx = x + dx
                ny = y + dy
                if 0 <= nx < self.width and 0 <= ny < self.height:
                    if not self.visited[ny][nx]:
                        candidate.append((y, x, ny, nx, nb, ob))

            if not candidate:
                if not self.perfect:
                    self.imperfect_insert(y, x)
                while path and not path[-1]:
                    path.pop()
            else:
                path.append(candidate)

            while path and path[-1]:
                idx = self.rng.randrange(len(path[-1]))
                item = path[-1].pop(idx)
                cy, cx, ny, nx, nb, ob = item
                if not self.visited[ny][nx]:
                    self.maze[cy][cx] -= nb
                    self.maze[ny][nx] -= ob
                    y, x = ny, nx
                    if animation is not None:
                        animation(x, y)
                    break

        if not self.perfect:
            self.imperfect_insert(sy, sx)

    def hnk(self, animation: Callable[[int, int], None] | None = None) -> None:
        directions = [(-1, 0, 1, 4), (0, 1, 2, 8), (1, 0, 4, 1), (0, -1, 8, 2)]
        x: int = self.rng.randint(0, self.width - 1)
        y: int = self.rng.randint(0, self.height - 1)
        if (y, x) in self.cells_42:
            x = round(self.width / 2 - 1)
            y = math.ceil(self.height / 2 - 1)
        sx = x
        sy = y
        while True:
            candidate: list[tuple[int, int, int, int, int, int]] = []
            self.visited[y][x] = True
            for direction in directions:
                dy, dx, nb, ob = direction
                nx = x + dx
                ny = y + dy
                if 0 <= nx < self.width and 0 <= ny < self.height:
                    if not self.visited[ny][nx]:
                        candidate.append((y, x, ny, nx, nb, ob))

            if not candidate:
                if not self.perfect:
                    self.imperfect_insert(y, x)
                found: bool = False
                for hy in range(self.height):
                    for hx in range(self.width):
                        if (hy, hx) not in self.cells_42 and self.visited[hy][
                            hx
                        ]:
                            for direction in directions:
                                dy, dx, nb, ob = direction
                                nx = hx + dx
                                ny = hy + dy
                                if (
                                    0 <= nx < self.width
                                    and 0 <= ny < self.height
                                ):
                                    if not self.visited[ny][nx]:
                                        y = hy
                                        x = hx
                                        found = True
                                        break
                        if found:
                            break
                    if found:
                        break
                if not found:
                    if not self.perfect:
                        self.imperfect_insert(sy, sx)
                    break
            else:
                idx = self.rng.randrange(len(candidate))
                item = candidate.pop(idx)
                cy, cx, ny, nx, nb, ob = item
                if not self.visited[ny][nx]:
                    self.maze[cy][cx] -= nb
                    self.maze[ny][nx] -= ob
                    y, x = ny, nx
                    if animation is not None:
                        animation(x, y)

    def generate(
        self, animation: Callable[[int, int], None] | None = None
    ) -> None:
        for y in range(self.height):
            row: list[int] = []
            visited: list[bool] = []
            for x in range(self.width):
                row.append(15)
                visited.append(False)
            self.maze.append(row)
            self.visited.append(visited)
        if self.width > 8 and self.height > 6:
            self.pattern_42()
        if self.strategy == StrategyType.DEPTH_FIRST_SEARCH:
            self.backtracking(animation)
        elif self.strategy == StrategyType.HUNT_AND_KILL:
            self.hnk(animation)
