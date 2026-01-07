n = 100

fp = open("descending_" + str(n) + ".txt", "w")
fp.write(str(n) + " ")
for i in range(n, 1, -1):
    fp.write(str(i) + " ")
fp.write(str(1))
fp.close()

print(f"Generated descending_{n}.txt with {n} elements")
