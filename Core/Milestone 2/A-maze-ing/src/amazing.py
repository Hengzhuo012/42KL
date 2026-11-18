from mazegen import MazeGenerator
import display
from output import output_maze
import time
import random
import subprocess
from prompt import instruction
from load_config import load_config


def main() -> None:
    config = load_config()
    prompt_status: bool = True
    loop_strategy: bool = True
    animate: bool = True
    delay: float = 0.01
    seed: int = random.randint(0, 9999)
    strategy: int = 0
    stragety_list: list[str] = ["backtracking", "hnk"]
    generator = MazeGenerator(
        width=config.width,
        height=config.height,
        entry=config.entry,
        end=config.exit,
        output_file=config.output_file,
        seed=seed,
        perfect=config.perfect,
    )

    def my_draw(y: int, x: int) -> None:
        frame = display.output(generator, highlight=(y, x))
        print("\033[H" + frame, end="", flush=True)
        time.sleep(delay)

    while True:
        generator = MazeGenerator(
            width=config.width,
            height=config.height,
            entry=config.entry,
            end=config.end,
            output_file=config.output_file,
            seed=seed,
            perfect=config.perfect,
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
                generator, seed, strategy, config.perfect
            )


if __name__ == "__main__":
    main()
