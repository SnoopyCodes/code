with open("in.txt", "r") as file:
    lines = file.readlines()
cnt = 0
for line in lines:
    arr = list(map(int, line.split()))
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
    if valid:
        cnt += 1
print(cnt)