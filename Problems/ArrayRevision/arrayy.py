# Given an array replace every element by greater element on the right side (not including the element)
             
# i/p - 16 17 4 3 -10 -3
# o/p - 17 5  5 -3 -3 -1

#Approach 1
def sortGreaterElem(arr):
  s = len(arr) - 1
  temp = arr[s]
  arr[s] = -1
  for i in range(s-1, -1, -1):
    tempno = arr[i]
    arr[i] = max(temp, arr[i+1])
    temp = tempno

  return arr

arr = [16,17,10,3,8,2]
print(sortGreaterElem(arr))


#Approach 2
def sortGreaterElem(arr):
  s = len(arr) - 1
  arr2 = [0] * 6
  arr2[s] = -1
  for i in range(s-1, -1, -1):
    arr2[i] = max(arr2[i+1], arr[i+1])

  return arr2

arr = [16,17,10,3,8,2]
print(sortGreaterElem(arr))



# -1
# 2



def f():
  for i in range(3):
    yield i
