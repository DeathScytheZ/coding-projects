from tkinter import *
from math import *

root = Tk()

root.geometry("314x360")

root.title("Calculator")

root.resizable(width = False, height = False)


screen = Entry(root,width = 14, borderwidth = 3, bg = "#21221B", fg = "#008A30")
screen.configure(font=("Digital-7", 35, "italic"))
screen.grid(row = 1, column = 1, ipady = 5, columnspan = 5)


#the number's buttons
def button_Number(num):
    current = screen.get()
    screen.delete(0,END)
    screen.insert(0,str(current) + str(num))
    global z
    z = True


#the division button
def button_divide():
    global first_number
    first_number = float(screen.get())
    screen.delete(0, END)
    global operation
    operation = "division"


#the multiplicaion button
def button_multiply():
    global first_number
    first_number = float(screen.get())
    screen.delete(0, END)
    global operation
    operation = "multiplication"


#the subtracion button
def button_subtract():
    if screen.get() == "":
        screen.insert(0,"-")
    elif screen.get() == "|":
        screen.insert(1,"-")
    else:
        global first_number
        first_number = float(screen.get())
        screen.delete(0, END)
        global operation
        operation = "subtraction"


#the addition button
def button_Add():
    global first_number
    first_number = float(screen.get())
    screen.delete(0, END)
    global operation
    operation = "addition"


#the delete button
def button_Delete():
    if z == True:
        k = len(screen.get()) - 1
        screen.delete(k)


#the clear button
def button_Clear():
    screen.delete(0,END)
    global z
    z = True


#the Ans button
def button_Ans():
    screen.delete(0,END)
    screen.insert(0,Ans)
    global z
    z = False


#the squeared button
def button_squeared():
    global operation
    operation = "squared"
    global number
    number = float(screen.get())
    l = len(screen.get())
    screen.insert(l,"²")
    global z
    z = True


#the squear root button
def button_squear_root():
    screen.insert(0,"√")
    global operation
    operation = "squear root"
    global z
    z = True


def button_pos_neg():
    reversed = float(screen.get()) * (-1)
    screen.delete(0,END)
    screen.insert(0,reversed)
    global z
    z = True


def button_Absolute():
    if screen.get() == "":
        screen.insert(0,"|")
    elif screen.get()[0] == "|":
        global l
        l = len(screen.get())
        screen.insert(l,"|")
    global operation
    operation = "Absolute Value"
    global z
    z = True

def button_Pi():
    screen.delete(0,END)
    screen.insert(0,pi)
    global z
    z = False


def button_e():
    screen.delete(0,END)
    screen.insert(0,exp(1))
    global z
    z = False


def button_ln():
    screen.insert(0,"ln")
    global operation
    operation = "natural logarithm"


def button_log():
    screen.insert(0,"log")
    global operation
    operation = "logarithm"


def button_factorial():
    l = len(screen.get())
    screen.insert(l,"!")
    global operation
    operation = "factorial"


def button_power():
    global first_number
    first_number = float(screen.get())
    screen.delete(0,END)
    global operation
    operation = "power"


def button_cos():
    screen.insert(0,"cos")
    global operation
    operation = "cos"


def button_sin():
    screen.insert(0,"sin")
    global operation
    operation = "sin"


def button_tan():
    screen.insert(0,"tan")
    global operation
    operation = "tan"


def button_reciprocal():
    result = 1 / float(screen.get())
    screen.delete(0,END)
    screen.insert(0,result)



