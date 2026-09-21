import sys


class Error(Exception):
    "Parameter Error"
    pass


class Redundant(Exception):
    "Redundant item"
    pass


def check_key(keys: list[str], key_to_check: str) -> bool:
    for key in keys:
        if key == key_to_check:
            return False
    return True


def set_inventory():
    inv: dict[str, int] = {}
    for arg in sys.argv[1:]:
        try:
            item = arg.split(":")
            if len(item) != 2:
                raise Error()
            else:
                key = item[0]
                value = int(item[1])
                if not check_key(inv.keys(), key):
                    raise Redundant(key)
                else:
                    inv[key] = value
        except Error:
            print(f"Error - invalid parameter '{item[0]}'")
        except Redundant as key:
            print(f"Redundant item '{key}' - discarding")
        except ValueError as e:
            print(f"Quantity error for '{key}': {e}")
    return inv


def ft_inventory_system():
    print("=== Inventory System Analysis ===")
    inv = set_inventory()
    print(f"Got inventory: {inv}")


if __name__ == "__main__":
    ft_inventory_system()
