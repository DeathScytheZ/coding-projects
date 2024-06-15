T = input("enter a Temperature: ")
sign = T[-1]
if sign.lower() == "c":
    sign = T[0:-1]
    result = (float(sign)*(9/5))+32
    print(str(result) + " °F")
elif sign.lower() == "f":
    sign = T[0:-1]
    result = ((float(sign)-32)*(5/9))
    print(str(result) + " °c")
