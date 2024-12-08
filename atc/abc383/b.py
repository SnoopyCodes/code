H, W, D = map(int, input().split())
office = [input() for _ in range(H)]
ans = 0
for i1 in range(H):
    for j1 in range(W):
        for i2 in range(H):
            for j2 in range(W):
                if i1 == i2 and j1 == j2:
                    continue
                if office[i1][j1] == '#' or office[i2][j2] == '#':
                    continue
                cnt = 0
                for i in range(H):
                    for j in range(W):
                        if office[i][j] == '#':
                            continue
                        if abs(i - i1) + abs(j - j1) <= D or abs(i - i2) + abs(j - j2) <= D:
                            cnt += 1
                ans = max(ans, cnt)
print(ans)