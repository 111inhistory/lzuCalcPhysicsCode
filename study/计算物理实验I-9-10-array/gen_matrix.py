import os
import sys
import random

if __name__ == '__main__':
    if len(sys.argv) == 4:
        path = sys.argv[1]
        if not os.path.exists(path):
            print('Path does not exist, Please enter a valid path')
            exit(1)
        m = sys.argv[2]
        n = sys.argv[3]
    else:
        path = input("Path:")
        if not os.path.exists(path):
            print('Path does not exist, Please enter a valid path')
            exit(1)
        m, n = map(int, input().split(" "))
    string = [0] * (m*n)
    for i in range(n*m):
        string[i] = random.randint(0,100)
    with open(path, "a") as f:
        f.write("\n".join(string))