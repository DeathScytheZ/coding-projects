def guessing_game():
    wanna_play = str(input("welcome to my game whould you like to play? (yes,no):"))
    if wanna_play.upper() == "NO":
        wanna_play = False
        print("alright see ya later!")
    elif wanna_play.upper() == "YES":
        wanna_play = True
        print("cool let's play!")
        X = int(input("enter the start of the range: "))
        Y = int(input("enter the end of the range: "))
        from random import randint
        num = randint(X,Y)
        can_guess = True
        attempts = 1
        while wanna_play and can_guess:
            guessed_num = int(input("guess a number: "))
            if guessed_num == num :
                print("you won!! it took you "+ str(attempts) + " attempts")
                can_guess = False
                play_again = str(input("do you wanna play again? (yes,no) :"))
                if play_again.upper() == "YES" :
                    can_guess = True
                    print("cool let's play again!!")
                    X = int(input("enter the start of the range: "))
                    Y = int(input("enter the end of the range: "))
                    num = randint(X,Y)
                elif play_again.upper() == "NO":
                    print("alright see ya next time!!")
            elif guessed_num < X :
                print("please enter a number from the given range!")
            elif guessed_num > Y :
                print("please enter a number from the given range!")
            elif guessed_num < num and  guessed_num >= X and attempts < 3:
                print("it's higher!! try again: ")
                attempts += 1
            elif guessed_num > num and  guessed_num <= Y and attempts > 3:
                print("it's lower!! try again: ")
                attempts += 1
            else:
                can_guess = False
                print("you lost !!")
                play_again1 = str(input("do you wanna play again? (yes,no): "))
                if play_again1.upper() == "YES":
                    can_guess = True
                    attempts = 1
                    print("let's play!!")
                    X = int(input("enter the start of the range: "))
                    Y = int(input("enter the end of the range: "))
                    num = randint(X, Y)
                elif play_again1.upper() == "NO":
                    can_guess = False
                    print("see ya later!!")
    else:
        print("please enter a valid answer(yes or no): ")

guessing_game()
