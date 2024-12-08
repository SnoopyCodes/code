from collections import deque

H, W, D = map(int, input().split())
office = [input() for _ in range(H)]
check = [[-1 for i in range(W)] for j in range(H)]

d = deque()
for i in range(H):
    for j in range(W):
        if office[i][j] == 'H':
            check[i][j] = 0
            d.append((i, j))

dx = [0, 0, 1, -1]
dy = [-1, 1, 0, 0]

while (d):
    r, c = d.popleft()
    for i in range(4):
        nr = r + dx[i]
        nc = c + dy[i]
        if nr < 0 or nc < 0 or nr == H or nc == W or office[nr][nc] == '#' or check[nr][nc] != -1:
            continue
        check[nr][nc] = check[r][c] + 1
        if check[nr][nc] != D:
            d.append((nr, nc))

sum = 0
for i in range(H):
    for j in range(W):
        #why was this giving error?
        #
        if 0 <= check[i][j] <= D:
            sum += 1
print(sum)