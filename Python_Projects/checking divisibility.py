num_1 = int(input("enter the first number: "))
num_2 = int(input("enter the second number: "))
divisibility = num_1 % num_2
if divisibility == 0 :
       print("the two numbers are divisible")
       result = num_1 / num_2
       print("the result is: " + str(result))
else:
    result = num_1 % num_2
    reminder = num_1 // num_2
    print("the two numbers are not divisible,the result is: " + str(result) + " ,the reminder is: " + str(reminder))
