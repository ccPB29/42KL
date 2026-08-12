from ex0 import AquaFactory, CreatureFactory, FlameFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import (
    AggressiveStrategy,
    BattleStrategy,
    DefensiveStrategy,
    InvalidStrategyError,
    NormalStrategy,
)


def battle(
    opponents: list[tuple[CreatureFactory, BattleStrategy]],
) -> None:
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")

    creatures = []

    for factory, strategy in opponents:
        creatures.append((factory.create_base(), strategy))

    try:
        for i in range(len(creatures)):
            for j in range(i + 1, len(creatures)):
                first, first_strategy = creatures[i]
                second, second_strategy = creatures[j]

                print("* Battle *")
                print(first.describe())
                print("vs.")
                print(second.describe())
                print("now fight!")

                for action in first_strategy.act(first):
                    print(action)

                for action in second_strategy.act(second):
                    print(action)

    except InvalidStrategyError as error:
        print(f"Battle error, aborting tournament: {error}")


def main() -> None:
    print("Tournament 0 (basic)")
    battle([
        (FlameFactory(), NormalStrategy()),
        (HealingCreatureFactory(), DefensiveStrategy()),
    ])

    print("Tournament 1 (error)")
    battle([
        (FlameFactory(), AggressiveStrategy()),
        (HealingCreatureFactory(), DefensiveStrategy()),
    ])

    print("Tournament 2 (multiple)")
    battle([
        (AquaFactory(), NormalStrategy()),
        (HealingCreatureFactory(), DefensiveStrategy()),
        (TransformCreatureFactory(), AggressiveStrategy()),
    ])


if __name__ == "__main__":
    main()
