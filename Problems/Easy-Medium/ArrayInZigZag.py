# Given an array rearrange the elements in zig zag order

# I/p - [4,3, 7, 8, 6, 2, 1]
# O/p - [3, 7, 4, 8, 2, 6, 1]

# Approach - Swap alternatively for > and < comparison

# TC - O(N) - SC- O(1)

def f(x):
    flag = True
    for idx in range(len(x) - 1):
        if flag:
            if x[idx] > x[idx + 1]:
                x[idx] , x[idx + 1] = x[idx + 1], x[idx]
    
        else:
            if x[idx] < x[idx + 1]:
                x[idx] , x[idx + 1] = x[idx + 1], x[idx]
           
        flag = bool(1- flag)
    return x

print(f([4,3,7, 8,6,2,1]))