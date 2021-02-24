class Queue:
  def __init__(self, n=10):
    self.__n = n
    self.__buffer  = [0]*n
    self.__current_elements = 0
    self.__reset()

  def __reset(self):
    self.__start = 0
    self.__end = -1

  def enqueue(self, data):
    if self.__current_elements == self.__n:
      raise Exception("QUeue is full")

    self.__current_elements += 1
    self.__end = (self.__end + 1) % self.__n
    self.__buffer[self.__end] = data

  def dequeue(self):
    if self.__current_elements == 0:
      raise Exception("QUeue is empty")

    res  = self.__buffer[self.__start]
    self.__start = (self.__start  + 1) %self.__n
    self.__current_elements -= 1

    if self.__current_elements == 0:
      self.__reset()
    return res

  def __str__(self):
      return f"{self.__start} : {self.__end} : {self.__buffer}"

if __name__ == "__main__":
    q = Queue(5)
  
    for i in range(1,6):
        q.enqueue(i)
        print(q)

    for i in range(5):
        print(q.dequeue())
        print(q)

    for i in range(6,10):
        q.enqueue(i)
        print(q)