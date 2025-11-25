import sys

il = lambda: list(map(int, sys.stdin.readline().split()))
ii = lambda: int(input())

for _ in range(ii()):
    N, K = il()
    par = [0] + [x - 1 for x in il()]
    depth = [0] * N
    depth_size = [0] * N
    is_leaf = [1] * N
    depth_size[0] = 1
    for i in range(1, N):
        p = par[i]
        depth[i] = depth[p] + 1
        depth_size[depth[i]] += 1
        is_leaf[p] = 0
    min_d = N
    for i in range(N):
        if is_leaf[i]:
            min_d = min(min_d, depth[i])
    dp = [0] * (N + 1)
    dp[0] = 1
    can = 0

    item_cnt = [0] * (N + 1)
    for i in range(min_d + 1):
        item_cnt[depth_size[i]] += 1
    all_items = []
    for i in range(N + 1):
        if not item_cnt[i]: continue
        for b in range(20, -1, -1):
            if (1 << b) - 1 <= item_cnt[i]:
                rem = item_cnt[i] - (1 << b) + 1
                for s in range(b):
                    all_items.append((1 << s) * i)
                if rem:
                    all_items.append(rem * i)
                break
    for x in all_items:
        for j in range(can, -1, -1):
            dp[j + x] |= dp[j]
        can += x
    leeway = N - can
    ans = min_d
    for i in range(N + 1):
            if not dp[i]: continue
            if i <= K and i + leeway >= K or i <= N - K and i + leeway >= N - K:
                ans += 1
                break
    print(ans)