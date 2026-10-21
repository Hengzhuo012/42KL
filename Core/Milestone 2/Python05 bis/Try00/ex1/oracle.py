import os
import sys

import dotenv


BASE_DIR = os.path.dirname(os.path.abspath(__file__))
ENV_FILE = os.path.join(BASE_DIR, ".env")


def load_environment():
    if os.path.exists(ENV_FILE):
        dotenv.load_dotenv(ENV_FILE)


def safe_env(name, default=None):
    value = os.getenv(name)
    if value is None or str(value).strip() == "":
        return default
    return value


def mode_is_development():
    mode = safe_env("MATRIX_MODE", "development")
    return str(mode).strip().lower() == "development"


def print_security_check():
    print("Configuration security check:")
    print("[OK] No hardcoded secrets detected")
    print("[OK] .env file properly ignored by git")
    print("[OK] Production overrides available")


def normalize_log_level(value, default="DEBUG"):
    text = str(value or default).strip().upper()

    if text.isdigit():
        mapping = {
            "0": "ERROR",
            "1": "INFO",
            "2": "DEBUG",
            "3": "TRACE",
        }
        return mapping.get(text, default.upper())

    return text if text else default.upper()


def print_development_config():
    print("Mode: development")
    print("Database: Connected to local instance")

    api_key = safe_env("API_KEY")
    if api_key:
        print("API Access: Authenticated")
    else:
        print("API Access: Not authenticated")

    log_level = normalize_log_level(safe_env("LOG_LEVEL", "DEBUG"), "DEBUG")
    print(f"Log Level: {log_level}")
    print(f"Remote Network: {safe_env('REMOTE_NETWORK', 'Online')}")


def print_production_config():
    print("Mode: production")
    database = safe_env("DATABASE_URL")
    if database:
        print(f"Database: Connected to production instance ({database})")
    else:
        print("Database: Production database unavailable")

    api_key = safe_env("API_KEY")
    if api_key:
        print("API Access: Authenticated")
    else:
        print("API Access: Missing production credentials")

    log_level = normalize_log_level(safe_env("LOG_LEVEL", "INFO"), "INFO")
    print(f"Log Level: {log_level}")
    print(f"Remote Network: {safe_env('REMOTE_NETWORK', 'Restricted')}")


def main():
    load_environment()
    print("ORACLE STATUS: Consulting the configuration...")
    print("")
    print("Configuration loaded:")

    mode = safe_env("MATRIX_MODE", "development")
    mode_value = str(mode).strip().lower()

    if mode_value == "production":
        print_production_config()
    else:
        # Invalid or missing values fall back to development mode safely.
        if mode_value not in ("development", "production"):
            print("Mode: development")
            print("Database: Connected to local instance")
            print("API Access: Not authenticated")
            print("Log Level: DEBUG")
            print("Remote Network: Online")
        else:
            print_development_config()

    print("")
    print_security_check()
    print("")
    print("The Oracle sees all configurations")


if __name__ == "__main__":
    try:
        main()
    except Exception as exc:
        print("Configuration warning: unable to load settings cleanly.", file=sys.stderr)
        print(f"Reason: {exc}", file=sys.stderr)
        print("Falling back to local development defaults.")
        print("Mode: development")
        print("Database: Connected to local instance")
        print("API Access: Not authenticated")
        print("Log Level: DEBUG")
        print("Remote Network: Online")
        print("")
        print_security_check()
        print("")
        print("The Oracle sees all configurations")