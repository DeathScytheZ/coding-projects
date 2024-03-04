'''
class Student:
    num_of_students = 0
    def __init__(self, name, age, exam_1 = 0, exam_2 = 0, final_exam = 0):
        self.__name = name
        self.__age = age
        self.__exam_1 = exam_1
        self.__exam_2 = exam_2
        self.__final_exam = final_exam
        Student.num_of_students += 1

    def get_name(self):
        return f"Student's name: {self.__name}"

    def get_age(self):
        return f"Student's age: {self.__age}"

    def average(self):
        average = ((self.__exam_1 + self.__exam_2)/2 + self.__final_exam * 2)/3
        return f"Student's average: {average}"

    def get_exams(self):
        return f"First exam: {self.__exam_1} \nSecond exam: {self.__exam_2} \nFinal exam: {self.__final_exam} "

    def no_of_students(self):
        return f"Number of students is: {Student.num_of_students}"


t = Student("T", 18, 14, 18, 15)
'''


list = [10, 15, 48, 63, 15, 9, 10, 14, 45, 77, 14, 598]
print(list[5:])