#the equal button
def button_Equal():
    if operation == "addition":
        second_number = float(screen.get())
        screen.delete(0, END)
        result = first_number + second_number
        screen.insert(0,result)
    elif operation == "subtraction":
        second_number = float(screen.get())
        screen.delete(0, END)
        result = first_number - second_number
        screen.insert(0,result)
    elif operation == "division":
        second_number = float(screen.get())
        screen.delete(0, END)
        result = first_number / second_number
        screen.insert(0,result)
    elif operation == "multiplication":
        second_number = float(screen.get())
        screen.delete(0, END)
        result = first_number * second_number
        screen.insert(0,result)
    elif operation == "squared":
        result = number ** 2
        screen.delete(0,END)
        screen.insert(0,result)
    elif operation == "squear root":
        s = screen.get()
        s = s.replace("√","")
        s = sqrt(float(s))
        screen.delete(0,END)
        screen.insert(0,s)
    elif operation == "Absolute Value":
        num = screen.get()[1:l]
        result = abs(float(num))
        screen.delete(0,END)
        screen.insert(0,result)
    elif operation == "natural logarithm":
        num = screen.get().replace("ln","")
        result = log(float(num),exp(1))
        screen.delete(0,END)
        screen.insert(0,result)
    elif operation == "logarithm":
        num = screen.get().replace("log","")
        result = log((float(num)),10)
        screen.delete(0,END)
        screen.insert(0,result)
    elif operation == "factorial":
        num = screen.get().replace("!","")
        result = factorial(float(num))
        screen.delete(0,END)
        screen.insert(0,result)
    elif operation == "power":
        second_number = float(screen.get())
        result = pow(first_number,second_number)
        screen.delete(0,END)
        screen.insert(0,result)
    elif operation == "cos":
        num = screen.get().replace("cos","")
        result = cos(float(num))
        screen.delete(0,END)
        screen.insert(0,result)
    elif operation == "sin":
        num = screen.get().replace("sin","")
        result = sin(float(num))
        screen.delete(0,END)
        screen.insert(0,result)
    elif operation == "tan":
        num = screen.get().replace("tan","")
        result = tan(float(num))
        screen.delete(0,END)
        screen.insert(0,result)
    global Ans
    Ans = screen.get()
    global z
    z = False



#the number's buttons
b1 = Button(root,text = "1",padx = 22, pady = 9, bg = "#1C2633", fg = "#FFFFFF", command = lambda : button_Number(1))
b2 = Button(root,text = "2",padx = 22, pady = 9, bg = "#1C2633", fg = "#FFFFFF", command = lambda : button_Number(2))
b3 = Button(root,text = "3",padx = 22, pady = 9, bg =  "#1C2633", fg = "#FFFFFF", command = lambda : button_Number(3))
b4 = Button(root,text = "4",padx = 22, pady = 9, bg =  "#1C2633", fg = "#FFFFFF", command = lambda : button_Number(4))
b5 = Button(root,text = "5",padx = 22, pady = 9, bg =  "#1C2633", fg = "#FFFFFF", command = lambda : button_Number(5))
b6 = Button(root,text = "6",padx = 22, pady = 9, bg =  "#1C2633", fg = "#FFFFFF", command = lambda : button_Number(6))
b7 = Button(root,text = "7",padx = 22, pady = 9, bg =  "#1C2633", fg = "#FFFFFF", command = lambda : button_Number(7))
b8 = Button(root,text = "8",padx = 22, pady = 9, bg =  "#1C2633", fg = "#FFFFFF", command = lambda : button_Number(8))
b9 = Button(root,text = "9",padx = 22, pady = 9, bg =  "#1C2633", fg = "#FFFFFF", command = lambda : button_Number(9))
b0 = Button(root,text = "0",padx = 22, pady = 9, bg =  "#1C2633", fg = "#FFFFFF", command = lambda : button_Number(0))
b_dot = Button(root,text = ".", padx = 23, pady = 9, bg =  "#1C2633", fg = "#FFFFFF", command = lambda : button_Number("."))
b_divide = Button(root,text = "/",padx = 23, pady = 9, bg =  "#000000", fg = "#FFFFFF", command = button_divide)
b_multiply = Button(root,text = "×",padx = 22, pady = 9, bg =  "#000000", fg = "#FFFFFF", command = button_multiply)
b_subtract = Button(root,text = "-",padx = 23, pady = 9, bg =  "#000000", fg = "#FFFFFF", command = button_subtract)
b_add = Button(root,text = "+",padx = 21, pady = 9, bg =  "#000000", fg = "#FFFFFF", command = button_Add)
b_delete = Button(root,text = "⌫",padx = 18, pady = 9, bg =  "#000000", fg = "#FFFFFF", command = button_Delete)
b_clear = Button(root,text = "C", padx = 21, pady = 9, bg =  "#000000", fg = "#FFFFFF", command = button_Clear)
b_equal = Button(root,text = "=", padx = 55, pady = 9, bg =  "#951A12", fg = "#FFFFFF", command = button_Equal)
b_squeared = Button(root,text = "x²", padx = 18, pady = 9, bg =  "#000000", fg = "#FFFFFF", command = button_squeared)
b_Ans = Button(root,text = "Ans", padx = 15, pady = 9, bg = "#000000", fg = "#FFFFFF", command = button_Ans)
b_squear_root = Button(root,text = "√", padx = 18, pady = 9, bg = "#000000", fg = "#FFFFFF", command = button_squear_root)
b_pos_neg = Button(root,text = "+/-", padx = 16, pady = 9, bg = "#1C2633", fg = "#FFFFFF", command = button_pos_neg)
b_Abs = Button(root,text = "|x|", padx = 21, pady = 9, bg = "#000000", fg = "#FFFFFF", command = button_Absolute)
b_Pi = Button(root,text = "π", padx = 18, pady = 9, bg = "#000000", fg = "#FFFFFF", command = button_Pi)
b_e = Button(root,text = "e", padx = 23, pady = 9, bg = "#000000", fg = "#FFFFFF", command = button_e)
b_ln = Button(root,text = "ln", padx = 23, pady = 9, bg = "#000000", fg = "#FFFFFF", command = button_ln)
b_log = Button(root,text = "log", padx = 18, pady = 9, bg = "#000000", fg = "#FFFFFF", command = button_log)
b_factorial = Button(root,text = "n!", padx = 18, pady = 9,  bg = "#000000", fg = "#FFFFFF", command = button_factorial)
b_power = Button(root,text = "^", padx = 18, pady = 9, bg = "#000000", fg = "#FFFFFF", command = button_power)
b_cos = Button(root,text = "cos", padx = 18, pady = 9, bg = "#000000", fg = "#FFFFFF", command = button_cos)
b_sin = Button(root,text = "sin", padx = 18, pady = 9, bg = "#000000", fg = "#FFFFFF", command = button_sin)
b_tan = Button(root,text = "tan", padx = 18, pady = 9, bg = "#000000", fg = "#FFFFFF", command = button_tan)
b_reciprocal = Button(root,text = "1/x", padx = 18, pady = 9, bg = "#000000", fg = "#FFFFFF", command = button_reciprocal)



