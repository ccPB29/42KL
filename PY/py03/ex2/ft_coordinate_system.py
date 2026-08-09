import math


def get_player_pos() -> tuple[float, float, float]:
    while True:
        user_input = input(
            "Enter new coordinates as floats in format 'x,y,z': "
        )

        parts = user_input.split(",")

        if len(parts) != 3:
            print("Invalid syntax")
            continue

        values: list[float] = []

        for part in parts:
            try:
                values.append(float(part))
            except ValueError as error:
                print(f"Error on parameter '{part}': {error}")
                break
        else:
            return (values[0], values[1], values[2])


def distance(
    pos1: tuple[float, float, float],
    pos2: tuple[float, float, float]
) -> float:
    return math.sqrt(
        (pos2[0] - pos1[0]) ** 2
        + (pos2[1] - pos1[1]) ** 2
        + (pos2[2] - pos1[2]) ** 2
    )


def main() -> None:
    print("=== Game Coordinate System ===")
    print()

    print("Get a first set of coordinates")
    first = get_player_pos()

    print(f"Got first tuple: {first}")
    print(
        f"It includes: X={first[0]}, "
        f"Y={first[1]}, Z={first[2]}"
    )

    center = (0.0, 0.0, 0.0)
    print(
        f"Distance to center: "
        f"{round(distance(first, center), 4)}"
    )

    print()
    print("Get a second set of coordinates")
    second = get_player_pos()

    print(
        "Distance between the 2 sets of coordinates: "
        f"{round(distance(first, second), 4)}"
    )


if __name__ == "__main__":
    main()
