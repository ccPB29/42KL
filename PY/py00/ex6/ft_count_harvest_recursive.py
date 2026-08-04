def ft_count_harvest_recursive() -> None:
    d = int(input("Days until harvest: "))

    def circle(d: int) -> None:
        if d > 1:
            circle(d - 1)
        print(f"Day {d}")

    circle(d)
    print("Harvest time!")
