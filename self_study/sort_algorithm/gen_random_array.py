import random

intlist = [i for i in range(100)]
random.shuffle(intlist)

print(f"{{{', '.join(map(str, intlist))}}}")
