import sys

input = sys.stdin.readline

N, M = map(int, input().split())
cows = list(map(int, input().split()))
#heights clearly double
#
canes = list(map(int, input().split()))
#direct simulation :)
#hold on wtf
#okay first simulate i guess
initmx = 0
for i in cows:
    initmx = max(initmx, i)
newmx = 0
for cane in canes:
    base = cows[0]
    #we can't iterate through all of the array
    #we can keep a suffix max telling us the max ahead?
    #but i believe that requires updating it?
    #wait just simulate first
    cows[0] = min(cows[0] + cane, cows[0] * 2)
    if base < cane and newmx < initmx:
        for i in range(1, N):
            if cows[i] > base:
                tmp = cows[i]
                cows[i] += min(cows[i] - base, cane - base)
                base = tmp
                if base >= cane:
                    break
    newmx = max(newmx, cows[0])
for cow in cows:
    print(cow)