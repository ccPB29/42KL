from ex1 import HealingCreatureFactory, TransformCreatureFactory


def main() -> None:
    print("Testing Creature with healing capability")

    healing_factory = HealingCreatureFactory()

    print(" base:")
    base = healing_factory.create_base()
    print(base.describe())
    print(base.attack())
    print(base.heal())

    print(" evolved:")
    evolved = healing_factory.create_evolved()
    print(evolved.describe())
    print(evolved.attack())
    print(evolved.heal())

    print()
    print("Testing Creature with transform capability")

    transform_factory = TransformCreatureFactory()

    print(" base:")
    base_transform = transform_factory.create_base()
    print(base_transform.describe())
    print(base_transform.attack())
    print(base_transform.transform())
    print(base_transform.attack())
    print(base_transform.revert())

    print(" evolved:")
    evolved_transform = transform_factory.create_evolved()
    print(evolved_transform.describe())
    print(evolved_transform.attack())
    print(evolved_transform.transform())
    print(evolved_transform.attack())
    print(evolved_transform.revert())


if __name__ == "__main__":
    main()
