T = int(input())
def solve():
    N = int(input())
    hunger = list(map(int, input().split()))
    ans = 0
    cur = hunger[0] # valid from [0, i - 2]
    for i in range(2, N): #make i - 1 equal to i - 2
        # maintain a current hunger level
        # try to make as many of [0...i] equal as we can
        # try to decrease it down to what we can, otherwise increase the others
        # OK so from the left side
        # if it can't be the same for 
        if hunger[i - 1] < cur and i % 2 == 0:
            print(-1)
            return
        elif hunger[i - 1] < cur:
            ans += (cur - hunger[i - 1]) * (i-1)
            cur = hunger[i - 1]
        elif hunger[i - 1] != cur:
            # decrease this and i
            ans += 2 * (hunger[i - 1] - cur)
            hunger[i] -= hunger[i - 1] - cur
            hunger[i - 1] = cur
    if hunger[-1] < cur and N % 2 == 0:
        print(-1)
        return
    elif hunger[-1] < cur:
        ans += (cur - hunger[-1]) * (N - 1)
    elif hunger[-1] != cur:
        print(-1)
        return
        
    if cur < 0 or min(hunger) < 0:
        print(-1)
        return
    print(ans)
    


for _ in range(T):
    solve()
