import sys
import typing


def read_file(filename: str) -> None:
    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{filename}'")

    try:
        file: typing.IO = open(filename, "r")
    except OSError as error:
        sys.stderr.write(
            f"[STDERR] Error opening file '{filename}': {error}\n"
        )
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

    new_content = ""

    for char in content:
        if char == "\n":
            new_content += "#\n"
        else:
            new_content += char

    if len(content) > 0 and content[-1] != "\n":
        new_content += "#"

    print(new_content, end="")

    print()
    print("---")

    sys.stdout.write("Enter new file name (or empty): ")
    sys.stdout.flush()

    new_filename = sys.stdin.readline()
    if len(new_filename) > 0 and new_filename[-1] == "\n":
        new_filename = new_filename[:-1]

    if new_filename == "":
        sys.stdout.write("Not saving data.\n")
        return

    try:
        new_file: typing.IO = open(new_filename, "w")
    except OSError as error:
        sys.stderr.write(
            f"[STDERR] Error opening file '{new_filename}': {error}\n"
            "Data not saved.\n"
        )
        return

    print(f"Saving data to '{new_filename}'")
    new_file.write(new_content)
    print(f"Data saved in file '{new_filename}'.")
    new_file.close()


def main() -> None:
    if len(sys.argv) != 2:
        sys.stderr.write("Usage: ft_stream_management.py <file>\n")
        return

    read_file(sys.argv[1])


if __name__ == "__main__":
    main()

# cat > ancient_fragment.txt << 'EOF'
# [FRAGMENT 001] Digital preservation protocols established 2087
# [FRAGMENT 002] Knowledge must survive the entropy wars
# [FRAGMENT 003] Every byte saved is a victory against oblivion
# EOF