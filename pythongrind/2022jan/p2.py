import sys

input = sys.stdin.readline
def beats(win, lose):
    lw = 0
    ww = 0
    for x in lose:
        for y in win:
            if x > y:
                lw += 1
            elif y > x:
                ww += 1
    return ww > lw

def solve():
    #quite clearly we just spam!
    #i dont really care about anything just spam
    A = list(map(int, input().split()))
    B = A[4:8]
    A = A[0:4]
    if not beats(A, B):
        C = A
        A = B
        B = C
    for i in range(1, 11):
        for j in range(i, 11):
            for k in range(j, 11):
                for l in range(k, 11):
                    C = [i, j, k, l]
                    if beats(B, C) and beats(C, A):
                        print("yes")
                        return
    print("no")
T = int(input())
for _ in range(T): solve()
