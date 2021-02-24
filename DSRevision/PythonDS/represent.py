# class Employee:

#   def __init__(self):
#     self.name = "Megha"
#     self.age = 23

#   def __str__(self):
#     return f"Age is {self.age} and name is {self.name}!!! "

#   def __repr__(self):
#     return f"Age is {self.age} and name is {self.name} "


# e = Employee()
# print(e)


class Person:

    def __init__(self, person_name, person_age):
        self.name = person_name
        self.age = person_age

    # def __str__(self):
    #     return f'Person name is {self.name} and age is {self.age}'

    def __repr__(self):
        return f'Person(name={self.name}, age={self.age})'


p = Person('Pankaj', 34)

print(p)
print(p.__repr__())