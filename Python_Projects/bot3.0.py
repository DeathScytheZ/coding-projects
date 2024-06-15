import pyautogui
import time

time.sleep(5)
def delete_bot():
    while True:
        msg = pyautogui.locateCenterOnScreen('msg.png')
        pyautogui.moveTo(msg)
        pyautogui.move(102,0)
        pyautogui.click()
        pyautogui.PAUSE = 0.5
        delete = pyautogui.locateCenterOnScreen('delete.png')
        #pyautogui.moveTo(delete)
        pyautogui.click(delete)
        confirm = pyautogui.locateCenterOnScreen('confirm.png')
        #pyautogui.moveTo(confirm)
        pyautogui.click(confirm)

delete_bot()