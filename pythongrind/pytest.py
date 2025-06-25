import sys
input_line, input_ind = [], -1
def istr():
    global input_ind, input_line
    input_ind += 1
    if input_ind == len(input_line):
        input_line, input_ind = sys.stdin.readline().split(), 0
    return input_line[input_ind]
def iint(): return int(istr())

N, Q = iint(), iint()
from heapq import heappop, heappush

coord = [0] * N
heap = []

def dist(a, b): return abs(a[0] - b[0]) + abs(a[1] - b[1])

dsu = [i for i in range(N)]
size = [1] * N
def find(u):
    global dsu
    if dsu[u] != u: dsu[u] = find(dsu[u])
    return dsu[u]
def union(u, v):
    global dsu, size
    u, v = find(u), find(v)
    if u is v: return False
    if size[u] < size[v]: u, v = v, u
    size[u] += size[v]
    dsu[v] = u
    return True
def add():
    global dsu, size
    dsu.append(N)
    size.append(1)

for i in range(N):
    coord[i] = (iint(), iint())
    for j in range(i):
        heappush(heap, (dist(coord[i], coord[j]), i, j))
for q in range(Q):
    t = iint()
    if t == 1:
        coord.append((iint(), iint()))
        for i in range(N):
            heappush(heap, (dist(coord[i], coord[N]), i, N))
        add()
        N += 1
    elif t == 2:
        while heap and find(heap[0][1]) == find(heap[0][2]):
            heappop(heap)
        
        min_dist = heap[0][0] if heap else -1
        while heap and heap[0][0] == min_dist:
            (w, u, v) = heappop(heap)
            union(u, v)
        print(min_dist)
    else:
        u, v = iint() - 1, iint() - 1
        [print("Yes") if find(u) == find(v) else print("No")]
