import tkinter as tk
from tkinter import ttk

root = tk.Tk()

root.title("Tk")
root.geometry("500x300")
root.resizable(width = False, height = False)


L1 = ttk.Label(root, text = "Label 1: ", width = 8, font =(None, 12))
L1.grid(row = 0, column = 0, ipady = 16)

E1 = ttk.Entry(root, width = 69)
E1.grid(row = 0, column = 1, ipady = 14)

L2 = ttk.Label(root, text = "Label 2: ", width = 8, font =(None, 12))
L2.grid(row = 1, column = 0, ipady = 16)

E2 = ttk.Entry(root, width = 69)
E2.grid(row = 1, column = 1, ipady = 14)

L3 = ttk.Label(root, text = "Button 1: ", width = 8, font =(None, 12))
L3.grid(row = 2, column = 0, ipady = 16)

def b1():
    E2.delete(0, "end")
    E = E1.get()
    E1.delete(0, "end") 
    E2.insert(0, E)

def b2():
    E1.delete(0, "end")
    E2.delete(0, "end")

L4 = ttk.Label(root, text = "Button 2: ", width = 8, font =(None, 12))
L4.grid(row = 3, column = 0, ipady = 16)

B1 = ttk.Button(root, text = "Delete", width = 30, command = b1)
B1.place(x = "75", y = "112", height = 50) 

B2 = ttk.Button(root, text = "Clear", width = 30, command = b2)
B2.place(x = "75", y = "167", height = 50) 


root.mainloop()