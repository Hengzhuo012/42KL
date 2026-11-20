from mazegen import MazeGenerator
import display
from output import output_maze
import time
from prompt import instruction
from load_config import load_config
from solver import breadth_first_search
import random


def main() -> None:
    config = load_config()
    prompt_status: bool = False
    animate: bool = True
    delay: float = 0.01
    generator = MazeGenerator(
        width=config.width,
        height=config.height,
        entry=config.entry,
        exit=config.exit,
        output_file=config.output_file,
        seed=config.seed,
        perfect=config.perfect,
        strategy=config.strategy,
    )

    def my_draw(highlight: list[tuple[int, int]]) -> None:
        frame = display.output(generator, highlight=highlight)
        print("\033[H" + frame, end="", flush=True)
        time.sleep(delay)

    while True:
        generator = MazeGenerator(
            width=config.width,
            height=config.height,
            entry=config.entry,
            exit=config.exit,
            output_file=config.output_file,
            seed=config.seed,
            perfect=config.perfect,
            strategy=config.strategy,
        )
        print("\033[2J\033[H", end="")
        if animate:
            generator.generate(my_draw)
        else:
            generator.generate()

        answer: str | None = None
        if animate:
            result = breadth_first_search(
                generator.entry, generator.exit, generator.maze, my_draw
            )
        else:
            result = breadth_first_search(
                generator.entry, generator.exit, generator.maze
            )
        output_maze(generator, answer)
        try:
            if result is None:
                raise Exception
            else:
                answer, solve_path = result
        except Exception:
            print("No valid path to exit")
        print("\033[2J\033[H", end="")
        print(display.output(generator, solve_path))
        time.sleep(5.0)
        # break
        config.strategy = config.strategy.next()
        if not prompt_status:
            config.strategy.next()
            config.seed = random.randint(0, 9999)
            config.perfect = random.choice([True, False])
            continue
        if prompt_status:
            config.seed, config.strategy, config.perfect = instruction(
                generator, config.seed, config.strategy, config.perfect
            )


if __name__ == "__main__":
    main()
