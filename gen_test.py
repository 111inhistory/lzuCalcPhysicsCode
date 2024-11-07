import os
import sys

def gen_test(path, function_name):
    with open(path, "a") as f:
        main_func = r"""

int main() {
    char s[64];
    scanf("%s", s);
"""
        for i in range(len(function_name)):
            if i == 0:
                main_func += f"    if (strcmp(s, \"{function_name[0]}\") == 0) {{\n        {function_name[0]}();\n    }}"
            else:
                main_func += f" else if (strcmp(s, \"{function_name[0]}\") == 0) {{\n        {function_name[i]}();\n    }}"
        main_func += f" else {{\n        printf(\"No test found\\n\");\n    }}\n    return 0;\n}}"
        f.write(main_func)



if __name__ == '__main__':
    if len(sys.argv) > 1:
        path = sys.argv[1]
        if not os.path.exists(path):
            print('Path does not exist, Please enter a valid path')
            exit(1)
        function_name = sys.argv[2:]
    else:
        path = input("Path:")
        if not os.path.exists(path):
            print('Path does not exist, Please enter a valid path')
            exit(1)
        function_name = []
        t = input()
        while t != '':
            function_name.append(t)
            t = input()
    gen_test(path, function_name)