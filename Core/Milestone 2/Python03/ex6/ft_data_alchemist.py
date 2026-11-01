import random


def ft_data_alchemist() -> None:
    print("=== Game Data Alchemist ===")
    print("")

    players_list = ["Alice", "bob", "Charlie", "dylan", "Emma", "Gregory",
                    "john", "kevin", "Liam"]
    capitalized_players_list = [player.capitalize() for player in players_list]
    already_capitalized = [player for player in players_list
                           if player[0].isupper()]
    print(f"Initial list of player: {players_list}")
    print(f"New list with all names capitalized: {capitalized_players_list}")
    print(f"New list of capitalized names only: {already_capitalized}")
    print("")

    players_dict = {player: random.randint(0, 1000)
                    for player in capitalized_players_list}
    print(f"Score dict: {players_dict}")
    average_score = sum(players_dict.values()) / len(players_dict)
    print(f"Score average is {average_score:.2f}")

    high_scores_dict = {player: score for player, score in players_dict.items()
                        if score > average_score}
    print(f"High scores: {high_scores_dict}")


if __name__ == "__main__":
    ft_data_alchemist()
