import random
with open("in.txt", "w") as file:
    N = 200000
    file.write(str(N) + "\n")
    for i in range(N):
        file.write(str(random.randint(1,N)) + "\n")
