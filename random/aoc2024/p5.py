import os
os.chdir("C:\\Users\\benja\\VSC\\code\\random\\aoc2024")
with open("in.txt", "r") as file:
    lines = file.readlines()
sum = 0
for mem in lines:
    for i in range(len(mem)):
        if mem[i:i+4] == "mul(":
            comma = mem[i:].find(",") + i
            end = mem[i:].find(")") + i
            if comma == -1 or end == -1:
                continue
            num1 = mem[i+4:comma]
            num2 = mem[comma+1:end]
            if num1.isdecimal() and num2.isdecimal() and len(num1) < 4 and len(num2) < 4:
                sum += int(num1) * int(num2)
print(sum)