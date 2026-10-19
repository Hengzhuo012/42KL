import os


class ModeError(Exception):
    pass


if __name__ == "__main__":
    try:
        print("ORACLE STATUS: Consulting the configuration...")
        print("")
        print("Configuration loaded:")
        if os.getenv("MATRIX_MODE") == "development":
            
        elif os.getenv("MATRIX_MODE") == "production":

        else:
            raise ModeError()
    except ModeError as e:
        print("INVALID MATRIX MODE")