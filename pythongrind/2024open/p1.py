import sys

input = sys.stdin.readline
print = sys.stdout.write
N, Q = map(int, input().split())
words = input().split()
mm = words[0] == "true" #current expression
right = [False] * N
left = [False] * N
right[N-1] = True 
left[0] = True
ored = (mm and words[1] == "or")
truored = ored
for i in range(1, N, 2):
    if words[i-1] == "and":
        if mm == True:
            if words[i] == "false":
                mm = False
                if ored:
                    ored = False
            if not truored:
                left[i] = True
        #if mm is false and its and then dont care
    else:
        if ored:
            truored = True
        if mm == False:
            if words[i] == "true":
                mm = True
                ored = True
            if not truored:
                left[i] = True
final = mm
mm = words[N-1] == "true"
ored = (mm and words[N-2] == "or")
truored = ored
print(str(final))
for i in range(N - 2, -1, -2):
    if words[i+1] == "and": #it matters, sort of
        if mm == True:
            if words[i] == "false":
                mm = False
                if ored:
                    ored = False
            if not truored:
                right[i] = True
    elif words[i+1] == "or":
        if ored:
            truored = True
        if mm == False:
            if words[i] == "true":
                mm = True
                ored = True
            if not truored:
                right[i] = True
for _ in range(Q):
    pain = input().split()
    l = int(pain[0]) - 1
    r = int(pain[1]) - 1
    if final == (pain[2] == "true"):
        print("Y")
    else:
        if left[l] and right[r]:
            print("Y")
        else:
            print("N")
