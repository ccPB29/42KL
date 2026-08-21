"""Detect and display the current Python environment."""

import os
import site
import sys


def in_virtual_environment() -> bool:
    """Return whether Python is running inside a virtual environment."""
    return sys.prefix != sys.base_prefix


def show_global_environment() -> None:
    """Display information for the global Python environment."""
    print()
    print("MATRIX STATUS: You're still plugged in")
    print()
    print(f"Current Python: {sys.executable}")
    print("Virtual Environment: None detected")
    print()
    print("WARNING: You're in the global environment!")
    print("The machines can see everything you install.")
    print()
    print("Package installation path:")
    print(site.getsitepackages()[0])
    print()
    print("To enter the construct, run:")
    print("python -m venv matrix_env")
    print("source matrix_env/bin/activate  # On Unix")
    print(r"matrix_env\Scripts\activate  # On Windows")
    print()
    print("Then run this program again.")


def show_virtual_environment() -> None:
    """Display information for the active virtual environment."""
    env_path = sys.prefix
    env_name = os.path.basename(env_path)

    print()
    print("MATRIX STATUS: Welcome to the construct")
    print()
    print(f"Current Python: {sys.executable}")
    print(f"Virtual Environment: {env_name}")
    print()
    print(f"Environment Path: {env_path}")
    print("SUCCESS: You're in an isolated environment!")
    print("Safe to install packages without affecting the global system.")
    print()
    print("Package installation path:")
    print(site.getsitepackages()[0])


def main() -> None:
    """Display information about the current Python environment."""
    if in_virtual_environment():
        show_virtual_environment()
    else:
        show_global_environment()


if __name__ == "__main__":
    main()
