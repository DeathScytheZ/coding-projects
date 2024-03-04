def Converter():
    Type = input("Km/Mi: ")
    if Type.lower() != "km" and Type.lower() != "mi" and Type.lower() != "quit":
        print("unavailable Type of conversion!")
        Converter()
    elif Type.lower() == "quit":
        quit()
        Converter()
    else:
        distance = input("Value: ")
        if distance == "quit":
            quit()
        else:
            try:
                distance = float(distance)
            except:
                print("unvalide value! ")
                Converter()
    if Type.lower() == "mi":
        result  = distance * 1.609344
        print(result, "km")
        Converter()
    else:
        result = distance * 0.621371
        print(result, "mi")
        Converter()
Converter()