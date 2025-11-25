with open("in.txt", "w") as f:
    f.write("1\n")
    f.write("500 500\n")
    s = "1" * 500
    for i in range(500):
        f.write(s)