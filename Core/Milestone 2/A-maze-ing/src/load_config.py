from pydantic import BaseModel, Field, ValidationError, model_validator
import sys
from typing import Any


class Config(BaseModel):
    """Store maze configuration values.

    Attributes:
        width: Width of the maze.
        height: Height of the maze.
        entry: `(x, y)` coordinates of the maze entry.
        exit: `(x, y)` coordinates of the maze exit.
        output_file: Output filename.
        perfect: Whether the maze is perfect.
    """
    
    width: int = Field(ge=2, le=50)
    height: int = Field(ge=2, le=50)
    entry: tuple[int, int]
    exit: tuple[int, int]
    output_file: str = Field(min_length=4, max_length=20)
    perfect: bool
    
    strategy: 

    @model_validator(mode="after")
    def check_entry(self) -> "Config":
        """Validate that the entry coordinates are inside the maze."""
        x, y = self.entry
        if x >= self.width or y >= self.height:
            raise ValueError(
                f"Entry {self.entry} must be within width={self.width} "
                f"and height={self.height}"
            )
        return self

    @model_validator(mode="after")
    def check_exit(self) -> "Config":
        """Validate that exit coordinates are inside the maze
        and do not overlap the entry.
        """
        x_exit, y_exit = self.exit
        x_entry, y_entry = self.entry
        if (x_exit == x_entry) and (y_exit == y_entry):
            raise ValueError(
                f"Exit {self.exit} cannot be the same coordiantes as "
                f"entry {self.entry}"
            )
        if x_exit >= self.width or y_exit >= self.height:
            raise ValueError(
                f"Entry {self.entry} must be within width={self.width} "
                f"and height={self.height}"
            )
        return self

    @model_validator(mode="after")
    def check_output_file(self) -> "Config":
        """Validate that the output file ended with '.txt'"""
        if self.output_file[-4:] != ".txt":
            raise ValueError(
                f"Output file {self.output_file} must ended with '.txt'"
            )
        return self


def remove_comments(file_content: list[str]) -> list[str]:
    """Remove comments that starts with '#' in config.txt

    Args:
        file_content: a list of strings read from the config.txt

    Returns:
        a list of strings without comments.
    """
    for line in file_content:
        if line.startswith("#"):
            file_content.remove(line)
    return file_content


def load_config() -> Config:
    """Load the values from config.txt with exception handling

    Returns:
        A class of Config
    """
    try:
        with open("config.txt") as fd:
            file_content = fd.read().splitlines()
        file_content = remove_comments(file_content)
        config_dict: dict[str, Any] = {}
        for line in file_content:
            key, value = line.split("=", maxsplit=1)
            config_dict[key.strip()] = value.strip()
        config = Config(
            width=config_dict["WIDTH"],
            height=config_dict["HEIGHT"],
            entry=config_dict["ENTRY"].split(","),
            exit=config_dict["EXIT"].split(","),
            output_file=config_dict["OUTPUT_FILE"],
            perfect=config_dict["PERFECT"],
        )
    except FileNotFoundError as error:
        print(f"File Not Found, {error.strerror}: '{error.filename}'")
        sys.exit(1)
    except ValidationError as error_list:
        for error in error_list.errors():
            if error["loc"]:
                error_type = str(error["loc"][0])
                print(f"{error_type.capitalize()}-", end="")
            msg = error["msg"].removeprefix("Value error,")
            print(msg)
            sys.exit(1)
    return config
