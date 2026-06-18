import sys
md, rd, rn = 10**9 + 7, lambda: list(map(str, sys.stdin.readline().split())), range

for _ in rn(int(rd()[0])):
    s = rd()[0]
    N = len(s)
    sets = [set(rd()[1:]) for _ in rn(N)]
    ok = 1
    # ok man its just flows