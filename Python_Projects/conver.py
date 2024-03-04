Type = input("Km/Mi: ")
Distance = float(input("Value: "))
if Type.lower() == "km":
    result = Distance * 0.621371
elif Type.lower() == "mi":
    result = Distance * 1.609344
print(result)