import sys

input = sys.stdin.readline
def solve():
    N = int(input())
    hunger = list(map(int, input().split()))
    #wait we need the same
    #so if min is on the edges like 100 1 ...
    #not allowed
    # okay i mean i implmeneted naive version
    # but that does based on hunger levels
    #so how do we get it down to O(N)
    #okay we could binary search but ;_; why lets try not to
    #it is easy to naively solve for a single value
    #need to reduce the amount of stuff we are searching for though
    #hmmmmmmmmmm now what
    #when is something definitely impossible?
    #i think we can base it off of N actually
    #basically if we run through N at first
    #then see how many we need to buy for the difference to go down?
    #oh i was right
    #sheesh this is tough
    total = 0
    for i in range(N - 1):
        if hunger[i] < 0: 
            print(-1)
            return
        #make i+1 the same as i
        if (hunger[i+1] < hunger[i]): #in these cases we don't even need to modify hunger
            if i % 2 == 0:
                print(-1)
                return
            else:
                total += (hunger[i] - hunger[i+1]) * (i+1)
        elif hunger[i+1] > hunger[i]:
            total += (hunger[i+1] - hunger[i]) * 2
            if i+2 == N:
                print(-1)
                return
            hunger[i+2] -= hunger[i+1] - hunger[i]
            hunger[i+1] = hunger[i]
    if hunger[N-1] < 0:
        print(-1)
        return
    print(total)



T = int(input())
for _ in range(T): solve()