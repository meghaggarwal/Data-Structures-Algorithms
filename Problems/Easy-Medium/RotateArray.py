# Given an array and a no k, rotate the array by k

# i/p - [1,2,3,4,5,6,7]
# k= 3
# o/p - [4,5,6,7,1,2,3]

# Approach- reverse 0 to k -1 - O(n)
#           reverse k to n- 1 - O(N)
#           reverse n - 1 to  0 - O(N)

# TC - O(N), SC - O(1)

def f(x, k):
    length = len(x)
    x[:k] = x[k -1::-1]
    x[k: ] = x[length - 1:k -1 :-1]
    x[:] = x[length -1::-1]
    return x

print(f([1,2,3,4,5,6], 2))


#Non Pythonic 

def f1(x, k):
    length = len(x)
    i , start= 0 , 0
    j, end = length - 1, length -1 
    cur = k -1
    try:
        while(i<cur):
            x[i], x[cur] = x[cur], x[i]
            i+=1
            cur-=1
        while(k<j):
            x[k], x[j] = x[j], x[k]
            k+=1
            j-=1
        while(start<end):
            x[start], x[end] = x[end], x[start]
            start+=1
            end-=1
        return x
    except:
        return 'Invalid value of k!!'
print(f1([1,2,3,4,5,6], 3))
  
    



