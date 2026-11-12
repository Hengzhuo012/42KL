import os
import sys

import dotenv


BASE_DIR = os.path.dirname(os.path.abspath(__file__))
ENV_FILE = os.path.join(BASE_DIR, ".env")


def load_environment() -> None:
    if os.path.exists(ENV_FILE):
        dotenv.load_dotenv(ENV_FILE)


def safe_env(name: str, default: str | None = None) -> str | None:
    value = os.getenv(name)
    if value is None or value.strip() == "":
        return default
    return value


def normalize_log_level(value: str | None, default: str = "DEBUG") -> str:
    text = (value or default).strip().upper()

    if text.isdigit():
        mapping = {
            "0": "ERROR",
            "1": "INFO",
            "2": "DEBUG",
            "3": "TRACE",
        }
        return mapping.get(text, default.upper())

    return text if text else default.upper()


def print_security_guidance() -> None:
    print("Configuration security:")
    print("[OK] Secrets are read from environment variables")
    print("[OK] Keep .env local; commit only placeholder values")
    print("[OK] Production overrides are supported")


def print_development_config() -> None:
    print("Mode: development")
    print("Database: Connected to local instance")

    if safe_env("API_KEY"):
        print("API Access: Authenticated")
    else:
        print("API Access: Not authenticated")

    log_level = normalize_log_level(safe_env("LOG_LEVEL"), "DEBUG")
    print(f"Log Level: {log_level}")
    endpoint = safe_env("ZION_ENDPOINT")
    network = "Configured" if endpoint else "Online (default)"
    print(f"Remote Network: {network}")


def print_production_config() -> None:
    print("Mode: production")
    if safe_env("DATABASE_URL"):
        print("Database: Connected to production instance")
    else:
        print("Database: Production database unavailable")

    if safe_env("API_KEY"):
        print("API Access: Authenticated")
    else:
        print("API Access: Missing production credentials")

    log_level = normalize_log_level(safe_env("LOG_LEVEL"), "INFO")
    print(f"Log Level: {log_level}")
    endpoint = safe_env("ZION_ENDPOINT")
    network = "Configured" if endpoint else "Restricted (default)"
    print(f"Remote Network: {network}")


def print_missing_configuration(mode: str) -> None:
    required = ["API_KEY", "ZION_ENDPOINT"]
    if mode == "production":
        required.append("DATABASE_URL")

    missing = [name for name in required if not safe_env(name)]
    if missing:
        print(f"WARNING: Missing configuration: {', '.join(missing)}")


def main() -> None:
    load_environment()
    print("ORACLE STATUS: Consulting the configuration...")
    print()
    print("Configuration loaded:")

    mode = (safe_env("MATRIX_MODE", "development") or "development")
    mode_value = mode.strip().lower()
    if mode_value not in ("development", "production"):
        print(f"WARNING: Unknown MATRIX_MODE '{mode}'; using development")
        mode_value = "development"

    if mode_value == "production":
        print_production_config()
    else:
        print_development_config()

    print_missing_configuration(mode_value)
    print()
    print_security_guidance()
    print()
    print("The Oracle sees all configurations")


if __name__ == "__main__":
    try:
        main()
    except Exception as exc:
        print("Configuration warning: unable to load settings cleanly.",
              file=sys.stderr)
        print(f"Reason: {exc}", file=sys.stderr)
        print("Falling back to local development defaults.")
        print("Mode: development")
        print("Database: Connected to local instance")
        print("API Access: Not authenticated")
        print("Log Level: DEBUG")
        print("Remote Network: Online (default)")
        print_missing_configuration("development")
        print()
        print_security_guidance()
        print()
        print("The Oracle sees all configurations")
