# Given an array of size n, find the majority element which is more than n/2.and

# i/p - 3 3 4 4 1 2 3 5 4 4
# o/p - 4


# Approach - Moore's algorithm
# Cancel out the majority element with every other unique element. The element which occurs maximum time will cancel out other non repetitive elements. Then check if the element is major ( occur more than n/2)

def findCandidate(x, n):
  cur = x[0]
  count_cur = 1
  for i in range(0, n):
    if x[i] == cur and count_cur > 0:
      count_cur +=1
      if count_cur == 0:
        cur = x[i]
        count_cur = 1
    elif x[i] != cur and count_cur > 0:
      count_cur -=1
      if count_cur == 0:
          cur = x[i]
          count_cur = 1
    else:  
      return -1
  return cur

def findMajority(cand, x, n): #if selected candidate occurs more than n/2
  count = 0
  for i in range(n):
    if x[i] == cand:
      count+=1
  if count > n/2:
    return True
  else:
    return False

x = [3,4,1,4,4,4,4,1,2,2,4]
n = len(x)
cand = findCandidate(x, n)
if findMajority(cand, x, n) == True:
  print(cand)
else:
  print('No majority element found')
