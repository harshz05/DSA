from pathlib import Path
import subprocess


def create_problem_file(path: Path, content: str):

    if path.exists():
        raise FileExistsError("Problem already exists.")

    path.write_text(content, encoding="utf-8")


def run_git_command(command):
    return subprocess.run(
        command,
        capture_output=True,
        text=True,
        shell=True
    )


def is_git_repository():
    result = run_git_command("git rev-parse --is-inside-work-tree")
    return result.returncode == 0


def get_git_status():
    result = run_git_command("git status --porcelain")
    return result.stdout.strip()


def git_add():
    return run_git_command("git add .")


def git_commit(message):
    return run_git_command(f'git commit -m "{message}"')


def git_push():
    return run_git_command("git push")