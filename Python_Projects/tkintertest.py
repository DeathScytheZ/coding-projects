from tkinter import *

root = Tk()
root.geometry("400x300")
frame = Frame(root)
frame.pack(side = "top", expand = True, fill = "both")
Label(frame, text = "Label").pack(pady = 50)
def clear():
        frame.destroy()
Button(root, text = "kill", command = clear).pack(pady = 50)


root.mainloop()