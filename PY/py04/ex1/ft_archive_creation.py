import sys
import typing


def read_file(filename: str) -> None:
    print("=== Cyber Archives Recovery & Preservation ===")
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

    print()
    print("Transform data:")

    print("---")
    print()

    new_content = content.replace("\n", "#\n")

    if len(content) > 0 and content[-1] != "\n":
        new_content += "#"

    print(new_content, end="")

    print()
    print("---")

    new_filename = input("Enter new file name (or empty): ")
    if new_filename == "":
        print("Not saving data.")
        return

    new_file: typing.IO = open(new_filename, "w")
    print(f"Saving data to '{new_filename}'")
    new_file.write(new_content)
    print(f"Data saved in file '{new_filename}'.")
    new_file.close()


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_archive_creation.py <file>")
        return

    read_file(sys.argv[1])


if __name__ == "__main__":
    main()

# cat > ancient_fragment.txt << 'EOF'
# [FRAGMENT 001] Digital preservation protocols established 2087
# [FRAGMENT 002] Knowledge must survive the entropy wars
# [FRAGMENT 003] Every byte saved is a victory against oblivion
# EOF