import random
import time

list = [6,8,10]
def Dice():
    print("available dices: " + str(list)[1:-1])
    dice = int(input("Pick a dice: "))
    if list.count(dice) >= 1:
            while True:
                time.sleep(0.5)
                num = random.randint(1,dice)
                print(num)
                time.sleep(0.5)
                roll_again = input("Would you like to roll the dice again? ")
                if roll_again.lower() == "yes":
                    continue
                else:
                    time.sleep(0.5)
                    quit()
    else:
        time.sleep(0.5)
        print("Sorry,this dice is not available")
        return  Dice()
Dice()