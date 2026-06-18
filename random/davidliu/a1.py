import sys
md, rd, rn = 10**9 + 7, lambda: list(map(int, sys.stdin.readline().split())), range

for _ in rn(rd()[0]):
    N = rd()[0]
    s = sum(rd()[0] for _ in rn(N)) % 24
    act = s % 12
    if act == 0:
        act = 12
    append = "pm" if s >= 12 else "am"
    print(str(act) + append)
