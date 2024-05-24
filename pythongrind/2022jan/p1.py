import sys

input = sys.stdin.readline
def count(char):
    global right

right = []
left = []
grn = [[False, False, False], [False, False, False], [False, False, False]]
mtch = [[False, False, False], [False, False, False], [False, False, False]]
for _ in range(3):
    right.append(input())
for _ in range(3):
    left.append(input())
#find if something exists
#first eliminate all greens; mark everything htat is green green
green = 0
for i in range(3):
    for j in range(3):
        if right[i][j] == left[i][j]:
            grn[i][j] = True
            green += 1
yell = 0
for i in range(3):
    for j in range(3):
        if (grn[i][j]): continue
        col = right[i][j]
        found = False
        for k in range(3):
            for l in range(3):
                if (mtch[k][l] or grn[k][l]): continue
                if (right[i][j] == left[k][l]):
                    yell += 1
                    mtch[k][l] = True
                    found = True
                    break
            if found: break
print(green)
print(yell)

