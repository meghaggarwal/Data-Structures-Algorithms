# Given a binary array, find max no of consecutive 1's if only a single 0 is allowed to be flipped.

# 0 0 1 1 1 1 0 0 1 1


# Complexity - Every element is coming inside the window and gettting out so total 2 times processed maximum

# So TC - O(n)

# Approach 2 - Store indexes in the array...calculate the array size using the array.

def consecutiveOnes(arr):
  max_1s = -1
  max_zero = 0
  idx = -1
  max_one = 0
  j = 0
  n = len(arr)
  for i in range(n):

    if arr[i - 1] == 0 and i > 0:
      max_zero-=1

    if arr[i - 1] == 1 and i > 0:
      max_one-=1

    while(max_zero <= 1 and j < n ):
    
      if arr[j] == 0:
        max_zero+=1
        j+=1
        continue

      max_one+=1
      j+=1

    if max_one + 1 > max_1s:
      max_1s = max_one + 1
      idx = i

  print(idx, max_1s)
  
consecutiveOnes( [1,0,1,1,0,1,1,1,0,1,0,1] )


def consecutiveOnes(arr):
  end = 0
  n = len(arr)
  start = 0
  zeroCount = 0
  maxWindow = -1
  startwl = 0
  while(end < n):
    if( zeroCount < 2):
      if(arr[end] == 0):
        zeroCount+=1

      end+=1

    if(zeroCount > 1):
      if(arr[start] == 0):
        zeroCount-=1

      start+=1

    if( (end - start - 1 > maxWindow) and (zeroCount<=1)):
      maxWindow = end - start - 1
      startwl = start
      print('startwl', startwl, maxWindow)

  for i in range(startwl, startwl + maxWindow + 1):
    print(arr[i])


consecutiveOnes( [ 1,0,1,1,0,1,1,1,0,1,0,1] )







                


    

    


  

  