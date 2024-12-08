N = int(input())
amt = 0
lt = 0
for i in range(N):
    t, v = map(int, input().split())
    if lt != 0:
        amt = max(amt - (t - lt), 0)
    amt += v
    lt = t
print(amt)