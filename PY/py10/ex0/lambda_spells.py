def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    """Sort artifacts by power in descending order."""
    return sorted(
        artifacts,
        key=lambda artifact: artifact["power"],
        reverse=True,
    )


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    """Filter mages by minimum power."""
    return list(
        filter(
            lambda mage: mage["power"] >= min_power,
            mages
        )
    )


def spell_transformer(spells: list[str]) -> list[str]:
    """Transform spell names with decorative symbols."""
    return list(
            map(
                lambda spell: f"* {spell} *",
                spells
            )
    )

def mage_stats(mages: list[dict]) -> dict[str, int | float]:
    """Calculate maximum, minimum, and average mage power."""
    return {
        "max_power": max(mages, key=lambda mage: mage["power"])["power"],
        "min_power": min(mages, key=lambda mage: mage["power"])["power"],
        "avg_power": round(
            sum(map(lambda mage: mage["power"], mages)) / len(mages),
            2
        )
    }


if __name__ == "__main__":
    artifacts = [
        {"name": "Crystal Orb", "power": 85, "type": "magic"},
        {"name": "Fire Staff", "power": 92, "type": "weapon"},
    ]

    mages = [
        {"name": "Alice", "power": 80, "element": "fire"},
        {"name": "Bob", "power": 40, "element": "water"},
        {"name": "Charlie", "power": 60, "element": "earth"},
    ]

    spells = ["fireball", "heal", "shield"]

    print()
    print("Testing artifact sorter...")
    print(artifact_sorter(artifacts))

    print("\nTesting power filter...")
    print(power_filter(mages, 60))

    print("\nTesting spell transformer...")
    print(spell_transformer(spells))

    print("\nTesting mage stats...")
    print(mage_stats(mages))
