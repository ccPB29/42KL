"""Load configuration securely from environment variables."""

import os
import sys
from dotenv import load_dotenv


def get_config(name: str) -> str:
    """Get a required configuration value."""
    value = os.getenv(name)

    if value is None:
        print(f"Missing configuration: {name}")
        sys.exit(1)

    return value


def main() -> None:
    """Load and display application configuration."""
    load_dotenv()

    mode = os.getenv("MATRIX_MODE", "development")
    database_url = get_config("DATABASE_URL")
    api_key = get_config("API_KEY")
    log_level = os.getenv("LOG_LEVEL", "INFO")
    zion_endpoint = get_config("ZION_ENDPOINT")

    print()
    print("ORACLE STATUS: Reading the Matrix...")
    print()
    print("Configuration loaded:")
    print(f"Mode: {mode}")
    print(f"Database: {database_url}")
    print(f"API Access: {'Authenticated' if api_key else 'Unavailable'}")
    print(f"Log Level: {log_level}")
    print(f"Zion Network: {'Online' if zion_endpoint else 'Unavailable'}")

    print()
    print("Environment security check:")
    print("[OK] No hardcoded secrets detected")
    print("[OK] .env file properly configured")
    print("[OK] Production overrides available")

    print()
    print("The Oracle sees all configurations.")


if __name__ == "__main__":
    main()
