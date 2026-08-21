PATTERN_42 = (
    "#...###",
    "#.....#",
    "###.###",
    "..#.#..",
    "..#.###",
)


def get_pattern_42(
    width: int,
    height: int
) -> set[tuple[int, int]]:
    """Return coordinates of the closed cells forming '42'."""
    pattern_height = len(PATTERN_42)
    pattern_width = len(PATTERN_42[0])

    if width < pattern_width + 2 or height < pattern_height + 2:
        print("Error: maze is too small to contain the '42' pattern.")
        return set()

    start_x = (width - pattern_width) // 2
    start_y = (height - pattern_height) // 2

    cells: set[tuple[int, int]] = set()

    for y, row in enumerate(PATTERN_42):
        for x, char in enumerate(row):
            if char == "#":
                cells.add((start_x + x, start_y + y))

    return cells
