class Human:
    def __init__(self,name):
        #self.age = int(age)
        self.name = name

    def welcome(self):
        print("Hello Mr " + self.name)

H = Human('Golk')
H.welcome()

