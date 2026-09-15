def ft_count_harvest_recursive():
    days = int(input("Days until harvest: "))
    recursive_helper(days)
    print("Harvest time!")


def recursive_helper(days: int):
    if (days == 1):
        print("Day 1")
    else:
        recursive_helper(days - 1)
        print(f'Day {days}')
