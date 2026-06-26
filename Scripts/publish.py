from pathlib import Path

from utils import (
    is_git_repository,
    get_git_status,
    git_add,
    git_commit,
    git_push,
)


def generate_commit_message(status):

    for line in status.splitlines():

        filename = line[3:].strip()

        if filename.startswith("Problems/") and filename.endswith(".cpp"):

            problem = Path(filename).stem
            return f"Add {problem}"

    return "Update repository"


def main():

    if not is_git_repository():
        print("❌ Not inside a Git repository.")
        return

    status = get_git_status()

    if status == "":
        print("✅ Nothing to publish.")
        return

    print("\nFiles changed:\n")

    for line in status.splitlines():
        print(" ", line)

    print()

    choice = input("Continue? (Y/N): ").strip().lower()

    if choice != "y":
        print("Cancelled.")
        return

    add_result = git_add()

    if add_result.returncode != 0:
        print("❌ Failed to stage files.")
        print(add_result.stderr)
        return

    print("\n✅ Files staged.\n")

    message = input(
        "Commit message (Press Enter for automatic): "
    ).strip()

    if message == "":
        message = generate_commit_message(status)

    print(f"\nUsing commit message: {message}")

    commit_result = git_commit(message)

    if commit_result.returncode != 0:
        print("\n❌ Commit failed.")
        print(commit_result.stderr)
        return

    print("\n✅ Commit created.")

    push = input("\nPush to GitHub? (Y/N): ").strip().lower()

    if push != "y":
        print("Commit saved locally.")
        return

    push_result = git_push()

    if push_result.returncode != 0:
        print("\n❌ Push failed.")
        print(push_result.stderr)
        return

    print("\n🚀 Successfully published to GitHub!")


if __name__ == "__main__":
    main()