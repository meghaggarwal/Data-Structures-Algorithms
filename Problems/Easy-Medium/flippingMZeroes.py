# Given a binary array, find the index of zero to be flipped to get max no of consecutive one's where m index can be flipped.

# i/p - 0 1 1 1 0 1 0 1 0 0 1 , m = 2
# o/p - 4 , 6 

# Approach - Window sliding method
#  1. Take start and end pointer.
#  2. Move end untill 2 0's are not encountered.
#  3. Move start pointer to next when end pointer have encountered more than 1 zero.

# TC - O(n) SC - O(1)

def flippinZeroes(x, n, m):
    end = 0
    start = 0
    zeroCount = 0
    maxWindow = 0
    
    while(end < n):
        if zeroCount <= m:
            if x[end] == 0:
                zeroCount+=1
            end+=1

        if zeroCount > m:
            if x[start] == 0:
                zeroCount-=1
            start+=1

        if (end - start -1 > maxWindow) and (zeroCount <= m):
            maxWindow = end - start -1
            wl = start
            
        
    for i in range(0, maxWindow + 1 ):
        if x[wl + i] == 0:
            print(wl + i)

    
x = [0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1]
n = len(x)
flippinZeroes(x, n , 2)

        
