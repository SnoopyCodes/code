for _ in range(int(input())):
    N, M, R = map(int, input().split())
    stock = [] # ratio, days, cost
    BIG = (int) (1e18)
    min_cost = [BIG] * (R + 1)
    for i in range(M):
        info = input().split()
        a, b, c = map(int, info[1:])
        for z in range(c):
            stock.append((a / b, a, b))
            for d in range(R - b, -1, -1):
                min_cost[d + b] = min(min_cost[d + b], min_cost[d] + a)
    stock.sort(reverse=1)
    """
    binary search on # of rounds we can survive
    """