import sys

input = sys.stdin.readline
def solve():
    N = int(input())
    log = list(map(int, input().split()))
    #make them all equal?
    #we need to figure out what to select based off
    #first its guaranteed for N - 1
    #again i think we could possibly binary search on this
    #consider keeping the max
    #we should definitely try keeping the max
    #this can be done easily in O(N^2) if we find the next smallest sum
    #then add stuff together
    #but without binary search!
    #wait we can iterate through a itself..idk if that helps at all though, just means no ll
    #lets impl simple solution first
    #wait as stuff decreases i dont think our runtime decreases
    #how to implement linked list in here :skull:
    #wait this is tricky
    #well we have to iterate through the array in some way
    #how?
    #its p1 it cant be too hard..
    #if we like iterate over the blocks of stuff isnt that good enough
    #ok bruh this is annoying
    #i really need to stop looking at solutions
    #i probably need tio implement #2
    #first do this
    #wait isnt this just brute force
    #...bruh i shouldve just
    #okay whatever
    total = 0
    mx = 0
    for sleeps in log:
        total += sleeps
        mx = max(mx, sleeps)
    for size in range(mx, total+1):
        if size == 0: 
            print(0)
            return
        if total % size != 0: continue
        cur = 0
        period = 0
        cnt = 0
        while period < N:
            cur = 0
            valid = True
            while period < N and cur < size:
                cnt += 1
                cur += log[period]
                period += 1
            if cur != size:
                valid = False
                break
            cnt -= 1
        if valid:
            print(cnt)
            return

    
T = int(input())
for _ in range(T):
    solve()