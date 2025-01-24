import sys
sys.setrecursionlimit(1000000000)

N = int(input())
pieces = [0] * 3
sushi = list(map(int, input().split()))
for i in range(N):
    pieces[sushi[i] - 1] += 1
def expect(a, b, c):
    if a < 0 or b < 0 or c < 0:
        return -1
    if a == 0 and b == 0 and c == 0:
        return 0
    res = a / N * expect(a-1, b, c)
    res += b / N * expect(a+1, b-1, c)
    res += c / N * expect(a, b+1, c-1)
    res += 1
    res *= N / (a + b + c)
    return res
print(expect(pieces[0], pieces[1], pieces[2]))