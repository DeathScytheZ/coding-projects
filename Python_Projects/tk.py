'''
from tkinter import *

root = Tk()
root.geometry("250x250")


def h():
    quit()


def g():

    root1 = Tk()
    root1.geometry("200x150")

    b2 = Button(root1, text = "Tk2", width = 27, height = 3, borderwidth = 3, command = h)
    b2.grid(row = 1, column = 1)

    root1.mainloop()







b1 = Button(root, width = 34, borderwidth = 3, height = 5, text = "Tk", command = g)
b1.grid(row = 1, column = 1)



root.mainloop()

'''

import pyautogui
import time


def spam_bot(msg_count):
    msg = str(input_box.get())
    time.sleep(5)
    type_box = pyautogui.locateCenterOnScreen("type_box.png")
    for i in range(0,int(msg_count)):
        pyautogui.moveTo(type_box)
        pyautogui.click()
        pyautogui.typewrite(msg)
        send = pyautogui.locateCenterOnScreen("send.png")
        pyautogui.moveTo(send)
        pyautogui.click()
