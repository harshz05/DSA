from datetime import date


def generate_cpp_template(number, name):
    return f"""/*
=========================================
LeetCode {number} - {name}
=========================================

Difficulty :

Pattern    :

Time        :

Space       :

Date Solved : {date.today()}

=========================================
*/

class Solution {{
public:

}};
"""