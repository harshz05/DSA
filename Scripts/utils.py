from pathlib import Path


def create_problem_file(path: Path, content: str):

    if path.exists():
        raise FileExistsError("Problem already exists.")

    path.write_text(content, encoding="utf-8")

    import subprocess


def run_git_command(command):
    result = subprocess.run(
        command,
        capture_output=True,
        text=True,
        shell=True
    )

    return result