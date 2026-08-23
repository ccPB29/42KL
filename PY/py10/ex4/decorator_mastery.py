from functools import wraps
from collections.abc import Callable
from typing import Any
import time


def spell_timer(func: Callable) -> Callable:
    @wraps(func)
    def wrapper(*args: Any, **kwargs: Any) -> Any:
        print(f"Casting {func.__name__}...")

        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()

        print(f"Spell completed in {end - start:.3f} seconds")
        return result

    return wrapper


@spell_timer
def fireball() -> str:
    time.sleep(0.101)
    return "Fireball cast!"


def power_validator(min_power: int) -> Callable:
    def decorator(func: Callable) -> Callable:
        @wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            power = kwargs.get("power")
            if power is None and args:
                power = args[-1]
            if not isinstance(power, int):
                return "Invalid power"
            if power >= min_power:
                return func(*args, **kwargs)
            return "Insufficient power for this spell"

        return wrapper

    return decorator


@power_validator(10)
def ice_blast(spell_name: str, power: int) -> str:
    return f"{spell_name} cast with {power} power"


def retry_spell(max_attempts: int) -> Callable:
    def decorator(func: Callable) -> Callable:
        @wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            for n in range(1, max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    if n < max_attempts:
                        print(
                            f"Spell failed, retrying... "
                            f"(attempt {n}/{max_attempts})"
                        )

            return (
                f"Spell casting failed after "
                f"{max_attempts} attempts"
            )

        return wrapper

    return decorator


@retry_spell(3)
def unstable_spell() -> str:
    raise Exception("Spell failed")


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        return len(name) >= 3 and all(
            char.isalpha() or char.isspace()
            for char in name
        )

    @power_validator(10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return f"Successfully cast {spell_name} with {power} power"


def main() -> None:
    print("Testing spell timer...")
    result = fireball()
    print(f"Result: {result}")

    print()
    print("Testing power validator...")
    print(ice_blast("Ice Blast", 15))
    print(ice_blast("Ice Blast", 5))

    print()
    print("Testing retrying spell...")
    print(unstable_spell())
    print("Waaaaaaagh spelled !")

    print()
    print("Testing MageGuild...")
    guild = MageGuild()

    print(guild.validate_mage_name("Gandalf"))
    print(guild.validate_mage_name("A1"))

    print(guild.cast_spell("Lightning", 15))
    print(guild.cast_spell("Fireball", 5))


if __name__ == "__main__":
    main()
