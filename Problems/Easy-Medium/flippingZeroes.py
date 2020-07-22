# Given a binary array, find the index of zero to be flipped to get max no of consecutive one's

# i/p - 0 1 1 1 0 1 0 1 0 0 1
# o/p - 4

# Approach - Window sliding method
#  1. Take start and end pointer.
#  2. Move end untill 2 0's are not encountered.
#  3. Move start pointer to next when end pointer have encountered more than 1 zero.

# TC - O(n) SC - O(1)

def flippingZeroes(x, n):
    start = 0
    end = 0
    countZero = 0
    #zeroIndex = 0
    res = 0
    wL = 0
    maxWindow = 0
    while(end < n):
        if countZero < 2:
            if x[end] == 0:
                #zeroIndex = end
                countZero+=1

            end+=1
        if countZero > 1: 
            if x[start] == 0:
                countZero-=1
            start+=1
        if( (end - start > maxWindow)  and (countZero <= 1)):
            
            maxWindow = end - start
            wL = start
            print(wL, maxWindow, end)
            #res = zeroIndex
            
    for i in range(0, maxWindow):
        if x[wL + i ] == 0:
            print(wL + i)
    
               
x = [1, 0, 0, 1, 1, 0, 1, 0, 1, 1]
n = len(x)
flippingZeroes(x, n)



