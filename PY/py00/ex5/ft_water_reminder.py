def ft_water_reminder() -> None:
    wd = int(input("Days since last watering: "))
    if wd > 2:
        print("Water the plants!")
    else:
        print("Plants are fine")
