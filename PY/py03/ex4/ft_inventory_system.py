import sys


def main() -> None:
    print("=== Inventory System Analysis ===")

    inventory: dict[str, int] = {}

    for arg in sys.argv[1:]:
        if ":" not in arg:
            print(f"Error - invalid parameter '{arg}'")
            continue

        item, quantity = arg.split(":", 1)

        if item in inventory:
            print(f"Redundant item '{item}' - discarding")
            continue

        try:
            inventory[item] = int(quantity)
        except ValueError as error:
            print(f"Quantity error for '{item}': {error}")

    print(f"Got inventory: {inventory}")

    items = list(inventory.keys())
    print(f"Item list: {items}")

    total = sum(inventory.values())
    print(f"Total quantity of the {len(items)} items: {total}")

    for item in inventory:
        percentage = inventory[item] / total * 100
        print(
            f"Item {item} represents "
            f"{round(percentage, 1)}%"
        )

    most_item = items[0]
    least_item = items[0]

    for item in items:
        if inventory[item] > inventory[most_item]:
            most_item = item

        if inventory[item] < inventory[least_item]:
            least_item = item

    print(
        f"Item most abundant: {most_item} "
        f"with quantity {inventory[most_item]}"
    )
    print(
        f"Item least abundant: {least_item} "
        f"with quantity {inventory[least_item]}"
    )

    inventory.update({"magic_item": 1})
    print(f"Updated inventory: {inventory}")


if __name__ == "__main__":
    main()
