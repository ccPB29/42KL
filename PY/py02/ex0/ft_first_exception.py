def input_temperature(temp_str: str) -> int:
    return int(temp_str)


def test_temperature() -> None:
    try:
        print("Input data is '25'")
        print(f"Temperature is now {input_temperature('25')}°C")
        print()
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
        print()

    try:
        print("Input data is 'abc'")
        print(f"Temperature is now {input_temperature('abc')}°C")
        print()
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
        print()

    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    print("=== Garden Temperature ===")
    print()
    test_temperature()
