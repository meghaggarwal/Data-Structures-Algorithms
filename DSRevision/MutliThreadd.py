import threading
import os
import time

def increment1(num):
  for i in range(num):
    i+=1
    time.sleep(2)
    print(i)

def main_task():
 
  t1 = threading.Thread(target=increment1, args=(10,))
  t2 = threading.Thread(target=increment1, args=(10,))

  t1.start()
  t2.start()

  t1.join()
  t2.join()


if __name__ == '__main__':
  for i in range(10):
    main_task()
    

