num = input("enter a nuber: ")
even = 0
odd = 0
for n in num :
    n = int(n)
    if n % 2 == 0 :
        even += 1
    else:
        odd += 1
print("Even: " + str(even))
print("Odd: " + str(odd))
