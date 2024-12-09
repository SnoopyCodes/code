import os
os.chdir("C:\\Users\\benja\\VSC\\code\\atc\\random")
N = 200000 - 1
file = open("hack.txt", "w")
file.write(str(N) +"\n")
for i in range(1, N + 1):
    if i == 2:
        continue
    file.write(str(i) + " 2 1\n")
file.write(str(N + 1) + "\n")
for i in range(N):
    file.write("1 1 1\n")
file.write("2 1 1")
file.close()