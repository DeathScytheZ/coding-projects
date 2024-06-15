from math import *
import cmath
def Quadratic_Equation(a,b,c):
    # d : Δ
    d = int((b**2)-(4*a*c))
    print("Δ = " + str(d))
    if d > 0 :
        print("there are two real solutions: ")
        solution_1 = (-b+cmath.sqrt(d))/(2*a)
        print(solution_1)
        solution_2 = (-b-cmath.sqrt(d))/(2*a)
        print(solution_2)
    elif d == 0 :
        print("there is one real solution: ")
        solution_0 = (-b)/(2*a)
        print(solution_0)
    else :
        # no_solution : imaginary solution
        no_solution_1 = (-b+cmath.sqrt(d))/(2*a)
        no_solution_2 = (-b-cmath.sqrt(d))/(2*a)
        print("there are no real solutions, imaginary solutions are: ")
        print(no_solution_1)
        print(no_solution_2)
    return

a = int(input("enter a: "))
b = int(input("enetr b: "))
c = int(input("enter c: "))

Quadratic_Equation(a,b,c)
