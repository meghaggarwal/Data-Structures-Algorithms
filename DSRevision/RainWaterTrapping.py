def RainWaterTrap(arr): #Wrong Approach
  n = len(arr)
  i = 0
  j = 1
  sumTrap = 0
  count = 0
  totalTrap = 0
  flag = False
  while(j < n): 
    if arr[i] > arr[j]:
      flag = False
      sumTrap += arr[j] 
      count+=1
      j+=1

    else:
      flag = True
      totalTrap = totalTrap + (arr[i] * count) - sumTrap
      print(totalTrap, i, "i")
      sumTrap = 0
      count = 0
      i = j
      j+=1

    if j >= n and flag == False:
      sumTrap = 0
      count = 0
      i += 1
      j = i + 1

  print(totalTrap)

RainWaterTrap( [10,2,3,8] )

def RainWaterTrap(arr): #Right Approach

  n = len(arr)
  left = [0] * n
  right = [0] * n
  left[0] = arr[0]
  right[n-1] = arr[n-1]
  total = 0
  rightmax = 0
  for i in range(1, n):
    left[i] = max(left[i-1], arr[i])

  for i in range(n-2, -1, -1):
    right[i] = max(right[i+1], arr[i])

  for i in range(n-1, -1 , -1):
    total+= ( min(left[i], max(rightmax, arr[i])) - arr[i] ) * 1
    rightmax = max(arr[i], rightmax)

  print(total)

RainWaterTrap( [2,0,2] )