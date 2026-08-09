import sys
import typing


def read_file(filename: str) -> None:
    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{filename}'")

    try:
        file: typing.IO = open(filename, "r")
    except OSError as error:
        print(f"Error opening file '{filename}': {error}")
        return

    print("---")
    print()

    content = file.read()
    print(content, end="")

    print()
    print("---")

    file.close()
    print(f"File '{filename}' closed.")


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
        return

    read_file(sys.argv[1])


if __name__ == "__main__":
    main()

# cat > ancient_fragment.txt << 'EOF'
# [FRAGMENT 001] Digital preservation protocols established 2087
# [FRAGMENT 002] Knowledge must survive the entropy wars
# [FRAGMENT 003] Every byte saved is a victory against oblivion
# EOF