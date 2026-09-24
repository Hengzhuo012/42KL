def secure_archive(file_name: str, mode: str = 'r', text: str = "") \
 -> tuple[bool, str]:
    try:
        with open(file_name, mode) as file_handle:
            if mode == "r":
                return True, file_handle.read()
            elif mode == "w":
                file_handle.write(text)
                return True, "Content successfully written to file"
            else:
                return False, "Invalid mode"
    except OSError as e:
        return False, f"{e}"


def ft_vault_security():
    print("=== Cyber Archives Security ===")
    print("")

    print("Using 'secure_archive' to read from a nonexistent file:")
    print(secure_archive("test.txt"))
    print("")

    print("Using 'secure_archive' to read from an inaccessible file:")
    print(secure_archive("no_perm.txt"))
    print("")

    print("Using 'secure_archive' to read from a regular file:")
    print(secure_archive("ancient_fragment.txt"))
    print("")

    print("Using 'secure_archieve' to write previous content to a new file:")
    print(secure_archive("new_file.txt", "w", "this is a test file.\nhello"))


if __name__ == "__main__":
    ft_vault_security()
