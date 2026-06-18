import sys
md, rd, rn = 10**9 + 7, lambda: list(map(str, sys.stdin.readline().split())), range
from collections import defaultdict as dd
# for typing
from typing import TypeVar
T = TypeVar("T")
"""
PRECONDITIONS:
    THERE ARE NO EDGES INTO ROOT
    THERE ARE NO PARALLEL EDGES
this is because this is all to be precomputed.
"""
def edmond(E: set[tuple[T,T,int]], root: T) -> tuple[int, set[tuple[T, T, int]]]:
    """
    steps:
        1. remove unnecessary edges
        2. find a cycle within the graph
        3. remake edges
    """
    if not len(E):
        return 0
    G = dd(list[T])
    min_e_into = dd(lambda: -1) # index of the edge that is least into node u
    for i, u, v, w in enumerate(E):
        G[u].append(v, w)
        if min_e_into[v] == -1 or w < E[min_e_into[v]][2]:
            min_e_into[v] = i
    state = dd(int)

    def dfs(u: T) -> int:
        state[u] = 1
        for v in G[u]:
            if state[v] == 1:
                return v
            elif not state[v]:
                out = dfs(v)
                if ~out:
                    if u == out:
                        return -1 # we are at the end of the cycle.
                    return out
        state[u] = 2
        return -1
    dfs(root)
    # if there is no cycle, we have an answer.
    # we now have a cycle denoted by the nodes that have state 1.
    nxt = []
    rep = None
    for u, s in state.items():
        if s == 1:
            rep = u
            break
    if not rep:
        return 0
    
    for u, v, w in E:
        if state[u] == 1 and state[v] == 1:
            continue
        if state[v] == 1:
            nxt.append(u, v, w - E[min_e_into[v]][2])
        else:
            nxt.append(u, v, w)
    amt, A = edmond(nxt, root) # amt, arborescence
    

        


