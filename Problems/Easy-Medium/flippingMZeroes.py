

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

        if (end - start > maxWindow) and (zeroCount <= m):
            maxWindow = end - start
            wl = start
            
        
    for i in range(0, maxWindow):
        if x[wl + i] == 0:
            print(wl + i)

    
x = [0, 1, 1, 1, 0, 1, 0, 0, 1, 1]
n = len(x)
flippinZeroes(x, n , 0)

        
