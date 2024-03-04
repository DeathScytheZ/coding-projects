'''
def calc(num1, num2):
    product = num1 * num2
    sum = num1 + num2
    if product >= 1000:
        return product 
    else:
        return sum
num1 = int(input("number1: "))
num2 = int(input("number2: "))
print(calc(num1, num2))
'''




'''
def Sum():
    previous_num = 0 
    current_num = 0
    print("Printing current and previous number sum in a range(10)")
    for i in range(10):
        sum = current_num + previous_num    
        print("Current number " + str(current_num) + " previous number " + str(previous_num) + " sum " + str(sum))
        current_num += 1
        previous_num = current_num - 1  
Sum()   
'''


'''
def even():
    string = str(input("enter a string: "))
    print("original string: " , string)
    print("printing only even index chars")
    for i in string:
        if string.index(i) % 2 == 0:
            print("index[" , string.index(i) , "]", i)
even()
'''




'''
def Remove():
    for i in range(n):
        string.pop(0)
    print("".join(string))
string = str(input("enter a string: "))    
string = list(string)
n = int(input("enter n: ")) 
Remove()
'''



'''
def First_Last():
    L1 = input("enter the elments of the list separated by space: ")
    L1 = L1.split()
    if L1[0] == L1[-1]:
        print("True")
    else:
        print("False")
First_Last()
'''



'''
L = input()
L = L.split()
L = list(map(int, L))

def Divisibal_by_5():
    for i in L:
        if i % 5 == 0:
            print(i)
Divisibal_by_5()
'''


'''
Substring = str(input("enter substring: "))
String =  str(input("enter string: "))
String = String.split()
count = 0
for i in String:
    if i == Substring:
        count += 1
print(count)
'''


#for i in range(6):
    #for f in range(i):
        #print(i, end = " ")
    #print("\n")



