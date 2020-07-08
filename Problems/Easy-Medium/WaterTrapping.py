# Given n non-negative integers representing an elevation map where the width of each bar is 1, 
# compute how much water it is able to trap after raining.

# Approach - Count the individual water trapped in the bar

# Method 1 - Tc - O(N), S(c) - o(1)
def f(x):
    total = 0
    length = len(x)
    for j in range(0,length):
        lmax = x[j]
        rmax = x[j]
        for i in range(j+1):
            lmax = max(lmax, x[i])
        for i in range(j, length):
            rmax = max(rmax, x[i])

        total += min(lmax, rmax) - x[j]
    return total

print(f( [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))

# Method 2 ( Using left array and right array )
# TC - O(n), S(c) - O(2n)

def f1(x):
    length = len(x)
    l = [0] * length
    r = [0] * length
    r[length - 1] = x[length - 1]
    total = 0
    
    for i in range(1, length ):
        l[i] = max(x[i], l[i-1])

    for i in range(length - 2, -1, -1):
        r[i] = max(x[i], r[i+1])

    for i in range(length - 2, 0, -1):
        
        total+= min(l[i], r[i]) - x[i]

    return total

print(f1( [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))


# Method 3 (Using envelope method, most efficient)
# TC - O(n), SC - O(1)

def f2(x):
    length = len(x)
    lmax = x[0]
    rmax = x[length - 1]
    i = 0
    j = length - 1
    total = 0
    while(i <= j):
        lmax = max(lmax , x[i])
        rmax = max(rmax, x[j])
        if lmax <= rmax:
            total+= lmax - x[i]
            i+=1
        else:
            total+= rmax - x[j]
            j -=1
    return total
    

print(f2( [3,0,2,0,4]))

