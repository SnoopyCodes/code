from collections import deque
N, M = map(int, input().split())
graph = [[] for _ in range(N)]
indeg = [0] * N
for e in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    graph[a].append(b)
    indeg[b] += 1
d = deque()
for i in range(N):
    if indeg[i] == 0:
        d.append(i)
order = []
while not len(d) == 0:
    v = d.popleft()
    order.append(v)
    for adj in graph[v]:
        indeg[adj] -= 1
        if indeg[adj] == 0:
            d.append(adj)
if len(order) != N:
    print("IMPOSSIBLE")
else:
    [print(i+1) for i in order]
