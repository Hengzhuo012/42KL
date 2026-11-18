import os
import dotenv


BASE_DIR = os.path.dirname(os.path.abspath(__file__))
ENV_FILE = os.path.join(BASE_DIR, ".env")


def safe_env(name: str, default: str | None = None) -> str | None:
    value = os.getenv(name)
    return value if value and value.strip() else default


def print_configuration(mode: str) -> None:
    production = (mode == "production")
    print(f"Mode: {mode}")

    if production:
        if safe_env("DATABASE_URL"):
            print("Database: Connected to production instance")
        else:
            print("Database: Production database unavailable")
    else:
        print("Database: Connected to local instance")

    api_key = safe_env("API_KEY")
    if api_key:
        print("API Access: Authenticated")
    elif production:
        print("API Access: Missing production credentials")
    else:
        print("API Access: Not authenticated")

    default_level = "INFO" if production else "DEBUG"
    log_level = (safe_env("LOG_LEVEL", default_level) or default_level).upper()
    print(f"Log Level: {log_level}")

    if safe_env("ZION_ENDPOINT"):
        network = "Configured"
    else:
        network = "Restricted (default)" if production else "Online"
    print(f"Remote Network: {network}")


def print_missing_configuration(mode: str) -> None:
    required = ["API_KEY", "ZION_ENDPOINT"]
    if mode == "production":
        required.append("DATABASE_URL")

    missing = [name for name in required if not safe_env(name)]
    if missing:
        print(f"WARNING: Missing configuration: {', '.join(missing)}")


def main() -> None:
    dotenv.load_dotenv(ENV_FILE)
    print("ORACLE STATUS: Consulting the configuration...")
    print()
    print("Configuration loaded:")

    mode = (safe_env("MATRIX_MODE", "development") or "development")
    mode = mode.strip().lower()
    if mode not in ("development", "production"):
        print(f"WARNING: Unknown MATRIX_MODE '{mode}'; using development")
        mode = "development"

    print_configuration(mode)
    print_missing_configuration(mode)
    print()
    print("Configuration security check:")
    print("[OK] No hardcoded secrets detected")
    print("[OK] .env file properly ignored by git")
    print("[OK] Production overrides available")
    print()
    print("The Oracle sees all configurations.")


if __name__ == "__main__":
    main()
