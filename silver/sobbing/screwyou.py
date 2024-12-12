def to_reduced_list(s):
    """Compress runs of equal chars in a string s
    >>> to_reduced_list('2211')
    ['2', '1']
    """
    l = []
    for c in s:
        if len(l) > 0 and l[-1] == c:
            continue
        l.append(c)
    return l


def solve():
    N, P = map(int, input().split())
    assert P == 1
    tubes = [to_reduced_list(input()) for _ in range(2)]
    tubes.append([])
    ans = len(tubes[0]) + len(tubes[1]) - 2
    # ^ num chars after simplifying, if tubes[0] and tubes[1] start with different chars and we choose the better of Q and Q'
    if tubes[0][0] == tubes[1][0]:
        ans += 1
    if ans > 1:  # require extra pour into beaker
        ans += 1
    print(ans)


T = int(input())
for _ in range(T):
    solve()