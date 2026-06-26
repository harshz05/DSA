from pathlib import Path

problem_number = int(input("Problem Number : "))
problem_name = input("Problem Name   : ").strip()

filename = f"{problem_number:04d} - {problem_name}.cpp"

repo_root = Path(__file__).resolve().parent.parent
problems_folder = repo_root / "Problems"

problems_folder.mkdir(exist_ok=True)

file_path = problems_folder / filename

if file_path.exists():
    print("\n❌ This problem already exists.")
    exit()

template = f"""/*
=========================================
LeetCode {problem_number} - {problem_name}
=========================================

Difficulty :

Pattern    :

Time        :

Space       :

Date Solved :

=========================================
*/

class Solution {{
public:

}};
"""

with open(file_path, "w", encoding="utf-8") as f:
    f.write(template)

print(f"\n✅ Created:\n{file_path}")