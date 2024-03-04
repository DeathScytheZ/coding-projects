from random import *
import time
def guess():
    print("wolcome to the game")
    time.sleep(1)
    wanna_play = input("do you wannna play? ")
    if wanna_play.lower() == "yes":
        time.sleep(1)
        print("let's play!!")
        time.sleep(1)
        list_of_words = [999,111,777]
        L = len(list_of_words)
        print("the words are: " + str(list_of_words))
        hidden_word = str(list_of_words[randint(0, int(L-1))])
        print(hidden_word)
        guessed_word = str(input("guess a word: "))
        chances = 3
        while guessed_word != hidden_word :
            time.sleep(1)
            chances -= 1
            guessed_word = str(input("try again: "))
            if chances == 1:
                time.sleep(1)
                print("you lost,the hidden word was: "+str(hidden_word))
                time.sleep(1)
                play_agian = input("wanna play again? ")
                if play_agian.lower() == "yes":
                    time.sleep(1)
                    chances = 3
                    hidden_word = str(list_of_words[randint(0, int(L-1))])
                    continue
                else:
                    time.sleep(1)
                    print("see ya later!!")
                    break
        else:
            time.sleep(1)
            print("you won")
        return
    else:
        time.sleep(1)
        print("see ya later!!")
guess()
