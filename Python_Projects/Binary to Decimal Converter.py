import tkinter as tk
from tkinter import ttk

root = tk.Tk()
root.geometry("316x304")
root.resizable(width = False, height = False)
root.title("Binary to Decimal Converter")

History = []

L1 = ttk.Label(root, text = "Binary Number: ", width = 50)
L1.grid(row = 1, column = 1, ipady = 10)

L2 = ttk.Label(root, text = "Decimal Number: ", width = 50)
L2.grid(row = 3, column = 1, ipady = 10)

L3 = ttk.Label(root, text = "", width = 50)
L3.grid(row = 5, column = 1, ipady = 8)

Binary_Number = ttk.Entry(root, width = 51)
Binary_Number.grid(row = 2, column = 1, ipady = 10)

Decimal_Number = ttk.Entry(root, width = 51)
Decimal_Number.grid(row = 4, column = 1, ipady = 10)
def Converter():
    num = Binary_Number.get()
    pos = len(num)-1
    result = 0
    for i in num:
        if i == "1" or i == "0" :
            result += int(i) * (2 ** pos)
            pos -= 1
        else:
            Binary_Number.delete(0, "end")
            Decimal_Number.delete(0, "end")
            
            root_2 = tk.Toplevel(root)
            root_2.geometry("185x100")
            root_2.title("EROOR")
            root_2.resizable(width = False, height = False)  

            def Ok():
                root_2.destroy()

            Error = ttk.Label(root_2, text = "This is not a Binary Number!", width = 30 )
            Error.configure(anchor = "center")
            Error.grid(row = 1, column = 1, ipady = 10) 

            Ok_Button = ttk.Button(root_2, text = "Ok", width = 20, command = Ok)
            Ok_Button.grid(row = 2, column = 1, ipady = 5)

            root_2.mainloop()

    Decimal_Number.delete(0, "end")
    if num != "":
        Decimal_Number.insert(0, result)
        History.append(num + " = " + Decimal_Number.get())

def Reset():
    Binary_Number.delete(0, "end")
    Decimal_Number.delete(0, "end")

def Show_History():
    root_3 = tk.Toplevel(root)
    frame = tk.Frame(root_3)
    frame.pack(expand = True, fill = "both")
    root_3.geometry("208x200")
    root_3.resizable(width = False, height = False)
    root_3.title("History")

    for i in History:
        I = History.index(i)
        L4 = ttk.Label(frame, text = i, width = 25)
        L4.grid(row = I, column = 0)
    
    def Clear():
        try:
            frame.destroy()
            History.clear()
        except:  
            pass     

    Clear = ttk.Button(root_3, text = "Clear", width = 33, command = Clear)
    Clear.place(x = 0, y = 160, height = 40)

    root_3.mainloop()

def Quit():
    root.destroy()

Convert = ttk.Button(root, text = "Convert", width = 51, command = Converter)
Convert.grid(row = 6, column = 1, ipady = 15)

Reset = ttk.Button(root, text = "Reset", width = 16, command = Reset)
Reset.place(x = 0, y = 248.5, height = 55) 

Show_History = ttk.Button(root, text = "History", width = 16, command = Show_History)
Show_History.place(x = 105, y = 248.5, height = 55)

Quit = ttk.Button(root, text = "Quit", width = 16, command = Quit)
Quit.place(x = 210, y = 248.5, height = 55)

root.bind('<Return>', lambda event: Converter())

root.mainloop()