N, K = map(int, input().split())
MOD = 998244353
S = input()
q = [i for i in range(N) if S[i] == '?']
def process(s):
    cnt = 0
    inv = 0
    for i in range(N):
        if s[i] == '1':
            cnt += 1
        else:
            inv += cnt
    cnt_zero = N - cnt
    res = inv * K
    # for each "1" there are ((K - 1) * cnt_zero), then in the next ((K - 2) * cnt_zero)
    res += (K * (K - 1) // 2) * cnt_zero * cnt
    return res
q.append(-1)
ans = float('inf')
for i in range(len(q)):
    s = ""
    for j in range(N):
        if S[j] == '?':
            if j <= q[i]:
                s += '0'
            else:
                s += '1'
        else:
            s += S[j]
    ans = min(ans, process(s))
print(ans % MOD)