def ft_count_harvest_recursive():
    d = int(input("Days until harvest: "))

    def circle(d):
        if d > 1:
            circle(d - 1)
        print(f"Day {d}")

    circle(d)
    print("Harvest time!")
