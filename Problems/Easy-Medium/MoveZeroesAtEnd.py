#Given an array move all zeroes to end

#Approach - 1.Take two pointer, 1 curr element pointer, other to replace the current  element with lastnonzero element
#           2. current pointer - increment everytime
#           3. second pointer - moves forward only if current element is non zero

# def f(x):
#     i = 0
#     j = 0
#     while(j < len(x)):
#         if x[j] != 0:
#             x[i], x[j] = x[j], x[i]
#             i+=1
#         j+=1
#     return x


# x = [1,2,3,0,0,4,5]
# print(f(x))
def swap(a, b):
    temp = a
    a = b
    b = temp
    return (a , b)

def f(x):
    lastNonZero = 0
    for curr in x:
        if curr != 0:          
            x[lastNonZero] , curr = swap(x[lastNonZero],curr)
            lastNonZero+=1
        curr+=1
    return x


x = [0,1,0,0,4,5,6,0,0]
print(f(x))

