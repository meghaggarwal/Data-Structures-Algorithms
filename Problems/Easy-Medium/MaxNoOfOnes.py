#Given a sorted 2D array having 0's and 1's. Find the row which has maximum no of 1's

##Approach - O(m+n)
#           1. Take 2 pointers i , j for rows and column no respectively
#           2. Compare  A[i][j] with A[i+1][j], and update j every time if needed.
#           3. Update row with respect to pointer and comparison between the rows, for more clarity see code
def f(x): 
    row = 0
    col = len(x[0]) - 1
    for i in range(1,len(x)):
        if row < i: 
            # if col == -1:
            #     col = 0
            while(col!=-1):
                if x[row][col] > x[i][col]:
                    break
                elif x[row][col] < x[i][col]:
                    row = i
                    break
                else:
                    col -=1
    
    # while(col >= 0):
    #     if x[row][col] == 1:
    #         col-=1
    #         continue
    #     else:
    #         break

    return row
x = [[0,1,1,1], [0,1,1,1]]
print(f(x))
       