#placing the buttons
b_Ans.grid(row = 2, column = 3,sticky = "nsew")
b_clear.grid(row = 2, column = 4,sticky = "nsew")
b_delete.grid(row = 2, column = 5,sticky = "nsew")
b7.grid(row = 3, column = 3,sticky = "nsew")
b8.grid(row = 3, column = 4,sticky = "nsew")
b9.grid(row = 3, column = 5,sticky = "nsew")
b4.grid(row = 4, column = 3,sticky = "nsew")
b5.grid(row = 4, column = 4,sticky = "nsew")
b6.grid(row = 4, column = 5,sticky = "nsew")
b1.grid(row = 5, column = 3,sticky = "nsew")
b2.grid(row = 5, column = 4,sticky = "nsew")
b3.grid(row = 5, column = 5,sticky = "nsew")
b_e.grid(row = 5, column = 2,sticky = "nsew")
b_pos_neg.grid(row = 6, column = 3,sticky = "nsew")
b0.grid(row = 6, column = 4,sticky = "nsew")
b_dot.grid(row = 6, column = 5,sticky = "nsew")
b_Pi.grid(row = 5, column = 1,sticky = "nsew")
b_Abs.grid(row = 7, column = 2,sticky = "nsew")
b_subtract.grid(row = 7, column = 3,sticky = "nsew")
b_multiply.grid(row = 7, column = 4,sticky = "nsew")
b_divide.grid(row = 7, column = 5,sticky = "nsew")
b_squear_root.grid(row = 8, column = 1,sticky = "nsew")
b_squeared.grid(row = 8,column = 2,sticky = "nsew")
b_equal.grid(row = 8, column = 4, columnspan = 2,sticky = "nsew")
b_add.grid(row = 8, column = 3,sticky = "nsew")
b_ln.grid(row = 6, column = 1,sticky = "nsew")
b_log.grid(row = 6, column = 2,sticky = "nsew")
b_factorial.grid(row = 7, column = 1, sticky = "nsew")
b_power.grid(row = 6,column = 1, sticky = "nsew")
b_cos.grid(row = 3, column = 2, sticky = "nsew")
b_sin.grid(row = 3, column = 1, sticky = "nsew")
b_tan.grid(row = 2, column = 2, sticky = "nsew")
b_reciprocal.grid(row = 4, column = 2, sticky = "nsew")


root.mainloop()