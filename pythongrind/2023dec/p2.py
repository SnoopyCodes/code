import sys

input = sys.stdin.readline

N = int(input())
string = input()
#okay so it is known that in around N / 2 days it can infect everybody
#why is it at night ...
#okay anyways
#it's always *optimal* to assume that the infection did NOT start from some cow on the side
#this way it "covers" a larger area
#unless of course the area covered is even, in which case we have 2 at the center
#basically the idea is that if different groups have different sizes where they aren't in the middle
#then we just default to total number of cows?
#for any group we can do # of infected, and if even then infected / 2
#if a group is on the side it has up to gropu length possibilities
#what if we enumerate each section into a group
#then we have to say for every group if it can do something in x days, where we want x maximized
#__xxxx__
#yo what even is the point of though
#like literally help
#_x_ 1 day
#__x__ 2 days
#___x___3 days
#so we want the min max time it takes for each one which is group / 2
#then we need to find how to 
size = 0
parts = []
end = True
best = N
for i in range(N):
    if string[i] == '0':
        if size != 0:
            if end:
                best = size-1
            else:
                best = min(best, (size-1) // 2) #this definitely gives number of days
            parts.append(size)
            size = 0
        if end: end = False
    else:
        size += 1
if size > 0:
    best = min(best, size-1)
    parts.append(size)
total = 0
for part in parts:
    if part % (1 + 2 * best) == 0:
        total += part // (1 + 2 * best)
    else:
        total += 1 + part //(1 + 2 * best)
print(total)