import random

def gen(a:list[int]):
    if len(a) == 0:
        return str(random.randint(0, 10))
    else:
        return "{" + ", ".join([gen(a[1:]) for i in range(a[0])]) + "}"

print(gen([2,2,2,2,]))