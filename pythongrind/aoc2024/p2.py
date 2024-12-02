import os
os.chdir("C:\\Users\\benja\\VSC\\code\\pythongrind\\aoc2024")
with open("in.txt", "r") as file:
    lines = file.readlines()
L = []
d = {}
for line in lines:
    x, y = map(int, line.split())
    L += [x]
    if y in d:
        d[y] += 1
    else:
        d[y] = 1
sum = 0
for x in L:
    if x in d:
        sum += x * d[x]
print(sum)