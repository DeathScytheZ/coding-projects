from random import *
list = ["Yes", "No"]
T = True
while T:
    def random():
        r = input()
        if r.lower() == "":
            f = choice(list)
            print(f)
        else:
            T = False
            quit()
    random()

