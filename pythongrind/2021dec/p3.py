import sys

input = sys.stdin.readline
print = sys.stdout.write
grid = list()
N = 0
K = 0
def solve():
    global N, K
    N, K = map(int, int, input().split())
    global grid
    for _ in range(N):
        list.append(input())
    print(trav(0, 0, 0) + "\n")

T = int(input())
for _ in range(T):
    solve()
