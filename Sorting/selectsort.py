
def compare(f1, f2):
  return f1[0] * f2[1] > f1[1] * f2[0]


def select_sort(arr, arr1):
  idx = 0
  for i in range(len(arr) - 1):
    min = ( arr[i], arr1[i])
    for j in range(i+1, len(arr)):
      if(  compare( min , (arr[j], arr1[j] ) ) ):
        arr[i] , arr[j] = arr[j], arr[i]
        arr1[i] , arr1[j] = arr1[j], arr1[i]
        min = ( arr[i], arr1[i] )
        

  print(arr)
  print(arr1)

arr = [2,3,1]
arr1 = [5,6,4]

select_sort(arr, arr1)
