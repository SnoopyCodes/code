import os
os.chdir("C:\\Users\\benja\\VSC\\code\\random\\aoc2024")
with open("in.txt", "r") as file:
    lines = file.readlines()
def check(arr):
    valid = True
    help = 0
    for i in range(len(arr) - 1):
        diff = arr[i+1] - arr[i]
        if diff * help < 0:
            valid = False
        help = diff
        diff = abs(diff)
        if diff < 1 or diff > 3:
            valid = False
    return valid
cnt = 0
for line in lines:
    valid = False
    arr = list(map(int, line.split()))
    for i in range(len(arr)):
        tmp = arr[0:i] + arr[i+1:]
        if check(tmp):
            valid = True
    if valid:
        cnt += 1
print(cnt)