import sys

input = sys.stdin.readline
print = sys.stdout.write

N = int(input())
prefs = list(map(int, input().split()))
temps = list(map(int, input().split())) #diff input!
for i in range(N):
    temps[i] = prefs[i] - temps[i] # # of increases to get there
steps = 0
for i in range(N):
    if (temps[i] == 0):
        continue
    while i < N and temps[i] != 0:
        incs = 100001
        original = i
        inc = 1
        if temps[i] < 0: inc = -1
        while i < N:
            if temps[i] == 0: break
            if (temps[i] < 0) != (temps[original] < 0): break
            incs = min(incs, inc * temps[i])
            i += 1
        prev = 0
        for j in range(original, i):
            temps[j] -= incs * inc
        i = original
        steps += abs(incs)
print(str(steps))