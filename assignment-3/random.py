import random

n = 100

fp = open("random_" + str(n) + ".txt", "w")
fp.write(str(n) + " ")

for i in range(n):
    num = random.randint(-n, n)
    fp.write(str(num) + " ")

fp.close()

print(f"Generated random_{n}.txt with {n} elements (including negative numbers)")
