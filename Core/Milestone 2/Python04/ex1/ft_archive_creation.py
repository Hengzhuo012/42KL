import sys
import typing


class UsageError(Exception):
    "Expected exactly 1 argument"
    pass


def open_file(file_name: str, mode: str) -> typing.IO[str] | None:
    try:
        file_handle = open(file_name, mode)
        return file_handle
    except OSError as e:
        print(f"Error opening file '{file_name}': {e}")
        return None


def read_file(file_handle: typing.IO[str]) -> str:
    return file_handle.read()


def display_text(text: str):
    print("---\n")
    print(text)
    print("\n---")


def write_file(text: str, file_name: str, file_handle: typing.IO[str]) -> None:
    try:
        file_handle.write(text)
        print(f"Data saved in file '{file_name}'")
    except OSError as e:
        print(f"Error writing file: {e}")
        print("Data not saved.")


def close_file(file_handle: typing.IO[str]) -> None:
    file_handle.close()


def add_hashtag_to_lines(text: str) -> str:
    result = ""
    for char in text:
        if char == "\n":
            result += "#"
        result += char
    result += "#"
    return result


def ft_archive_creation():
    try:
        if len(sys.argv) != 2:
            raise UsageError()

        print("=== Cyber Archives Recovery & Preservation ===")
        file_name = sys.argv[1]
        print(f"Accessing file '{file_name}'")
        file_handle = open_file(file_name, 'r')
        if file_handle is None:
            return
        text = read_file(file_handle)
        display_text(text)
        close_file(file_handle)
        print(f"File '{file_name}' closed.")
        print("")

        print("Transform data:")
        text = add_hashtag_to_lines(text)
        display_text(text)
        print("")

        new_file_name = input("Enter new file name (or empty): ")
        if new_file_name == "":
            print("Not saving data.")
            return
        new_file_handle = open_file(new_file_name, 'w')
        if new_file_handle is None:
            return
        print(f"Saving data to '{new_file_name}'")
        write_file(text, new_file_name, new_file_handle)
        close_file(new_file_handle)
    except UsageError:
        print("Usage: ft_ancient_text.py <file>")


if __name__ == "__main__":
    ft_archive_creation()
