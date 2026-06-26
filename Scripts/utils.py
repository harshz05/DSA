from pathlib import Path
import subprocess


def create_problem_file(path: Path, content: str):

    if path.exists():
        raise FileExistsError("Problem already exists.")

    path.write_text(content, encoding="utf-8")


def run_git_command(command):
    result = subprocess.run(
        command,
        capture_output=True,
        text=True,
        shell=True
    )

    return result