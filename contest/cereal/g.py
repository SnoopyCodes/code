def solve():
    N = int(input())
    stores = list(map(int, input().split()))
    loop = stores + stores + stores
    moves = (N + 1) // 2 
    slide1 = sum(loop[0:moves]) #death
    slide2 = sum(loop[N-(moves-1):N+1])
    ans = min(slide1, slide2)
    for i in range(N, 2 * N):
        slide1 -= loop[i]
        slide1 += loop[i + moves]
        slide2 -= loop[i - moves + 1]
        slide2 += loop[i + 1]
        ans = max(min(slide1, slide2), ans)
    print(ans)
T = int(input())
for _ in range(T):
    solve()