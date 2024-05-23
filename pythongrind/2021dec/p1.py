import sys
input = sys.stdin.readline
print = sys.stdout.write

N = int(input())
arr = str(input())
'''
try making a method to iterate through the string
consider going through a string
so we can keep the last occurrence of G
basically see how many pictures we have?
wait how about we try just going both ways for each cow
then multiply stuff
this should tle on last but it should be n^2 otherwise
'''
toss = 0
for i in range(N):
    lhs = 0
    rhs = 0
    for l in range(i-1, -1, -1):
        if arr[l] == arr[i]: break
        lhs += 1
    for r in range(i+1, N):
        if arr[r] == arr[i]: break
        rhs += 1
    #what do we want to add?
    #isnt it multiply together then add lengths?
    #but we need to account for length < 2
    toss += lhs * rhs
    toss += max(0, lhs-1)
    toss += max(0, rhs-1)

print(str(toss))
