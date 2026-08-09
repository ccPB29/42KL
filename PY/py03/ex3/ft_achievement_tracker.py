import random


ALL_ACHIEVEMENTS = {
    "First Steps",
    "Boss Slayer",
    "Speed Runner",
    "Treasure Hunter",
    "Master Explorer",
    "Collector Supreme",
    "Untouchable",
    "Strategist",
    "Survivor",
    "World Savior",
    "Crafting Genius",
    "Sharp Mind",
    "Unstoppable",
    "Hidden Path Finder",
}


def gen_player_achievements() -> set[str]:
    count = random.randint(6, 10)
    return set(random.sample(list(ALL_ACHIEVEMENTS), count))


def main() -> None:
    alice = gen_player_achievements()
    bob = gen_player_achievements()
    charlie = gen_player_achievements()
    dylan = gen_player_achievements()

    print("=== Achievement Tracker System ===")
    print()

    print(f"Player Alice: {alice}")
    print(f"Player Bob: {bob}")
    print(f"Player Charlie: {charlie}")
    print(f"Player Dylan: {dylan}")
    print()

    all_distinct = alice.union(bob, charlie, dylan)
    common = alice.intersection(bob, charlie, dylan)

    print(f"All distinct achievements: {all_distinct}")
    print(f"Common achievements: {common}")
    print()

    print(
        f"Only Alice has: "
        f"{alice.difference(bob.union(charlie, dylan))}"
    )
    print(
        f"Only Bob has: "
        f"{bob.difference(alice.union(charlie, dylan))}"
    )
    print(
        f"Only Charlie has: "
        f"{charlie.difference(alice.union(bob, dylan))}"
    )
    print(
        f"Only Dylan has: "
        f"{dylan.difference(alice.union(bob, charlie))}"
    )
    print()

    print(f"Alice is missing: {ALL_ACHIEVEMENTS.difference(alice)}")
    print(f"Bob is missing: {ALL_ACHIEVEMENTS.difference(bob)}")
    print(f"Charlie is missing: {ALL_ACHIEVEMENTS.difference(charlie)}")
    print(f"Dylan is missing: {ALL_ACHIEVEMENTS.difference(dylan)}")


if __name__ == "__main__":
    main()
