from utils import run_git_command


def main():

    # Check whether we are inside a Git repository
    result = run_git_command("git rev-parse --is-inside-work-tree")

    if result.returncode != 0:
        print("❌ This folder is not a Git repository.")
        return

    # Check if there are any changes
    status = run_git_command("git status --porcelain")

    if status.stdout.strip() == "":
        print("✅ Nothing to publish.")
    else:
        print("📌 There are changes ready to publish.")


if __name__ == "__main__":
    main()