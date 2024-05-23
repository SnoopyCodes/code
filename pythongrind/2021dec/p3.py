import sys

input = sys.stdin.readline
print = sys.stdout.write
grid = list()
N = 0
K = 0
def trav(r, c, turns, dir): #dir == 0 
    if grid[r][c] == 'H': return 0
    if r == N - 1 and c == N - 1: return 1
    if (turns == K):
        if dir == 0:
            if c + 1 == N or grid[r][c+1] == 'H': return 0
            return trav(r, c + 1, turns, dir)
        else:
            if r + 1 == N or grid[r+1][c] == 'H': return 0
            return trav(r + 1, c, turns, dir)
    if dir == 0:
        ans = 0
        if c + 1 != N and grid[r][c+1] != 'H':
            ans += trav(r, c + 1, turns, dir)
        if r + 1 != N and grid[r+1][c] != 'H':
            ans += trav(r + 1, c, turns + 1, 1)
        return ans
    else:
        ans = 0
        if c + 1 != N and grid[r][c+1] != 'H':
            ans += trav(r, c + 1, turns + 1, 0)
        if r + 1 != N and grid[r+1][c] != 'H':
            ans += trav(r + 1, c, turns, dir)
        return ans


def solve():
    global N, K, grid
    N, K = map(int, input().split())
    grid = []
    for _ in range(N):
        grid.append(input())
    print(str(trav(0,1,0,0) + trav(1, 0, 0, 1)) + "\n")

T = int(input())
for _ in range(T):
    solve()
