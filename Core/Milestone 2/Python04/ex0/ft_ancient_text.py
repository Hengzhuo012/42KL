import sys
import typing






def ft_acient_text():
    try:
        file_handle = open(sys.argv[1])
    except FileNotFoundError as e:
        print(f"File Not Found Error: {e}")


if __name__ == "__main__":
    ft_acient_text()
