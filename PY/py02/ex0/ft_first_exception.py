def input_temperature(temp_str: str) -> int:
    return int(temp_str)

def test_temperature() -> None:
    print(f"Input data is '{temp_str}'")
    try:
        temp = input_temperature(temp_str)
        print(f"Temperature is now {temp}")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")

if __name__ == "__main__":
    print("=== Garden Temperature ===")
    print()
    test_temperature("25")
    print()
    test_temperature("abc")
