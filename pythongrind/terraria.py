import sys

"""
Graph of N vertices, M edges, Q queries.
Each query toggles a node on and off (guaranteed to state change). Check if the component is planar.
"""

rd, rn = lambda: list(map(int, sys.stdin.readline().split())), range

for _ in range(rd()[0]):
    N, M, Q = rd()
    G = [[] for _ in rn(N)]
    E = []
    for _ in rn(M):
        u, v = [w - 1 for w in rd()]
        E.append((u, v))
        G[u].append(v)
        G[v].append(u)
    exist = [-1 for _ in rn(N)]
    alive = [[] for _ in rn(N)]

    for i, u in enumerate(rd()):
        if ~exist[u]:
            alive[u].append(exist[u], i) # it existed from exist[u] to i.
            exist[u] = -1
        else:
            exist[u] = i
    # one way is to toggle 1 for a really long time, and connect 1 with everything else.
    # e.g. toggle 1 100k times, and connect 1 to everything. Then everything has to accept 1.
    # one way to fix this... bitsets?

