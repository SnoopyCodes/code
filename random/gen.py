import os, sys, random

N = 21
g = []
for i in range(21):
    g.append(input())

ans = 0
for i in range(N - 4):
    for j in range(N - 4):
        cur = 0
        for k in range(i, i + 4):
            for l in range(j, j + 4):
                if g[k][l] == '1':
                    cur += 1
        ans = max(ans, cur)
print(ans)