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


def set_inventory() -> dict[str, int]:
    inv: dict[str, int] = {}
    for arg in sys.argv[1:]:
        item = arg.split(":")
        key = item[0]
        try:
            if len(item) != 2:
                raise Error()
            value = int(item[1])
            if not check_key(list(inv.keys()), key):
                raise Redundant(key)
            inv[key] = value
        except Error:
            print(f"Error - invalid parameter '{arg}'")
        except Redundant as redundant_item:
            print(f"Redundant item '{redundant_item}' - discarding")
        except ValueError as e:
            print(f"Quantity error for '{key}': {e}")
    return inv


def ft_inventory_system():
    print("=== Inventory System Analysis ===")
    inv = set_inventory()
    print(f"Got inventory: {inv}")

    print(f"Item list: {list(inv.keys())}")
    total_quantity = sum(inv.values())
    print(f"Total quantity of the {len(inv)} items: {total_quantity}")

    keys = list(inv.keys())
    values = list(inv.values())

    if len(values) > 0:
        biggest_index = 0
        smallest_index = 0
        index = 0

        while index < len(values):
            item = keys[index]
            quantity = values[index]
            percentage = round(quantity / total_quantity * 100, 1)
            print(f"Item {item} represents {percentage}%")
            if quantity > values[biggest_index]:
                biggest_index = index
            if quantity < values[smallest_index]:
                smallest_index = index
            index += 1

        print(f"Item most abundant: {keys[biggest_index]} "
              f"with quantity {values[biggest_index]}")
        print(f"Item least abundant: {keys[smallest_index]} "
              f"with quantity {values[smallest_index]}")

    inv.update({"magic_item": 1})
    print(f"Updated inventory: {inv}")


if __name__ == "__main__":
    ft_inventory_system()
