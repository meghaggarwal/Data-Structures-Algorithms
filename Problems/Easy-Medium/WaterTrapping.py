# def f(x):
#     total = 0
#     length = len(x)
#     i = 0
#     count = 1
#     for j in range(1,length):
#         if x[i] >= x[j]:
#             count+=1
#             total+= (x[i] * count) - x[j]
#         else:
#             total+= x[i] * 1
#             count=1
#             i = j
#     return total

# print(f([1,2,1,1,3,2,1,2,1]))

def f1(x):
    total = 0
    length = len(x)
    i = 0
    for j in range(1,length):
        if x[i] >= x[j]:
            total+= x[i] - x[j]
        else:
            # count=1
            i = j
        print(total)
    return total

print(f1([0,3,0,2,1,4]))

