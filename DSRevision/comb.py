def printAllKLength(lis,set, k): 
  
    n = len(set)  
    lis = printAllKLengthRec(lis, set, "", n, k) 
    return lis
  
# The main recursive method 
# to print all possible  
# strings of length k 
def printAllKLengthRec(lis, set, start, n, k): 
      
    # Base case: k is 0, 
    # print prefix 
    if (k == 0) : 
      lis.append(start)
      return
  
    # One by one add all characters  
    # from set and recursively  
    # call for k equals to k-1 
    for i in range(n): 
  
        # Next character of input added 
        newStart = start + set[i] 
          
        # k is decreased, because  
        # we have added a new character 
        printAllKLengthRec(lis, set, newStart, n, k - 1) 


    return lis


lis = printAllKLength([], ['a','b'], 3) 
res = []
output_res = []
for i in range(len(lis)):
  flag = True
  for j in range(2):
    if lis[i][j] == 'a' and lis[i][j] == lis[i][j+1]:
      flag = False

  if flag == True:
    res.append(lis[i])

x = list(filter( lambda x : x[-1] == 'a' , res )) 
output_res.append(len(res))
output_res.append( str(len(x)) + '/' + str(len(res))) 
for x in output_res:
  print(x)



  




