def findAllComb(lis, set, k):
    n = len(set)
    lis = findAllCombLength(lis, set, "", n , k)
    return lis

def findAllCombLength(lis, set, start, n, k):

    if k == 0:
        lis.append(start)
        return

    for i in range(n):
        newStart = start + set[i]
        findAllCombLength(lis, set, newStart, n, k -1)

    return lis


def Solve (N):
    # Write your code here
    lis = findAllComb([], ['a','b'], N)
    print(lis)
    len_lis = len(lis)
    attend_class = []
    output_res = []
    for i in range(len_lis):
        flag = True
        for j in range(N - 1):
            if lis[i][j] == 'a' and lis[i][j] == lis[i][j +1]:
                flag = False

        if flag == True:
            attend_class.append(lis[i])


    grad_cermony_miss = list( filter ( lambda x: x[-1] == 'a' , attend_class))
    output_res.append(len(attend_class))
    output_res.append( str(len(grad_cermony_miss)) + '/' + str(len(attend_class)))
    return output_res

    # Dummy return
    

N = int(input())

out_ = Solve(N)
for i_out_ in out_:
    print (i_out_)