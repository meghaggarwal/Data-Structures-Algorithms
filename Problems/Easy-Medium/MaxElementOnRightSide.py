#Given an array, replace every element by greater element on right side.

#Approach - 1. Start from right side, take a temp variable, 
#           2. Replace the current element A[i] with maximum of A[i+1], temp
#           3. Update temp with current element
#           4. Repeat the steps for all the elements

def f(x):
    length = len(x)
    temp = x[length - 1]
    x[length - 1] = -1 
    for i in range(length - 2, -1, -1 ):
        if temp > x[i + 1]:
            temp , x[i ] = x[i], temp
        else:
            temp = x[i]
            x[i ] = x[i + 1]
    
    print(x)

# def f1(x):
#     length = len(x)
#     val =  x[length - 1]
#     x[length - 1] = -1
#     for i in range(length - 2 , -1, -1):
#         temp = x[i]
#         x[i] = max(x[i + 1], val)
#         val = temp
#     print(x)
        

x = [16,17,4,3,5,2]
f (x)