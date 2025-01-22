N = int(input())
pieces = [0] * 3
sushi = list(map(int, input().split()))
for i in range(N):
    pieces[sushi[i]-1] += 1
def expect(one, two, three):
    none = N - one + two + three
    # res = 
    
print(expect(sushi[0], sushi[1], sushi[2]))
