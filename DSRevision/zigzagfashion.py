# Given an array arrange the elements in zig zag fashion

# 4 3 7 8 6 2 5 1
# a[0] < a[1] > a[2] < a[3] > a[4]

# sort, divide it into half and then insert second half in between first half. - O(nlogn)

def zigZagArray(arr):
  n = len(arr) - 1
  for i in range(n):

    if(i%2):

      if arr[i] < arr[i+1]:
        arr[i] , arr[i+1] = arr[i+1], arr[i]

    else:
      if arr[i] > arr[i+1]:
        arr[i] , arr[i+1] = arr[i+1], arr[i]

  print(arr)

zigZagArray([4,3,7,8,6,5,2,1])


a b c
c a b

a + c
b + a
c + b





 