class Employee():
  def __init__(self,name, age):
    self.name = name
    self.age = age

    print("here")


class Student(Employee):
  def __init__(self, name, age, sal):

    # super().__init__(name, age)
    self.name = name
    self.age = age
    self.sal = sal

    print("we")


s = Student("megha", 23, 122)

  
    
    