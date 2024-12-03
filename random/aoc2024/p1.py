import os
os.chdir("C:\\Users\\benja\\VSC\\code\\random\\aoc2024")
with open("in.txt", "r") as file:
    lines = file.readlines()
L = []
R = []
for line in lines:
    x, y = map(int, line.split())
    L += [x]
    R += [y]
L.sort()
R.sort()
sum = 0
for x, y in zip(L, R):
    sum += abs(x - y)
print(sum)