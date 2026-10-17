import importlib


REAGENTS = (
    ("pandas", "Data manipulation ready"),
    ("numpy", "Numerical computation ready"),
)


def main():
    missing = []

    print("REAGENT STATUS: Loading reagents...")
    print()
    print("Checking dependencies:")

    for reagent, description in REAGENTS:
        try:
            module = importlib.import_module(reagent)
        except ImportError:
            print(f"[MISSING] {reagent} - install it using pip or Poetry")
            missing.append(reagent)
        else:
            print(f"[OK] {reagent} ({module.__version__}) - {description}")

    print()
    print("pip vs Poetry:")
    print("requirements.txt declares what to install; "
          "pip resolves it at install time.")
    print("pyproject.toml declares the same constraints; "
          "and Poetry pins the resolved versions in poetry.lock "
          "so every install is identical.")

    if missing:
        print()
        print("Missing reagents. Install them with pip:")
        print("pip install -r ex0/requirements.txt")
        print("Or with Poetry from the project root:")
        print("cd ex0")
        print("poetry install")
        print("poetry run python loading.py")
    else:
        print()
        print("All reagents present and accounted for.")


if __name__ == "__main__":
    main()
