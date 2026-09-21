import math


class SyntaxError(Exception):
    "Invalid syntax"
    pass


def check_input_is_float(str_input: str) -> tuple[float, float, float] | None:
    coord = ""
    try:
        temp_list: list[float] = []
        string_list = str_input.split(",")
        if len(string_list) != 3:
            raise SyntaxError()

        for coord in string_list:
            coord = coord.strip()
            coord = float(coord)
            temp_list.append(coord)
        return temp_list[0], temp_list[1], temp_list[2]

    except SyntaxError:
        print("Invalid Syntax")
        return None
    except ValueError as e:
        print(f"Error on parameter '{coord}': {e}")
        return None


def get_player_pos() -> tuple[float, float, float]:
    coord_tuple = None
    while coord_tuple is None:
        str_input = input("Enter new coordinates as "
                          "floats in format 'x,y,z': ")
        coord_tuple = check_input_is_float(str_input)
    return coord_tuple


def distance_between_two_points(coord1: tuple[float, float, float],
                                coord2: tuple[float, float, float]) -> float:
    return math.sqrt((coord1[0] - coord2[0])**2 + (coord1[1] - coord2[1])**2 +
                     (coord1[2] - coord2[2])**2)


def ft_coordinate_system():
    print("=== Game Coordinate System ===")
    print("")
    print("Get a first set of coordinates")
    coord1 = get_player_pos()
    print(f"Got a first tuple: ({coord1[0]:.1f}, {coord1[1]:.1f}, "
          f"{coord1[2]:.1f})")
    print(f"It includes: X={coord1[0]:.1f}, Y={coord1[1]:.1f}, "
          f"Z={coord1[2]:.1f}")
    distance_to_center = distance_between_two_points(coord1, (0, 0, 0))
    print(f"Distance to center: {distance_to_center:.4f}")
    print("")

    print("Get a second set of coordinates")
    coord2 = get_player_pos()
    distance = distance_between_two_points(coord1, coord2)
    print(f"Distance between the 2 sets of coordinates: {distance:.4f}")


if __name__ == "__main__":
    ft_coordinate_system()
