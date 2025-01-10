import random

counter=0

def check_once():
    for i in range(1,401):
        if random.random() < 0.005:
            return i
    return 400


def sum(time:int) -> float:
    global counter
    total = 0
    for _i in range(time):
        res = check_once()
        if res == 400:
            counter += 1
        total += res
    return 1 / (total / time)

if __name__ == "__main__":
    res = sum(100000)
    print(counter)
    print(f"{res*100}%")