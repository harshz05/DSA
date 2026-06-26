from pathlib import Path


def create_problem_file(path: Path, content: str):

    if path.exists():
        raise FileExistsError("Problem already exists.")

    path.write_text(content, encoding="utf-8")