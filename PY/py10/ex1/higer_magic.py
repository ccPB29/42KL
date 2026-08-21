from collections.abc import Callable


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    def combined(target: str, power: int) -> tuple[str, str]:
        return(
            spell1(target, power),
            spell2(target, power)
        )

    return combined


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    def mega_spell(target: str, power: int) -> str:
        amplified_power = power * multiplier
        return base_spell(target, amplified_power)

    return mega_spell


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    def conditional_spell(target: str, power: int) -> str:
        if condition(target, power):
            return spell(target, power)
        else:
            return "Spell fizzled"

    return conditional_spell


def spell_sequence(spells: list[Callable]) -> Callable:
    def sequence(target: str, power: int) -> list[str]:
        results = []
        for spell in spells:
            results.append(spell(target, power))
        return results

    return sequence

def fireball(target: str, power: int) -> str:
    return f"Fireball hits {target} with {power} power"


def heal(target: str, power: int) -> str:
    return f"Heal restores {target} with {power} power"


def strong_enough(target: str, power: int) -> bool:
    return power >= 20


def main() -> None:
    print()
    print("Testing spell combiner...")
    combined = spell_combiner(fireball, heal)
    print(f"Combined spell result: {combined('Dragon', 10)[0]}, {combined('Dragon', 10)[1]}")

    print("\nTesting power amplifier...")
    mega_fireball = power_amplifier(fireball, 3)
    print(f"Original: {fireball('Dragon', 10)}")
    print(f"Amplified: {mega_fireball('Dragon', 10)}")

    print("\nTesting conditional caster...")
    conditional = conditional_caster(strong_enough, fireball)
    print(conditional("Dragon", 30))
    print(conditional("Dragon", 10))

    print("\nTesting spell sequence...")
    sequence = spell_sequence([fireball, heal])
    print(sequence("Dragon", 20))


if __name__ == "__main__":
    main()
