import random


def gen_player_achievements() -> set[str]:
    achievement = ["Crafting Genius", "World Savior", "Master Explorer",
                   "Collector Supreme", "Untouchable", "Boss Slayer",
                   "Strategist", "Unstoppable", "Speed Runner", "Survivor",
                   "Treasure Hunter", "First Steps", "Sharp Mind"]
    number_of_achievements = random.randint(0, len(achievement))
    result = set(random.sample(achievement, number_of_achievements))
    return result


def ft_achievement_tracker():
    print("=== Achievement Tracker System ===")
    print("")

    alice = gen_player_achievements()
    bob = gen_player_achievements()
    charlie = gen_player_achievements()
    dylan = gen_player_achievements()
    print(f"Player Alice: {alice}")
    print(f"Player Bob: {bob}")
    print(f"Player Charlie: {charlie}")
    print(f"Player Dylan: {dylan}")
    print("")

    print(f"All distinct achievements: {alice.union(bob, charlie, dylan)}")
    print("")
    print(f"Common achievements: {alice.intersection(bob, charlie, dylan)}")
    print("")

    print(f"Only Alice has: {alice.difference(bob.union(charlie, dylan))}")
    print(f"Only Bob has: {bob.difference(alice.union(charlie, dylan))}")
    print(f"Only Charlie has: {charlie.difference(alice.union(bob, dylan))}")
    print(f"Only Dylan has: {dylan.difference(alice.union(bob, charlie))}")
    print("")

    print(f"Alice is missing: {(bob.union(charlie, dylan).difference(alice))}")
    print(f"Bob is missing: {alice.union(charlie, dylan).difference(bob)}")
    print(f"Charile is missing: {alice.union(bob, dylan).difference(charlie)}")
    print(f"Dylan is missing: {alice.union(bob, charlie).difference(dylan)}")


if __name__ == "__main__":
    ft_achievement_tracker()
