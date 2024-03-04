from tkinter import *

root = Tk()



B1 = Button(root, text = "B1: ", width = 20, height = 3, borderwidth = 1, relief = "groove", bg = "#000000", fg = "#ffffff")
B1.grid(row = 1, column = 1, sticky = "nswe")

B2 = Button(root, text = "B2", width = 20, height = 3, borderwidth = 1, relief = "groove")
B2.grid(row = 1, column = 2, sticky = "nswe")

B3 = Button(root, text = "B3", width = 20, height = 3, borderwidth = 1, relief = "groove")
B3.grid(row = 1, column = 3, sticky = "nswe")

B4 = Button(root, text = "B4", width = 44, height = 3, borderwidth = 1, relief = "groove")
B4.grid(row = 2, column = 1, columnspan = 2)

B5 = Button(root, text = "B5", width = 20, height = 3, borderwidth = 1, relief = "groove")
B5.grid(row = 2, column = 3)



root.mainloop()