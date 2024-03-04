Num = input()
pos = len(Num) - 1
result = 0
for i in Num:
    if i == "0" or i == "1":
        result += int(i) * (2 ** pos)
        pos -= 1
print(result)