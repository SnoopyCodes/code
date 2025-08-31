with open("in.txt", "w") as f:
    N = 300000
    f.writelines(str(N) + "\n")
    for i in range(N):
        f.writelines(str(1) + "\n")

    