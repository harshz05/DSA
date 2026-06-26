from config import PROBLEMS_DIR
from templates import generate_cpp_template
from utils import create_problem_file


def main():
    number = int(input("Problem Number : "))
    name = input("Problem Name   : ").strip()

    filename = f"{number:04d} - {name}.cpp"

    content = generate_cpp_template(number, name)

    create_problem_file(PROBLEMS_DIR / filename, content)

    print(f"\n✅ Created:\n{PROBLEMS_DIR / filename}")


if __name__ == "__main__":
    main()