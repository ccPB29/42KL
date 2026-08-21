from functools import reduce
from functools import partial
from functools import lru_cache
from functools import singledispatch
from collections.abc import Callable
import operator
from typing import Any


def spell_reducer(spells: list[int], operation: str) -> int:
    if not spells:
        return 0

    if operation == "add":
        return reduce(operator.add, spells)

    if operation == "multiply":
        return reduce(operator.mul, spells)

    if operation == "max":
        return reduce(max, spells)

    if operation == "min":
        return reduce(min, spells)

    raise ValueError("Unknown operation")


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:
    fire = partial(base_enchantment, power=50, element="Fire")

    ice = partial(base_enchantment, power=50, element="Ice")

    lightning = partial(base_enchantment, power=50, element="Lightning")

    return {
        "fire": fire,
        "ice": ice,
        "lightning": lightning,
    }


@lru_cache
def memoized_fibonacci(n: int) -> int:
    if n < 2:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:
    @singledispatch
    def cast_spell(value):
        return "Unknown spell type"

    @cast_spell.register
    def _(value: int):
        return f"Damage spell: {value} damage"

    @cast_spell.register
    def _(value: str):
        return f"Enchantment: {value}"

    @cast_spell.register
    def _(value: list) -> str:
        return f"Multi-cast: {len(value)} spells"

    return cast_spell


def base_enchantment(power: int, element: str, target: str) -> str:
    """Create an enchantment description."""
    return f"{element} enchantment on {target} with {power} power"


def main() -> None:
    """Test functools artifacts."""
    spells = [10, 20, 30, 40]

    print("\nTesting spell reducer...")
    print(f"Sum: {spell_reducer(spells, 'add')}")
    print(f"Product: {spell_reducer(spells, 'multiply')}")
    print(f"Max: {spell_reducer(spells, 'max')}")
    print(f"Min: {spell_reducer(spells, 'min')}")

    print("\nTesting partial enchanter...")
    enchants = partial_enchanter(base_enchantment)
    print(enchants["fire"](target="Dragon"))
    print(enchants["ice"](target="Dragon"))
    print(enchants["lightning"](target="Dragon"))

    print("\nTesting memoized fibonacci...")
    print(f"Fib(0): {memoized_fibonacci(0)}")
    print(f"Fib(1): {memoized_fibonacci(1)}")
    print(f"Fib(10): {memoized_fibonacci(10)}")
    print(f"Fib(15): {memoized_fibonacci(15)}")

    print("\nTesting spell dispatcher...")
    dispatcher = spell_dispatcher()
    print(dispatcher(42))
    print(dispatcher("fireball"))
    print(dispatcher(["fireball", "heal", "shield"]))
    print(dispatcher(3.14))


if __name__ == "__main__":
    main()
