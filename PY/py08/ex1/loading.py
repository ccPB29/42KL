"""Analyze simulated Matrix data."""

import sys

try:
    import numpy as np
    import pandas as pd
    import matplotlib
    import matplotlib.pyplot as plt
except ImportError as error:
    print(f"Missing dependency: {error}")
    print("pip install -r requirements.txt")
    print("or: poetry install")
    sys.exit(1)


def show_versions() -> None:
    """Show installed package versions."""
    print(
        f"[OK] pandas ({pd.__version__}) - "
        "Data manipulation ready"
    )
    print(
        f"[OK] numpy ({np.__version__}) - "
        "Numerical computation ready"
    )
    print(
        f"[OK] matplotlib ({matplotlib.__version__}) - "
        "Visualization ready"
    )


def main() -> None:
    """Analyze and visualize Matrix data."""
    print()
    print("LOADING STATUS: Loading programs...")
    print()
    print("Checking dependencies:")
    show_versions()

    print()
    print("Analyzing Matrix data...")

    data = np.random.normal(0, 1, 1000)
    frame = pd.DataFrame({"signal": data})

    print(f"Processing {len(frame)} data points...")
    print(f"Min: {frame['signal'].min():.2f}")
    print(f"Max: {frame['signal'].max():.2f}")

    print("Generating visualization...")
    plt.hist(frame["signal"])
    plt.savefig("matrix_analysis.png")
    plt.close()

    print()
    print("Analysis complete!")
    print("Results saved to: matrix_analysis.png")


if __name__ == "__main__":
    main()
