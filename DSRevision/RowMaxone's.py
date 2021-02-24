# Given a sorted two d arrays have o's and 1's. Find the row no which have max no of 1s
def RowMaxNoofOnes(arr):

  n = len(arr)
  col  = len(arr[n-1]) - 1
  row_num = -1
  for i in range(n):
    flag = False
    col_num = 0
    for j in range(col , -1, -1):
      if arr[i][j] == 1:
        col_num+=1
        row_num = i
        flag = True
      
      if arr[i][j] == 0:
        flag = False

      if flag == False:
        col = col - col_num 
        break

    if j == 0 and flag == True:
      break
       
  print(row_num)



# Using while loop

def RowMaxNoofOnes(arr):
  n = len(arr)
  row_num = -1
  col = len(arr[n-1]) - 1
  j = col
  for i in range(n):
    while(arr[i][j] == 1 and j>=0):
      j-=1
      row_num = i

  print(row_num)


      
RowMaxNoofOnes([ [0,1,1], [0,1,1], [1,1,1] ])