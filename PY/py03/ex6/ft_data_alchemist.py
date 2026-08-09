import random


def main() -> None:
    players = [
        "Alice",
        "bob",
        "Charlie",
        "dylan",
        "Emma",
        "Gregory",
        "john",
        "kevin",
        "Liam",
    ]

    print("=== Game Data Alchemist ===")
    print()

    print(f"Initial list of players: {players}")

    capitalized_players = [name.capitalize() for name in players]
    print(
        f"New list with all names capitalized: "
        f"{capitalized_players}"
    )

    already_capitalized = [
        name for name in players
        if name == name.capitalize()
    ]
    print(
        f"New list of capitalized names only: "
        f"{already_capitalized}"
    )

    scores = {
        name: random.randint(0, 1000)
        for name in capitalized_players
    }

    print(f"Score dict: {scores}")

    average = sum(scores.values()) / len(scores)
    print(f"Score average is {round(average, 2)}")

    high_scores = {
        name: score
        for name, score in scores.items()
        if score > average
    }

    print(f"High scores: {high_scores}")


if __name__ == "__main__":
    main()
