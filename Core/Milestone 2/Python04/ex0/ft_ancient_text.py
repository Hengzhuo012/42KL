import sys
import typing


class UsageError(Exception):
    "Expected exactly 1 argument"
    pass


def read_file(file_handle: typing.IO[str]) -> str:
    return file_handle.read()


def ft_acient_text():
    file_name = ""
    try:
        if len(sys.argv) != 2:
            raise UsageError()

        print("=== Cyber Archives Recovery ===")
        file_name = sys.argv[1]
        print(f"Accessing file '{file_name}'")
        file_handle = open(file_name, 'r')

        text = read_file(file_handle)
        print("---\n")
        print(text)
        print("\n---")

        file_handle.close()
        print(f"File '{file_name}' closed.")
    except UsageError:
        print("Usage: ft_ancient_text.py <file>")
    except OSError as e:
        print(f"Error opening file '{file_name}': {e}")


if __name__ == "__main__":
    ft_acient_text()
