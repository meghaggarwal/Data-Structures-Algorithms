# Given an array replace every element by greater element on the right side.

def GreatestElementOnRight(arr):
  n = len(arr)
  arr1 = [0] * n
  # temp = arr[n-1]
  arr1[n-1] = -1
  for i in range(n-2, -1, -1):
    # curr = arr[i]
    
    if(arr[i+1] > arr1[i+1]):     
      arr1[i] = arr[i+1]

    else:
      arr1[i] = arr1[i+1]

    # temp = curr

  print(arr1)


GreatestElementOnRight([16,17,4,3,5,9])
