N = int(input())
props = [[[None] for i in range(0)] for j in range((N))]
for i in range(N):
    x = input().split()
    K = int(x[1])
    for j in range(K):
        props[i] = x[2:]
# choose a winner
# iterate over the properties of the winner that have the most
def help(win):
    global props
    return [sum(1 if props[win][i] in props[j] else 0) for i in range(len(props[win]))]
for win in range(N):
    K = len(props[win])
    vis = [False] * K
    # OK
    