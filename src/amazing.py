from mazegen import MazeGenerator
import display
from output import output_maze
import time
import random
import subprocess
from prompt import instruction


def main() -> None:
    prompt_status: bool = False
    loop_strategy: bool = True
    animate: bool = True
    delay = 0.01
    seed: int = random.randint(0, 9999)
    width: int = 50
    height: int = 25
    start: tuple[int, int] = (0, 0)
    end: tuple[int, int] = ((width - 1), (height - 1))
    perfect = False
    strategy: int = 0
    stragety_list: list[str] = ["backtracking", 'hnk']
    generator = MazeGenerator(
        width, height, start, end, "output_maze.txt", seed, perfect
    )

    def my_draw(y: int, x: int) -> None:
        frame = display.output(generator, highlight=(y, x))
        print("\033[H" + frame, end="", flush=True)
        time.sleep(delay)

    while True:
        generator = MazeGenerator(
            width,
            height,
            start,
            end,
            "output_maze.txt",
            seed,
            perfect,
            stragety=strategy,
        )
        print("\033[2J\033[H", end="")
        if animate:
            generator.generate(my_draw)
        else:
            generator.generate()
        print(display.output(generator))
        output_maze(generator)
        result = subprocess.run(
            ["make", "check"], capture_output=True, text=True
        )
        print(stragety_list[strategy])
        print(result.stdout)
        time.sleep(5.0)
        # break
        if not prompt_status:
            if loop_strategy:
                strategy = (strategy + 1) % 2
            continue
        if prompt_status:
            seed, strategy, perfect = instruction(
                generator, seed, strategy, perfect
            )


if __name__ == "__main__":
    main()
