import random
with open("in.txt", "w") as f:
    f.write("1\n")
    f.write("1000 1000\n")
    pref = 'A' * 1000
    names = []
    for i in range(1000):
        name = pref
        for i in range(1000):
            name += chr(random.randint(65, 25 + 65))
        names.append(name)
    for i in range(1000):
        f.write(names[i] + " ")
    f.write("\n")
    for i in range(1000):
        f.write(names[i] + " ")