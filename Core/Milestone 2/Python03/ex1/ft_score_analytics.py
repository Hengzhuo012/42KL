import sys


def convert_str_to_int(string: str):
    try:
        return (int(string))
    except ValueError:
        print(f"Invalid parameter: '{string}'")


def ft_score_analytics():
    print("=== Player Score Analytics ===")
    size = len(sys.argv)
    scores_list: list[int] = []
    for i in range(size - 1):
        score = convert_str_to_int(sys.argv[i + 1])
        if score:
            scores_list.append(score)
    if len(scores_list):
        print(f"Scores proccessed: {scores_list}")
        print(f"Total players: {len(scores_list)}")
        print(f"Total score: {sum(scores_list)}")
        print(f"Average score: {sum(scores_list) / len(scores_list):.1f}")
        print(f"High score: {max(scores_list)}")
        print(f"Low score: {min(scores_list)}")
        print(f"Score range: {max(scores_list) - min(scores_list)}")
    else:
        print("No scores provided. Usage: python3 ft_score_analytics.py "
              "<score1> <score2> ...")


if __name__ == "__main__":
    ft_score_analytics()
